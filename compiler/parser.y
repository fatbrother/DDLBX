%{
#include <string>
#include <iostream>
#include <vector>
#include "ir/node.hpp"

#define YYERROR_VERBOSE 1

void yyerror(const char *s);
void parseText(const char* text);
extern int yylex();

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yyparse();
extern YY_BUFFER_STATE yy_scan_string(const char * str);
extern YY_BUFFER_STATE yy_switch_to_buffer(YY_BUFFER_STATE buffer);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

extern int yylineno;
extern int yycolumn;
extern char* yytext;
ddlbx::ir::NProgram* program;

%}

%union {
    ddlbx::ir::NProgram *program;
    ddlbx::ir::NType *type;
    ddlbx::ir::NBlock *block;
    ddlbx::ir::NExpression *expr;
    ddlbx::ir::NStatement *stmt;
    ddlbx::ir::NIdentifier *identifier;
    std::vector<std::shared_ptr<ddlbx::ir::NStatement>> *stmtvec;
    std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varvec;
    std::vector<std::shared_ptr<ddlbx::ir::NArgument>> *argvec;
    std::vector<std::shared_ptr<ddlbx::ir::NExpression>> *exprvec;
    std::string *string;
    int token;
}

%token <string> NUMBER FRAC_NUMBER IDENTIFIER STRING BOOL
%token <string> KW_NONE KW_INT KW_FLOAT KW_BOOL KW_STRING 
%token <token>  KW_RETURN KW_FUNCTION KW_VAR KW_OPT KW_FOR

%token <token> COM_EQ COM_NE COM_LE COM_GE COM_LT COM_GT
%token <token> OP_ASSIGN OP_PLUS OP_MINUS OP_MULT OP_DIV
%token <token> LPAREN RPAREN LBRACE RBRACE
%token <token> SEMICOLON COMMA COLON DOT

%type <program> Program
%type <stmtvec> GlobalStatements
%type <block> Block Statements
%type <stmt> Statement GlobalStatement FunctionDeclaration FunctionDefinition OptStatement ForStatement ReturnStatement
%type <expr> Condition Expression Term Factor Numeric Boolean String AssignExpression FunctionCallExpression DeclarationExpression FPDeclaration ForInitExpression Primary MemberAccessExpression
%type <varvec> DeclarationList
%type <argvec> FPDeclarationList
%type <exprvec> FCParameterList
%type <identifier> Identifier
%type <type> Type

%start Program

%%

Program:
      GlobalStatements {
        $$ = new ddlbx::ir::NProgram();
        $$->statements = *$1;
        program = $$;
      }
    ;

GlobalStatements:
      GlobalStatement {
        $$ = new std::vector<std::shared_ptr<ddlbx::ir::NStatement>>();
        $$->push_back(std::shared_ptr<ddlbx::ir::NStatement>($1));
      }
    | GlobalStatements GlobalStatement {
        $1->push_back(std::shared_ptr<ddlbx::ir::NStatement>($2));
      } 
    ;

GlobalStatement:
      FunctionDeclaration
    | FunctionDefinition SEMICOLON {
        $$ = $1;
      }
    ;

FunctionDefinition:
      KW_FUNCTION Identifier LPAREN FPDeclarationList RPAREN COLON Type {
        $$ = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>($7), 
                                                std::shared_ptr<ddlbx::ir::NIdentifier>($2), 
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>($4)));
      }
    ;

FunctionDeclaration:
      FunctionDefinition Block {
        $$ = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>($1)),
                                                 std::shared_ptr<ddlbx::ir::NBlock>($2));
      }
    ;

FPDeclarationList:
      /* empty */ {
        $$ = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
      }
    | FPDeclarationList COMMA FPDeclaration {
        $1->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>($3)));
      }
    | FPDeclaration {
        $$ = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
        $$->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>($1)));
      }
    ;

FPDeclaration:
      Identifier COLON Type {
        $$ = new ddlbx::ir::NArgument(std::shared_ptr<ddlbx::ir::NType>($3), std::shared_ptr<ddlbx::ir::NIdentifier>($1));
      }
    ;

ReturnStatement:
      KW_RETURN Expression SEMICOLON {
        $$ = new ddlbx::ir::NReturnStatement(std::shared_ptr<ddlbx::ir::NExpression>($2));
      }
    | KW_RETURN SEMICOLON {
        $$ = new ddlbx::ir::NReturnStatement();
      }
    ;

FunctionCallExpression:
      Identifier LPAREN FCParameterList RPAREN {
        $$ = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NIdentifier>($1), std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*$3));
      }
    | MemberAccessExpression LPAREN FCParameterList RPAREN {
        $$ = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NMemberAccess>(dynamic_cast<ddlbx::ir::NMemberAccess*>($1)),
                                                          std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*$3));
      }
    ;

