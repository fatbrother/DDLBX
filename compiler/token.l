%{
#include <string>
#include <iostream>
#include "ir/node.hpp"
#include "ir/object.hpp"
#include "ir/function.hpp"
#include "ir/statement.hpp"
#include "ir/expression.hpp"
#include "utils/logger.hpp"
#include "parser/parser.hpp"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) yylval.token = t; return t
#define YYTEXT_STR std::string(yytext)

extern int yylineno;
extern char* yytext;
int yycolumn = 1;

%}

%x COMMENT
%x MULTI_COMMENT

%option noyywrap
%option yylineno

%%

\/\/            { BEGIN COMMENT; }
<COMMENT>[^\n]* { ; }
<COMMENT>\n     { BEGIN 0; }

\/\*            { BEGIN MULTI_COMMENT; }
<MULTI_COMMENT>[^*]* { ; }
<MULTI_COMMENT>\*+[^*/]* { ; }
<MULTI_COMMENT>\*+\/ { BEGIN 0; }

"opt"           { ddlbx::utility::LOG_INFO("TOKEN: KW_OPT");      TOKEN(KW_OPT); }
"for"           { ddlbx::utility::LOG_INFO("TOKEN: KW_FOR");      TOKEN(KW_FOR); }
"ret"           { ddlbx::utility::LOG_INFO("TOKEN: KW_RETURN");   TOKEN(KW_RETURN); }
"fun"           { ddlbx::utility::LOG_INFO("TOKEN: KW_FUNCTION"); TOKEN(KW_FUNCTION); }
"var"           { ddlbx::utility::LOG_INFO("TOKEN: KW_VAR");      TOKEN(KW_VAR); }
"obj"           { ddlbx::utility::LOG_INFO("TOKEN: KW_OBJECT");   TOKEN(KW_OBJECT); }

"and"           { ddlbx::utility::LOG_INFO("TOKEN: AND");  TOKEN(OP_AND); }
"or"            { ddlbx::utility::LOG_INFO("TOKEN: OR");   TOKEN(OP_OR);  }
"not"           { ddlbx::utility::LOG_INFO("TOKEN: NOT");  TOKEN(OP_NOT); }

"from"          { ddlbx::utility::LOG_INFO("TOKEN: FROM");  TOKEN(KW_FROM); }
"to"            { ddlbx::utility::LOG_INFO("TOKEN: TO");    TOKEN(KW_TO); }
"step"          { ddlbx::utility::LOG_INFO("TOKEN: STEP");  TOKEN(KW_STEP); }

"true"                   { SAVE_TOKEN;     ddlbx::utility::LOG_INFO("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
"false"                  { SAVE_TOKEN;     ddlbx::utility::LOG_INFO("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
"maybe"                  { SAVE_TOKEN;     ddlbx::utility::LOG_INFO("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
[0-9]+                   { SAVE_TOKEN;     ddlbx::utility::LOG_INFO("TOKEN: INT " + YYTEXT_STR);          return NUMBER; }
[0-9]+"."[0-9]*          { SAVE_TOKEN;     ddlbx::utility::LOG_INFO("TOKEN: FLOAT " + YYTEXT_STR);        return FRAC_NUMBER; }
[A-Za-z_][A-Za-z0-9_]*   { SAVE_TOKEN;     ddlbx::utility::LOG_INFO("TOKEN: IDENTIFIER " + YYTEXT_STR);   return IDENTIFIER; }
\'[^"]*\'                { SAVE_TOKEN;     ddlbx::utility::LOG_INFO("TOKEN: STRING " + YYTEXT_STR);       return STRING; }


"=="            { ddlbx::utility::LOG_INFO("TOKEN: EQ");   TOKEN(COM_EQ); }
"<="            { ddlbx::utility::LOG_INFO("TOKEN: LE");   TOKEN(COM_LE); }
">="            { ddlbx::utility::LOG_INFO("TOKEN: GE");   TOKEN(COM_GE); }
"<>"            { ddlbx::utility::LOG_INFO("TOKEN: NE");   TOKEN(COM_NE); }

"<"             { ddlbx::utility::LOG_INFO("TOKEN: '<'");  TOKEN(COM_LT);  }
">"             { ddlbx::utility::LOG_INFO("TOKEN: '>'");  TOKEN(COM_GT);  }

"="             { ddlbx::utility::LOG_INFO("TOKEN: '='");  TOKEN(OP_ASSIGN); }
"+"             { ddlbx::utility::LOG_INFO("TOKEN: '+'");  TOKEN(OP_PLUS);   }
"-"             { ddlbx::utility::LOG_INFO("TOKEN: '-'");  TOKEN(OP_MINUS);  }
"*"             { ddlbx::utility::LOG_INFO("TOKEN: '*'");  TOKEN(OP_MULT);   }
"/"             { ddlbx::utility::LOG_INFO("TOKEN: '/'");  TOKEN(OP_DIV);    }

"("             { ddlbx::utility::LOG_INFO("TOKEN: '('");  TOKEN(LPAREN); }
")"             { ddlbx::utility::LOG_INFO("TOKEN: ')'");  TOKEN(RPAREN); }
"{"             { ddlbx::utility::LOG_INFO("TOKEN: '{'");  TOKEN(LBRACE); }
"}"             { ddlbx::utility::LOG_INFO("TOKEN: '}'");  TOKEN(RBRACE); }

","             { ddlbx::utility::LOG_INFO("TOKEN: ','");  TOKEN(COMMA);    }
":"             { ddlbx::utility::LOG_INFO("TOKEN: ':'");  TOKEN(COLON); }
"!"             { ddlbx::utility::LOG_INFO("TOKEN: '!'");  TOKEN(SEMICOLON); }
"."             { ddlbx::utility::LOG_INFO("TOKEN: '.'");  TOKEN(DOT); }

[ \t\r]+        { ; }
\n              { yycolumn = 1; }

.               { ddlbx::utility::LOG_INFO("unknown token: " + YYTEXT_STR + "\n"); yyterminate(); }

%%