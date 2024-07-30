#ifndef _yacc_defines_h_
#define _yacc_defines_h_

#define NUMBER 257
#define FRAC_NUMBER 258
#define IDENTIFIER 259
#define STRING 260
#define BOOL 261
#define KW_RETURN 262
#define KW_FUNCTION 263
#define KW_VAR 264
#define KW_OPT 265
#define KW_FOR 266
#define KW_OBJECT 267
#define COM_EQ 268
#define COM_NE 269
#define COM_LE 270
#define COM_GE 271
#define COM_LT 272
#define COM_GT 273
#define OP_ASSIGN 274
#define OP_PLUS 275
#define OP_MINUS 276
#define OP_MULT 277
#define OP_DIV 278
#define OP_AND 279
#define OP_OR 280
#define OP_NOT 281
#define LPAREN 282
#define RPAREN 283
#define LBRACE 284
#define RBRACE 285
#define SEMICOLON 286
#define COMMA 287
#define COLON 288
#define DOT 289
#define KW_FROM 290
#define KW_TO 291
#define KW_STEP 292
#define YYERRCODE 256

typedef union {
    ddlbx::ir::NProgram *program;
    ddlbx::ir::NType *type;
    ddlbx::ir::NBlock *block;
    ddlbx::ir::NExpression *expr;
    ddlbx::ir::NStatement *stmt;
    ddlbx::ir::NIdentifier *identifier;
    ddlbx::ir::NMemberDeclaration *member;
    std::vector<std::shared_ptr<ddlbx::ir::NStatement>> *stmtvec;
    std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varvec;
    std::vector<std::shared_ptr<ddlbx::ir::NArgument>> *argvec;
    std::vector<std::shared_ptr<ddlbx::ir::NExpression>> *exprvec;
    std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>> *membervec;
    std::vector<std::string> *stringvec;
    std::string *string;
    int token;
} YYSTYPE;
extern YYSTYPE yylval;

#endif