FCParameterList:
      /* empty */ {
        $$ = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
      }
    | FCParameterList COMMA Expression {
        $1->push_back(std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    | Expression {
        $$ = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
        $$->push_back(std::shared_ptr<ddlbx::ir::NExpression>($1));
      }
    ;

MemberAccessExpression:
      MemberAccessExpression DOT Identifier {
        dynamic_cast<ddlbx::ir::NMemberAccess*>($1)->ids.push_back(std::shared_ptr<ddlbx::ir::NIdentifier>($3));
      }
    | Primary DOT Identifier {
        $$ = new ddlbx::ir::NMemberAccess(std::shared_ptr<ddlbx::ir::NExpression>($1), {std::shared_ptr<ddlbx::ir::NIdentifier>($3)});
      }
    ;

Primary:
      Identifier {
        $$ = $1;
      }
    | Numeric {
        $$ = $1;
      }
    | Boolean {
        $$ = $1;
      }
    | String {
        $$ = $1;
      }
    | LPAREN Expression RPAREN {
        $$ = $2;
      }
    | FunctionCallExpression {
        $$ = $1;
      }
    ;

Statement:
      DeclarationExpression SEMICOLON {
        $$ = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>($1));
      }
    | AssignExpression SEMICOLON {
        $$ = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>($1));
      }
    | FunctionCallExpression SEMICOLON {
        $$ = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>($1));
      }
    | OptStatement
    | ForStatement
    | ReturnStatement
    ;

ForStatement:
      KW_FOR LPAREN ForInitExpression SEMICOLON Condition SEMICOLON AssignExpression RPAREN Block {
        $$ = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NExpression>($3), std::shared_ptr<ddlbx::ir::NExpression>($5), std::shared_ptr<ddlbx::ir::NExpression>($7), std::shared_ptr<ddlbx::ir::NBlock>($9));
      }
    ;

ForInitExpression:
      DeclarationExpression {
        $$ = $1;
      }
    | AssignExpression {
        $$ = $1;
      }
    ;

OptStatement:
      KW_OPT LPAREN Condition RPAREN Block {
        $$ = new ddlbx::ir::NOptStatement(std::shared_ptr<ddlbx::ir::NExpression>($3), std::shared_ptr<ddlbx::ir::NBlock>($5));
      }
    ;

Block:
      LBRACE Statements RBRACE {
        $$ = $2;
      }
    ;

Statements:
      /* empty */ {
        $$ = new ddlbx::ir::NBlock();
      }
    | Statements Statement {
        $1->statements.push_back($2);
      }
    ;

DeclarationExpression:
      KW_VAR DeclarationList {
        std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varList = $2;
        $$ = new ddlbx::ir::NVariableDeclarationList(*varList);
      }
    ;

DeclarationList:
      DeclarationList COMMA Identifier {
        $1->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>($3), nullptr));
      }
    | DeclarationList COMMA AssignExpression {
        $1->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>($3))));
      }
    | AssignExpression {
        $$ = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        $$->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>($1))));
      }
    | Identifier {
        $$ = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        $$->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>($1), nullptr));
      }
    ;

AssignExpression:
      Identifier OP_ASSIGN Expression {
        $$ = new ddlbx::ir::NAssignment(std::shared_ptr<ddlbx::ir::NIdentifier>($1), std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    ;

Condition:
      Expression COM_LT Expression {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    | Expression COM_GT Expression {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    | Expression COM_EQ Expression {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    | Expression COM_LE Expression {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    | Expression COM_GE Expression {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    | Expression COM_NE Expression {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    ;
Expression:
      Term {
        $$ = $1;
      }
    | Expression OP_PLUS Term {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    | Expression OP_MINUS Term {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    ;

Term:
      Factor {
        $$ = $1;
      }
    | Term OP_MULT Factor {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    | Term OP_DIV Factor {
        $$ = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>($1), $2, std::shared_ptr<ddlbx::ir::NExpression>($3));
      }
    ;

Factor:
      Identifier {
        $$ = $1;
      }
    | Numeric {
        $$ = $1;
      }
    | Boolean {
        $$ = $1;
      }
    | String {
        $$ = $1;
      }
    | LPAREN Expression RPAREN {
        $$ = $2;
      }
    | FunctionCallExpression {
        $$ = $1;
      }
    | MemberAccessExpression {
        $$ = $1;
      }
    ;

Identifier:
      IDENTIFIER {
        $$ = new ddlbx::ir::NIdentifier(*($1));
        delete $1;
      }
    ;

Numeric:
      NUMBER {
        $$ = new ddlbx::ir::NInteger(atol($1->c_str()));
      }
    | FRAC_NUMBER {
        $$ = new ddlbx::ir::NFloat(atof($1->c_str()));
      }
    ;

Boolean:
      BOOL {
        $$ = new ddlbx::ir::NBoolean(*$1);
      }
    ;

String:
      STRING {
        $$ = new ddlbx::ir::NString(*$1);
      }
    ;

Type:
      KW_INT {
        $$ = new ddlbx::ir::NType(*$1);
      }
    | KW_FLOAT {
        $$ = new ddlbx::ir::NType(*$1);
      }
    | KW_NONE {
        $$ = new ddlbx::ir::NType(*$1);
      }
    | KW_BOOL {
        $$ = new ddlbx::ir::NType(*$1);
      }
    | KW_STRING {
        $$ = new ddlbx::ir::NType(*$1);
      }

%%  

void yyerror(const char *s) {
    std::cout << "Error: " << s << " at line " << yylineno << ", near '" << yytext << "'\n\n";
    return;
}

void parseText(const char* text) {
    YY_BUFFER_STATE buffer = yy_scan_string(text);
    yyparse();
    yy_delete_buffer(buffer);
    return;
}