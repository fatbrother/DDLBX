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
#define KW_GET 268
#define COM_EQ 269
#define COM_NE 270
#define COM_LE 271
#define COM_GE 272
#define COM_LT 273
#define COM_GT 274
#define OP_ASSIGN 275
#define OP_PLUS 276
#define OP_MINUS 277
#define OP_MULT 278
#define OP_DIV 279
#define OP_AND 280
#define OP_OR 281
#define OP_NOT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACE 285
#define RBRACE 286
#define SEMICOLON 287
#define COMMA 288
#define COLON 289
#define DOT 290
#define KW_FROM 291
#define KW_TO 292
#define KW_STEP 293
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
