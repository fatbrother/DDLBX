#line 8 "btyaccpa.ske"

//
// @(#)btyaccpar, based on byacc 1.8 (Berkeley)
//
#define YYBTYACC 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Yshort;

#line 2 "parser.y"
#include <string>
#include <iostream>
#include <vector>
#include "ir/node.hpp"
#include "utils/logger.hpp"
#include "parser/parser.hpp"

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

#line 28 "parser.y"
#line 41 "y.tab.c"
static int yylhs[] = {                                        -1,
    0,    1,    1,    5,    5,    5,    5,    5,    7,    7,
    6,   30,   30,   30,   25,   11,   11,   35,   34,   34,
   34,   12,   13,   10,   10,   23,   23,   28,   28,   33,
   32,   32,   32,   31,   31,   31,   27,   27,   26,   26,
   26,   26,   26,   26,   26,    4,    4,    4,    4,    4,
    4,    9,    9,    9,    9,    8,    2,    3,    3,   24,
   29,   29,   29,   29,   22,   14,   14,   14,   14,   15,
   15,   15,   15,   15,   15,   15,   16,   16,   16,   17,
   17,   17,   18,   18,   18,   18,   18,   18,   18,   18,
   36,   19,   19,   20,   21,   37,
};
static int yylen[] = {                                         2,
    1,    1,    2,    2,    1,    1,    1,    1,    7,    8,
    2,    0,    3,    1,    3,    5,    6,    3,    0,    3,
    1,   10,   12,    3,    2,    4,    4,    4,    5,    3,
    0,    3,    1,    0,    3,    1,    3,    3,    1,    1,
    1,    1,    3,    1,    1,    2,    2,    2,    1,    1,
    1,    7,    9,   11,    5,    5,    3,    0,    2,    2,
    3,    3,    1,    1,    3,    3,    3,    2,    1,    3,
    3,    3,    3,    3,    3,    1,    1,    3,    3,    1,
    3,    3,    1,    1,    1,    1,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,
};
static int yydefred[] = {                                      0,
    0,    0,    0,    0,    2,    6,    0,    7,    5,    8,
    0,    0,    0,    3,   58,    4,   11,    0,    0,    0,
    0,    0,    0,   21,    0,    0,    0,   96,    0,   33,
    0,   14,    0,    0,    0,    0,    0,    0,    0,    0,
   92,   93,    0,   95,   94,    0,    0,    0,    0,    0,
    0,   57,   59,   49,   50,   51,    0,    0,    0,    0,
   80,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   30,    0,    0,    0,    0,    0,    0,   18,    0,
   20,   16,    0,    0,    0,    0,   25,    0,    0,   91,
   63,    0,    0,    0,    0,   68,    0,   46,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   48,   47,    0,    0,    0,    0,   32,   15,    0,   13,
    0,    0,    0,   17,   36,    0,    0,    0,   24,    0,
    0,    0,    0,    0,   66,   67,    0,    0,    0,    0,
    0,    0,    0,    0,   81,   82,   38,    0,   37,   65,
    9,    0,    0,    0,   26,    0,   28,    0,   62,    0,
    0,    0,    0,    0,   27,    0,   10,    0,   35,   29,
   56,   55,    0,    0,    0,    0,    0,    0,    0,   22,
    0,    0,   52,    0,    0,    0,    0,   23,    0,   53,
    0,   54,
};
static int yydgoto[] = {                                       3,
    4,   17,   27,   53,    5,    6,    7,   54,   55,   56,
    8,    9,   10,  125,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   32,   68,   69,   70,   92,   33,
  126,   29,   21,   23,   24,   89,   30,
};
static int yysindex[] = {                                   -177,
 -242, -249,    0, -177,    0,    0, -237,    0,    0,    0,
 -228, -238, -227,    0,    0,    0,    0, -219, -213, -196,
 -207, -200, -166,    0, -238, -215, -181,    0, -234,    0,
 -197,    0, -190, -186, -213, -160, -176, -238, -134, -238,
    0,    0,  -32,    0,    0, -230, -151, -142, -128, -143,
 -143,    0,    0,    0,    0,    0, -164, -111,  267,  -84,
    0,    0,    0,    0, -100,    0,  -75,  -53, -222,    0,
 -126,    0, -219, -219,  -86, -213, -213, -185,    0,    2,
    0,    0,  -41, -143, -143,  -57,    0,  -18,    0,    0,
    0,  -44, -126, -245, -143,    0,    3,    0, -143, -143,
 -245, -245, -245, -245, -245, -245, -245, -245, -245, -245,
    0,    0, -151, -143, -151, -143,    0,    0, -219,    0,
 -141,    5,   29,    0,    0, -140,  -16, -143,    0, -151,
   38,   42,  -72,    0,    0,    0,   43,   43,   43,   43,
   43,   43,  -84,  -84,    0,    0,    0, -138,    0,    0,
    0,   39, -219, -213,    0, -143,    0,  -10,    0, -126,
   52,   52, -143, -143,    0, -219,    0, -112,    0,    0,
    0,    0,   55, -272,   52,   64, -143,   52, -143,    0,
 -219,   58,    0,   78,   52, -143,   52,    0,   88,    0,
   52,    0,
};
static int yyrindex[] = {                                      0,
    0,    0,    0,  377,    0,    0,    0,    0,    0,    0,
    0,    9,    0,    0,    0,    0,    0, -232,  -87,    0,
    0,    0,    0,    0,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -87,    0,    0,    0,    0,    9,
    0,    0, -113,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -180, -221,  112,
    0,  -88,  -63,  -38,    0,  -13,    0,    0,   87,   12,
 -145,    0,    0,    0,    0,    0,  -87,    0,    0,    0,
    0,    0,    0,  -62,   15,    0,    0,    0,   37,    0,
    0,  100,   57,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -62,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   15,    0,    0,
    0,    0,  187,   62,    0,    0,  192,  202,  212,  222,
  232,  242,  137,  162,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -87,    0,    0,    0,    0,    0,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static int yycindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  121,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static int yygindex[] = {                                      0,
    0, -153,    0,    0,  390,    0,    0,    0,    0,    0,
    0,    0,    0,  -27,  302,  443,  268,  280,    0,    0,
    0,  -43,    0,    0,  324,    0,    0,    0,    0,  -34,
  -78,    0,   -8,   -7,  363,  -21,  -71,
};
#define YYTABLESIZE 549
static int yytable[] = {                                      57,
   78,  117,  118,   91,   26,   71,  127,  171,  172,   13,
  178,   41,   42,   43,   44,   45,   11,   39,   88,  179,
   22,  180,   96,   97,  183,   93,   41,   42,   43,   44,
   45,  188,   83,  190,   86,  148,   51,  192,   72,   28,
   31,   12,  121,   18,   18,   31,   15,  151,   16,  158,
   50,   51,   73,   19,   31,   87,   25,   76,   76,  114,
   20,   76,   34,   76,   76,   76,  115,  132,   40,   76,
   76,  135,  136,  133,   35,   41,   42,   43,   44,   45,
   46,  167,   47,   48,   49,    1,  159,   36,  150,    2,
   74,  147,   75,  149,  175,   77,   76,  122,   79,   50,
   51,   76,   69,   52,   69,   69,   69,   90,  160,  185,
   69,   69,   80,   41,   42,   43,   44,   45,   37,  168,
   38,   98,   83,   83,   83,   83,   83,   83,  169,   83,
   83,   83,   83,   83,   83,  173,  174,   50,   51,   94,
   83,  152,  155,   39,  165,   76,  156,  116,  156,  182,
   82,  184,   38,   95,   91,   91,   91,   91,  189,   91,
   91,   91,   91,   91,   91,   91,   91,   99,  100,   91,
  176,   91,   91,   91,   76,   91,   91,   91,   91,   84,
   84,   84,   84,   84,   84,  111,   84,   84,   84,   84,
   84,   84,  109,  110,   84,   12,   84,   84,   84,   12,
   40,  119,   84,   84,   85,   85,   85,   85,   85,   85,
  112,   85,   85,   85,   85,   85,   85,  163,  164,   85,
   34,   85,   85,   85,   34,   41,  128,   85,   85,   86,
   86,   86,   86,   86,   86,  113,   86,   86,   86,   86,
   86,   86,  130,  124,   86,   38,   86,   86,   86,   84,
   42,   85,   86,   86,   88,   88,   88,   88,   88,   88,
  123,   88,   88,   88,   88,   88,   88,  129,  157,   88,
  156,   88,   88,   88,  170,   44,  156,   88,   88,   89,
   89,   89,   89,   89,   89,  134,   89,   89,   89,   89,
   89,   89,  153,   19,   89,   19,   89,   89,   89,   34,
   45,   34,   89,   89,   83,   83,   83,   83,   83,   83,
  154,   83,   83,   83,   83,   83,   83,  107,  108,   83,
  161,   83,   83,   83,  162,   39,  166,   83,   83,   87,
   87,   87,   87,   87,   87,   15,   87,   87,   87,   87,
   87,   87,   64,   64,   87,  177,   87,   87,   87,  186,
   43,  181,   87,   87,   90,   90,   90,   90,   90,   90,
  187,   90,   90,   90,   90,   90,   90,   61,   61,   90,
  191,   90,   90,   90,  143,  144,    1,   90,   90,   77,
   77,   77,   77,   77,   77,   60,   77,   77,  145,  146,
   77,   77,    0,   14,   77,  131,   77,   77,   77,  120,
   81,    0,   77,   77,   78,   78,   78,   78,   78,   78,
    0,   78,   78,    0,    0,   78,   78,    0,    0,   78,
    0,   78,   78,   78,    0,    0,    0,   78,   78,   79,
   79,   79,   79,   79,   79,    0,   79,   79,    0,    0,
   79,   79,    0,    0,   79,    0,   79,   79,   79,    0,
    0,    0,   79,   79,   83,   83,   83,   83,   83,   83,
    0,   83,   83,   83,   83,   83,   83,    0,    0,   83,
   72,   72,    0,    0,   72,   39,   72,   72,   72,    0,
   75,   75,   72,   72,   75,    0,   75,   75,   75,    0,
   73,   73,   75,   75,   73,    0,   73,   73,   73,    0,
   74,   74,   73,   73,   74,    0,   74,   74,   74,    0,
   70,   70,   74,   74,   70,    0,   70,   70,   70,    0,
   71,   71,   70,   70,   71,    0,   71,   71,   71,    0,
    0,    0,   71,   71,  101,  102,  103,  104,  105,  106,
    0,  107,  108,  137,  138,  139,  140,  141,  142,
};
static int yycheck[] = {                                      27,
   35,   73,   74,   47,   13,   27,   85,  161,  162,  259,
  283,  257,  258,  259,  260,  261,  259,   25,   46,  292,
  259,  175,   50,   51,  178,   47,  257,  258,  259,  260,
  261,  185,   40,  187,   43,  114,  282,  191,  273,  259,
  273,  284,   77,  272,  272,  259,  284,  119,  286,  128,
  281,  282,  287,  282,  287,  286,  284,  279,  280,  282,
  289,  283,  259,  285,  286,  287,  289,   95,  284,  291,
  292,   99,  100,   95,  282,  257,  258,  259,  260,  261,
  262,  153,  264,  265,  266,  263,  130,  288,  116,  267,
  288,  113,  283,  115,  166,  282,  287,  283,  259,  281,
  282,  287,  283,  285,  285,  286,  287,  259,  130,  181,
  291,  292,  289,  257,  258,  259,  260,  261,  285,  154,
  287,  286,  268,  269,  270,  271,  272,  273,  156,  275,
  276,  277,  278,  279,  280,  163,  164,  281,  282,  282,
  286,  283,  283,  289,  283,  287,  287,  274,  287,  177,
  285,  179,  287,  282,  268,  269,  270,  271,  186,  273,
  274,  275,  276,  277,  278,  279,  280,  279,  280,  283,
  283,  285,  286,  287,  287,  289,  290,  291,  292,  268,
  269,  270,  271,  272,  273,  286,  275,  276,  277,  278,
  279,  280,  277,  278,  283,  283,  285,  286,  287,  287,
  289,  288,  291,  292,  268,  269,  270,  271,  272,  273,
  286,  275,  276,  277,  278,  279,  280,  290,  291,  283,
  283,  285,  286,  287,  287,  289,  284,  291,  292,  268,
  269,  270,  271,  272,  273,  289,  275,  276,  277,  278,
  279,  280,  287,  285,  283,  287,  285,  286,  287,  282,
  289,  284,  291,  292,  268,  269,  270,  271,  272,  273,
  259,  275,  276,  277,  278,  279,  280,  286,  285,  283,
  287,  285,  286,  287,  285,  289,  287,  291,  292,  268,
  269,  270,  271,  272,  273,  283,  275,  276,  277,  278,
  279,  280,  288,  285,  283,  287,  285,  286,  287,  285,
  289,  287,  291,  292,  268,  269,  270,  271,  272,  273,
  282,  275,  276,  277,  278,  279,  280,  275,  276,  283,
  283,  285,  286,  287,  283,  289,  288,  291,  292,  268,
  269,  270,  271,  272,  273,  284,  275,  276,  277,  278,
  279,  280,  286,  287,  283,  291,  285,  286,  287,  292,
  289,  288,  291,  292,  268,  269,  270,  271,  272,  273,
  283,  275,  276,  277,  278,  279,  280,  286,  287,  283,
  283,  285,  286,  287,  107,  108,    0,  291,  292,  268,
  269,  270,  271,  272,  273,  286,  275,  276,  109,  110,
  279,  280,  272,    4,  283,   94,  285,  286,  287,   76,
   38,   -1,  291,  292,  268,  269,  270,  271,  272,  273,
   -1,  275,  276,   -1,   -1,  279,  280,   -1,   -1,  283,
   -1,  285,  286,  287,   -1,   -1,   -1,  291,  292,  268,
  269,  270,  271,  272,  273,   -1,  275,  276,   -1,   -1,
  279,  280,   -1,   -1,  283,   -1,  285,  286,  287,   -1,
   -1,   -1,  291,  292,  268,  269,  270,  271,  272,  273,
   -1,  275,  276,  277,  278,  279,  280,   -1,   -1,  283,
  279,  280,   -1,   -1,  283,  289,  285,  286,  287,   -1,
  279,  280,  291,  292,  283,   -1,  285,  286,  287,   -1,
  279,  280,  291,  292,  283,   -1,  285,  286,  287,   -1,
  279,  280,  291,  292,  283,   -1,  285,  286,  287,   -1,
  279,  280,  291,  292,  283,   -1,  285,  286,  287,   -1,
  279,  280,  291,  292,  283,   -1,  285,  286,  287,   -1,
   -1,   -1,  291,  292,  268,  269,  270,  271,  272,  273,
   -1,  275,  276,  101,  102,  103,  104,  105,  106,
};
static int yyctable[] = {                                     18,
   91,   -1,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#if YYDEBUG
static char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUMBER","FRAC_NUMBER",
"IDENTIFIER","STRING","BOOL","KW_RETURN","KW_FUNCTION","KW_VAR","KW_OPT",
"KW_FOR","KW_OBJECT","COM_EQ","COM_NE","COM_LE","COM_GE","COM_LT","COM_GT",
"OP_ASSIGN","OP_PLUS","OP_MINUS","OP_MULT","OP_DIV","OP_AND","OP_OR","OP_NOT",
"LPAREN","RPAREN","LBRACE","RBRACE","SEMICOLON","COMMA","COLON","DOT","KW_FROM",
"KW_TO","KW_STEP",
};
static char *yyrule[] = {
"$accept : Program",
"Program : GlobalStatements",
"GlobalStatements : GlobalStatement",
"GlobalStatements : GlobalStatements GlobalStatement",
"GlobalStatement : FunctionDefinition SEMICOLON",
"GlobalStatement : MethodDeclaration",
"GlobalStatement : FunctionDeclaration",
"GlobalStatement : ObjectDeclaration",
"GlobalStatement : TraitMethodDeclaration",
"FunctionDefinition : KW_FUNCTION IDENTIFIER LPAREN FPDeclarationList RPAREN COLON Type",
"FunctionDefinition : KW_FUNCTION IDENTIFIER TemplateDeclaration LPAREN FPDeclarationList RPAREN COLON Type",
"FunctionDeclaration : FunctionDefinition Block",
"FPDeclarationList :",
"FPDeclarationList : FPDeclarationList COMMA FPDeclaration",
"FPDeclarationList : FPDeclaration",
"FPDeclaration : IDENTIFIER COLON Type",
"ObjectDeclaration : KW_OBJECT IDENTIFIER LBRACE MemberDeclarationList RBRACE",
"ObjectDeclaration : KW_OBJECT IDENTIFIER TemplateDeclaration LBRACE MemberDeclarationList RBRACE",
"MemberDeclaration : IDENTIFIER COLON IDENTIFIER",
"MemberDeclarationList :",
"MemberDeclarationList : MemberDeclarationList COMMA MemberDeclaration",
"MemberDeclarationList : MemberDeclaration",
"MethodDeclaration : KW_FUNCTION IDENTIFIER DOT IDENTIFIER LPAREN FPDeclarationList RPAREN COLON Type Block",
"TraitMethodDeclaration : KW_FUNCTION LBRACE MemberDeclarationList RBRACE DOT IDENTIFIER LPAREN FPDeclarationList RPAREN COLON Type Block",
"ReturnStatement : KW_RETURN Expression SEMICOLON",
"ReturnStatement : KW_RETURN SEMICOLON",
"FunctionCallExpression : IDENTIFIER LPAREN FCParameterList RPAREN",
"FunctionCallExpression : MemberAccessExpression LPAREN FCParameterList RPAREN",
"ObjectCreateExpression : IDENTIFIER LBRACE FCParameterList RBRACE",
"ObjectCreateExpression : IDENTIFIER TemplateDeclaration LBRACE FCParameterList RBRACE",
"TemplateDeclaration : COM_LT TypeList COM_GT",
"TypeList :",
"TypeList : TypeList COMMA Type",
"TypeList : Type",
"FCParameterList :",
"FCParameterList : FCParameterList COMMA Expression",
"FCParameterList : Expression",
"MemberAccessExpression : MemberAccessExpression DOT Identifier",
"MemberAccessExpression : Primary DOT Identifier",
"Primary : Identifier",
"Primary : Numeric",
"Primary : Boolean",
"Primary : String",
"Primary : LPAREN Expression RPAREN",
"Primary : FunctionCallExpression",
"Primary : ObjectCreateExpression",
"Statement : Expression SEMICOLON",
"Statement : DeclarationExpression SEMICOLON",
"Statement : AssignExpression SEMICOLON",
"Statement : OptStatement",
"Statement : ForStatement",
"Statement : ReturnStatement",
"ForStatement : KW_FOR LPAREN Identifier KW_TO Expression RPAREN Block",
"ForStatement : KW_FOR LPAREN Identifier KW_TO Expression KW_STEP Expression RPAREN Block",
"ForStatement : KW_FOR LPAREN Identifier KW_FROM Expression KW_TO Expression KW_STEP Expression RPAREN Block",
"ForStatement : KW_FOR LPAREN Expression RPAREN Block",
"OptStatement : KW_OPT LPAREN Condition RPAREN Block",
"Block : LBRACE Statements RBRACE",
"Statements :",
"Statements : Statements Statement",
"DeclarationExpression : KW_VAR DeclarationList",
"DeclarationList : DeclarationList COMMA Identifier",
"DeclarationList : DeclarationList COMMA AssignExpression",
"DeclarationList : AssignExpression",
"DeclarationList : Identifier",
"AssignExpression : Identifier OP_ASSIGN Expression",
"Expression : Condition OP_AND Expression",
"Expression : Condition OP_OR Expression",
"Expression : OP_NOT Expression",
"Expression : Condition",
"Condition : Calculation COM_LT Calculation",
"Condition : Calculation COM_GT Calculation",
"Condition : Calculation COM_EQ Calculation",
"Condition : Calculation COM_LE Calculation",
"Condition : Calculation COM_GE Calculation",
"Condition : Calculation COM_NE Calculation",
"Condition : Calculation",
"Calculation : Term",
"Calculation : Calculation OP_PLUS Term",
"Calculation : Calculation OP_MINUS Term",
"Term : Factor",
"Term : Term OP_MULT Factor",
"Term : Term OP_DIV Factor",
"Factor : Identifier",
"Factor : Numeric",
"Factor : Boolean",
"Factor : String",
"Factor : LPAREN Expression RPAREN",
"Factor : FunctionCallExpression",
"Factor : ObjectCreateExpression",
"Factor : MemberAccessExpression",
"Identifier : IDENTIFIER",
"Numeric : NUMBER",
"Numeric : FRAC_NUMBER",
"Boolean : BOOL",
"String : STRING",
"Type : IDENTIFIER",
};
#endif
#line 42 "btyaccpa.ske"

//
// YYPOSN is user-defined text position type.
//
#ifndef YYPOSN
#define YYPOSN int
#endif

#ifdef YYREDUCEPOSNFUNC
#define YYCALLREDUCEPOSN(e)   \
	if(reduce_posn) {     \
	  YYREDUCEPOSNFUNC(yyps->pos, &(yyps->psp)[1-yym], &(yyps->vsp)[1-yym], \
			   yym, yyps->psp - yyps->ps, yychar, yyposn, e);       \
	  reduce_posn = 0;    \
	}

#ifndef YYCALLREDUCEPOSNARG
#define YYCALLREDUCEPOSNARG yyps->val
#endif


#define YYPOSNARG(n) ((yyps->psp)[1-yym+(n)-1])
#define YYPOSNOUT    (yyps->pos)
#endif

/* If delete function is not defined by the user, do not delete. */
#ifndef YYDELETEVAL
#  define YYDELETEVAL(v, t) 
#endif

/* If delete function is not defined by the user, do not delete. */
#ifndef YYDELETEPOSN
#  define YYDELETEPOSN(v, t) 
#endif

#define yyclearin (yychar=(-1))

#define yyerrok (yyps->errflag=0)

#ifndef YYSTACKGROWTH
#define YYSTACKGROWTH 16
#endif

#ifndef YYDEFSTACKSIZE
#define YYDEFSTACKSIZE 12
#endif

#ifdef YYDEBUG
int yydebug;
#endif

int yynerrs;

/* These value/posn are taken from the lexer */
YYSTYPE yylval;
YYPOSN  yyposn;

/* These value/posn of the root non-terminal are returned to the caller */
YYSTYPE yyretlval;
YYPOSN  yyretposn;

#define YYABORT  goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#define YYVALID         do { if (yyps->save)          goto yyvalid; } while(0)
#define YYVALID_NESTED  do { if (yyps->save && \
                                 yyps->save->save==0) goto yyvalid; } while(0)

struct yyparsestate {
  yyparsestate *save;        // Previously saved parser state
  int           state;
  int           errflag;
  Yshort       *ssp;         // state stack pointer
  YYSTYPE      *vsp;         // value stack pointer
  YYPOSN       *psp;         // position stack pointer
  YYSTYPE       val;         // value as returned by actions
  YYPOSN        pos;         // position as returned by universal action
  Yshort       *ss;          // state stack base
  YYSTYPE      *vs;          // values stack base
  YYPOSN       *ps;          // position stack base
  int           lexeme;      // index of the conflict lexeme in the lexical queue
  unsigned int  stacksize;   // current maximum stack size
  Yshort        ctry;        // index in yyctable[] for this conflict
};

// Current parser state
static yyparsestate *yyps=0;

// yypath!=NULL: do the full parse, starting at *yypath parser state.
static yyparsestate *yypath=0;

// Base of the lexical value queue
static YYSTYPE *yylvals=0;

// Current posistion at lexical value queue
static YYSTYPE *yylvp=0;

// End position of lexical value queue
static YYSTYPE *yylve=0;

// The last allocated position at the lexical value queue
static YYSTYPE *yylvlim=0;

// Base of the lexical position queue
static YYPOSN *yylpsns=0;

// Current posistion at lexical position queue
static YYPOSN *yylpp=0;

// End position of lexical position queue
static YYPOSN *yylpe=0;

// The last allocated position at the lexical position queue
static YYPOSN *yylplim=0;

// Current position at lexical token queue
static Yshort *yylexp=0;

static Yshort *yylexemes=0;

//
// For use in generated program
//
#define yytrial (yyps->save)
#define yyvsp   (yyps->vsp)
#define yyval   (yyps->val)
#define yydepth (yyps->ssp - yyps->ss)


//
// Local prototypes.
//
int yyparse(void);

int  YYLex1();
int  yyexpand();
void YYSCopy(YYSTYPE *to, YYSTYPE *from, int size);
void YYPCopy(YYPOSN  *to, YYPOSN  *from, int size);
void YYMoreStack(yyparsestate *yyps);
yyparsestate *YYNewState(int size);
void YYFreeState(yyparsestate *p);


#line 495 "parser.y"
  

void yyerror(const char *s) {
    ddlbx::utility::Logger::error("Error: " + std::string(s) + " at " + std::to_string(yylineno) + ":" + std::to_string(yycolumn) + " near " + std::string(yytext));
    return;
}

void parseText(const char* text) {
    YY_BUFFER_STATE buffer = yy_scan_string(text);
    yyparse();
    yy_delete_buffer(buffer);
    return;
}
#line 599 "y.tab.c"
#line 186 "btyaccpa.ske"


//
// Parser function
//
int yyparse() {
  int yym, yyn, yystate, yychar, yynewerrflag;
  yyparsestate *yyerrctx = NULL;
  int reduce_posn;

#if YYDEBUG
  char *yys;
  
  if ((yys = getenv("YYDEBUG"))) {
    yyn = *yys;
    if (yyn >= '0' && yyn <= '9')
      yydebug = yyn - '0'; 
  }
#endif
  
  yyps = YYNewState(YYDEFSTACKSIZE);
  yyps->save = 0;
  yynerrs = 0;
  yyps->errflag = 0;
  yychar = (-1);
  
  yyps->ssp = yyps->ss;
  yyps->vsp = yyps->vs;
  yyps->psp = yyps->ps;
  *(yyps->ssp) = yystate = 0;
  

  //
  // Main parsing loop
  //
 yyloop:
  if ((yyn = yydefred[yystate])) {
    goto yyreduce;
  }

  //
  // Read one token
  //
  if (yychar < 0) {
    if ((yychar = YYLex1()) < 0) yychar = 0;
#if YYDEBUG
    if (yydebug) {
      yys = 0;
      if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
      if (!yys) yys = "illegal-symbol";
      printf("yydebug[%d,%d]: state %d, reading %d (%s)", 
	     yydepth, (int)yytrial, yystate, yychar, yys);
#ifdef YYDBPR
      printf("<");
      YYDBPR(yylval);
      printf(">");
#endif
      printf("\n"); 
    }
#endif
  }

  //
  // Do we have a conflict?
  //
  if ((yyn = yycindex[yystate]) &&
      (yyn += yychar) >= 0 &&
      yyn <= YYTABLESIZE &&
      yycheck[yyn] == yychar) {
    int ctry;

    if (yypath) {
#if YYDEBUG
      if (yydebug) {
        printf("yydebug[%d,%d]: CONFLICT in state %d: following successful trial parse\n", 
	       yydepth, (int)yytrial, yystate);
      }
#endif
      // Switch to the next conflict context
      yyparsestate *save = yypath;
      yypath = save->save;
      ctry = save->ctry;
      if (save->state != yystate) 
        goto yyabort;
      YYFreeState(save); 

    } else {

#if YYDEBUG
      if (yydebug) {
        printf("yydebug[%d,%d]: CONFLICT in state %d. ", 
	       yydepth, (int)yytrial, yystate);
        if(yyps->save) {
          printf("ALREADY in conflict. Continue trial parse.");
        } else {
          printf("Start trial parse.");
        }
        printf("\n");
      }
#endif
      yyparsestate *save = YYNewState(yyps->ssp - yyps->ss);
      save->save    = yyps->save;
      save->state   = yystate;
      save->errflag = yyps->errflag;
      save->ssp     = save->ss + (yyps->ssp - yyps->ss);
      save->vsp     = save->vs + (yyps->vsp - yyps->vs);
      save->psp     = save->ps + (yyps->psp - yyps->ps);
      memcpy (save->ss, yyps->ss, (yyps->ssp - yyps->ss + 1)*sizeof(Yshort));
      YYSCopy(save->vs, yyps->vs, (yyps->ssp - yyps->ss + 1));
      YYPCopy(save->ps, yyps->ps, (yyps->ssp - yyps->ss + 1));
      ctry = yytable[yyn];
      if (yyctable[ctry] == -1) {
#if YYDEBUG
        if (yydebug && yychar >= 0)
          printf("yydebug[%d]: backtracking 1 token\n", 
		 (int)yytrial);
#endif
        ctry++; 
      }
      save->ctry = ctry;
      if (!yyps->save) {
        // If this is a first conflict in the stack, start saving lexemes
        if (!yylexemes) {
          yylexemes = new Yshort[YYSTACKGROWTH];
          yylvals = new YYSTYPE[YYSTACKGROWTH];
          yylvlim = yylvals + YYSTACKGROWTH; 
          yylpsns = new YYPOSN[YYSTACKGROWTH];
          yylplim = yylpsns + YYSTACKGROWTH; 
        }
        if (yylvp == yylve) {
          yylvp = yylve = yylvals;
	  yylpp = yylpe = yylpsns;
          yylexp = yylexemes;
          if (yychar >= 0) {
            *yylve++ = yylval;
            *yylpe++ = yyposn;
            *yylexp = yychar;
            yychar = -1; 
          } 
        } 
      }
      if (yychar >= 0) {
        yylvp--, yylpp--, yylexp--;
        yychar = -1; 
      }
      save->lexeme = yylvp - yylvals;
      yyps->save = save; 
    }
    if (yytable[yyn] == ctry) {
#if YYDEBUG
      if (yydebug)
        printf("yydebug[%d,%d]: state %d, shifting to state %d\n",
               yydepth, (int)yytrial, yystate, yyctable[ctry]);
#endif
      if (yychar < 0)
        yylvp++, yylpp++, yylexp++;
      yychar = -1;
      if (yyps->errflag > 0) --yyps->errflag;
      yystate = yyctable[ctry];
      goto yyshift; 
    } else {
      yyn = yyctable[ctry];
      goto yyreduce; 
    } 
  }

  //
  // Is action a shift?
  //
  if ((yyn = yysindex[yystate]) &&
      (yyn += yychar) >= 0 &&
      yyn <= YYTABLESIZE &&
      yycheck[yyn] == yychar) {
#if YYDEBUG
    if (yydebug)
      printf("yydebug[%d,%d]: state %d, shifting to state %d\n",
             yydepth, (int)yytrial, yystate, yytable[yyn]);
#endif
    yychar = (-1);
    if (yyps->errflag > 0)  --yyps->errflag;
    yystate = yytable[yyn];
  yyshift:
    if (yyps->ssp >= yyps->ss + yyps->stacksize - 1) {
      YYMoreStack(yyps);
    }
    *++(yyps->ssp) = yystate;
    *++(yyps->vsp) = yylval;
    *++(yyps->psp) = yyposn;
    goto yyloop;
  }
  if ((yyn = yyrindex[yystate]) &&
      (yyn += yychar) >= 0 &&
      yyn <= YYTABLESIZE &&
      yycheck[yyn] == yychar) {
    yyn = yytable[yyn];
    goto yyreduce;
  }

  //
  // Action: error
  //
  if (yyps->errflag) goto yyinrecovery;
  yynewerrflag = 1;
  goto yyerrhandler;
yyerrlab:
  yynewerrflag = 0;
yyerrhandler:
  while (yyps->save) { 
    int ctry; 
    yyparsestate *save = yyps->save;
#if YYDEBUG
    if (yydebug)
      printf("yydebug[%d,%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
             yydepth, (int)yytrial, yystate, yyps->save->state, yylvp - yylvals - yyps->save->lexeme);
#endif
    // Memorize most forward-looking error state in case
    // it's really an error.
    if(yyerrctx==NULL || yyerrctx->lexeme<yylvp-yylvals) {
      // Free old saved error context state
      if(yyerrctx) YYFreeState(yyerrctx);
      // Create and fill out new saved error context state
      yyerrctx = YYNewState(yyps->ssp - yyps->ss);
      yyerrctx->save = yyps->save;
      yyerrctx->state = yystate;
      yyerrctx->errflag = yyps->errflag;
      yyerrctx->ssp = yyerrctx->ss + (yyps->ssp - yyps->ss);
      yyerrctx->vsp = yyerrctx->vs + (yyps->vsp - yyps->vs);
      yyerrctx->psp = yyerrctx->ps + (yyps->psp - yyps->ps);
      memcpy (yyerrctx->ss, yyps->ss, (yyps->ssp - yyps->ss + 1)*sizeof(Yshort));
      YYSCopy(yyerrctx->vs, yyps->vs, (yyps->ssp - yyps->ss + 1));
      YYPCopy(yyerrctx->ps, yyps->ps, (yyps->ssp - yyps->ss + 1));
      yyerrctx->lexeme = yylvp - yylvals;
    }
    yylvp  = yylvals   + save->lexeme;
    yylpp  = yylpsns   + save->lexeme;
    yylexp = yylexemes + save->lexeme;
    yychar = -1;
    yyps->ssp = yyps->ss + (save->ssp - save->ss);
    yyps->vsp = yyps->vs + (save->vsp - save->vs);
    yyps->psp = yyps->ps + (save->psp - save->ps);
    memcpy (yyps->ss, save->ss, (yyps->ssp - yyps->ss + 1) * sizeof(Yshort));
    YYSCopy(yyps->vs, save->vs,  yyps->vsp - yyps->vs + 1);
    YYPCopy(yyps->ps, save->ps,  yyps->psp - yyps->ps + 1);
    ctry = ++save->ctry;
    yystate = save->state;
    // We tried shift, try reduce now
    if ((yyn = yyctable[ctry]) >= 0) {
      goto yyreduce;
    }
    yyps->save = save->save;
    YYFreeState(save);
    //
    // Nothing left on the stack -- error
    //
    if (!yyps->save) {
#if YYDEBUG
      if (yydebug) {
        printf("yydebug[%d]: trial parse FAILED, entering ERROR mode\n", 
	       (int)yytrial);
      }
#endif
      // Restore state as it was in the most forward-advanced error
      yylvp  = yylvals   + yyerrctx->lexeme;
      yylpp  = yylpsns   + yyerrctx->lexeme;
      yylexp = yylexemes + yyerrctx->lexeme;
      yychar = yylexp[-1];
      yylval = yylvp[-1];
      yyposn = yylpp[-1];
      yyps->ssp = yyps->ss + (yyerrctx->ssp - yyerrctx->ss);
      yyps->vsp = yyps->vs + (yyerrctx->vsp - yyerrctx->vs);
      yyps->psp = yyps->ps + (yyerrctx->psp - yyerrctx->ps);
      memcpy (yyps->ss, yyerrctx->ss, (yyps->ssp - yyps->ss + 1) * sizeof(Yshort));
      YYSCopy(yyps->vs, yyerrctx->vs,  yyps->vsp - yyps->vs + 1);
      YYPCopy(yyps->ps, yyerrctx->ps,  yyps->psp - yyps->ps + 1);
      yystate = yyerrctx->state;
      YYFreeState(yyerrctx);
      yyerrctx = NULL;
    }
    yynewerrflag = 1; 
  }
  if (yynewerrflag) {
#ifdef YYERROR_DETAILED
    yyerror_detailed("syntax error", yychar, yylval, yyposn);
#else
    yyerror("syntax error");
#endif
  }
  ++yynerrs;
 yyinrecovery:
  if (yyps->errflag < 3) {
    yyps->errflag = 3;
    for (;;) {
      if ((yyn = yysindex[*(yyps->ssp)]) && 
	  (yyn += YYERRCODE) >= 0 &&
          yyn <= YYTABLESIZE && 
	  yycheck[yyn] == YYERRCODE) {
#if YYDEBUG
        if (yydebug)
          printf("yydebug[%d,%d]: state %d, ERROR recovery shifts to state %d\n",
                 yydepth, (int)yytrial, *(yyps->ssp), yytable[yyn]);
#endif
        /* Use label yyerrlab, so that compiler does not warn */
        if(yyps->errflag != yyps->errflag) goto yyerrlab;
        yystate = yytable[yyn];
        goto yyshift; 
      } else {
#if YYDEBUG
        if (yydebug)
          printf("yydebug[%d,%d]: ERROR recovery discards state %d\n",
                 yydepth, (int)yytrial, *(yyps->ssp));
#endif
        if (yyps->ssp <= yyps->ss) {
	  goto yyabort;
	}
	if(!yytrial) {
	  YYDELETEVAL(yyps->vsp[0],1);
	  YYDELETEPOSN(yyps->psp[0],1);
	}
        --(yyps->ssp);
        --(yyps->vsp);
        --(yyps->psp);
      }
    }
  } else {
    if (yychar == 0) goto yyabort;
#if YYDEBUG
    if (yydebug) {
      yys = 0;
      if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
      if (!yys) yys = "illegal-symbol";
      printf("yydebug[%d,%d]: state %d, ERROR recovery discards token %d (%s)\n",
             yydepth, (int)yytrial, yystate, yychar, yys); 
    }
#endif
    if(!yytrial) {
      YYDELETEVAL(yylval,0);
      YYDELETEPOSN(yyposn,0);
    }
    yychar = (-1);
    goto yyloop;
  }

  //
  // Reduce the rule
  //
yyreduce:
  yym = yylen[yyn];
#if YYDEBUG
  if (yydebug) {
    printf("yydebug[%d,%d]: state %d, reducing by rule %d (%s)",
           yydepth, (int)yytrial, yystate, yyn, yyrule[yyn]);
#ifdef YYDBPR
    if (yym) {
      int i;
      printf("<");
      for (i=yym; i>0; i--) {
        if (i!=yym) printf(", ");
        YYDBPR((yyps->vsp)[1-i]);
      }
      printf(">");
    }
#endif
    printf("\n");
  }
#endif
  if (yyps->ssp + 1 - yym >= yyps->ss + yyps->stacksize) {
    YYMoreStack(yyps);
  }

# ifdef _YACC_DEFAULT_ACTION_
  /* "$$ = NULL" default action */
  memset(&yyps->val, 0, sizeof(yyps->val));
# else
  /* RA: bison compatibility: default action is '$$ = $1;' */
  if (yym > 0) yyps->val = (yyps->vsp)[1 - yym];
# endif

  /* Default reduced position is NULL -- no position at all. No
     position will be assigned at trial time and if no position
     handling is present */
  memset(&yyps->pos, 0, sizeof(yyps->pos));

  reduce_posn = 1;

  switch (yyn) {

case 1:
  if (!yytrial)
#line 74 "parser.y"
{
        yyval.program = new ddlbx::ir::NProgram();
        yyval.program->statements = *yyvsp[0].stmtvec;
        program = yyval.program;
      }
#line 995 "y.tab.c"
break;
case 2:
  if (!yytrial)
#line 82 "parser.y"
{
        yyval.stmtvec = new std::vector<std::shared_ptr<ddlbx::ir::NStatement>>();
        yyval.stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1004 "y.tab.c"
break;
case 3:
  if (!yytrial)
#line 86 "parser.y"
{
        yyvsp[-1].stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1012 "y.tab.c"
break;
case 4:
  if (!yytrial)
#line 92 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1020 "y.tab.c"
break;
case 9:
  if (!yytrial)
#line 102 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), 
                                                *yyvsp[-5].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)));
      }
#line 1030 "y.tab.c"
break;
case 10:
  if (!yytrial)
#line 107 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), 
                                                *yyvsp[-6].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)),
                                                *yyvsp[-5].stringvec);
      }
#line 1041 "y.tab.c"
break;
case 11:
  if (!yytrial)
#line 116 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>(yyvsp[-1].stmt)),
                                                 std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1050 "y.tab.c"
break;
case 12:
  if (!yytrial)
#line 123 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
      }
#line 1058 "y.tab.c"
break;
case 13:
  if (!yytrial)
#line 126 "parser.y"
{
        yyvsp[-2].argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1066 "y.tab.c"
break;
case 14:
  if (!yytrial)
#line 129 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
        yyval.argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1075 "y.tab.c"
break;
case 15:
  if (!yytrial)
#line 136 "parser.y"
{
        yyval.expr = new ddlbx::ir::NArgument(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), *yyvsp[-2].string);
      }
#line 1083 "y.tab.c"
break;
case 16:
  if (!yytrial)
#line 142 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NObjectDeclaration(*yyvsp[-3].string, *yyvsp[-1].membervec);
      }
#line 1091 "y.tab.c"
break;
case 17:
  if (!yytrial)
#line 145 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateObjectDeclaration(*yyvsp[-4].string, *yyvsp[-1].membervec, *yyvsp[-3].stringvec);
      }
#line 1099 "y.tab.c"
break;
case 18:
  if (!yytrial)
#line 150 "parser.y"
{
        yyval.member = new ddlbx::ir::NMemberDeclaration(std::make_shared<ddlbx::ir::NType>(*yyvsp[0].string), *yyvsp[-2].string);
      }
#line 1107 "y.tab.c"
break;
case 19:
  if (!yytrial)
#line 156 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
      }
#line 1115 "y.tab.c"
break;
case 20:
  if (!yytrial)
#line 159 "parser.y"
{
        yyvsp[-2].membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1123 "y.tab.c"
break;
case 21:
  if (!yytrial)
#line 162 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
        yyval.membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1132 "y.tab.c"
break;
case 22:
  if (!yytrial)
#line 169 "parser.y"
{
        ddlbx::ir::NFunctionDefinition *funcDef = new ddlbx::ir::NFunctionDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[-1].type), *yyvsp[-6].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-4].argvec)));
        ddlbx::ir::NFunctionDeclaration *funcDecl = new ddlbx::ir::NFunctionDeclaration(
            std::shared_ptr<ddlbx::ir::NFunctionDefinition>(funcDef), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
        yyval.stmt = new ddlbx::ir::NMethodDeclaration(*yyvsp[-8].string, std::shared_ptr<ddlbx::ir::NFunctionDeclaration>(funcDecl));
      }
#line 1144 "y.tab.c"
break;
case 23:
  if (!yytrial)
#line 178 "parser.y"
{
        ddlbx::ir::NFunctionDefinition *funcDef = new ddlbx::ir::NFunctionDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[-1].type), *yyvsp[-6].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-4].argvec)));
        ddlbx::ir::NFunctionDeclaration *funcDecl = new ddlbx::ir::NFunctionDeclaration(
            std::shared_ptr<ddlbx::ir::NFunctionDefinition>(funcDef), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
        yyval.stmt = new ddlbx::ir::NTraitMethodDeclaration(*yyvsp[-9].membervec, std::shared_ptr<ddlbx::ir::NFunctionDeclaration>(funcDecl));
      }
#line 1156 "y.tab.c"
break;
case 24:
  if (!yytrial)
#line 187 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1164 "y.tab.c"
break;
case 25:
  if (!yytrial)
#line 190 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement();
      }
#line 1172 "y.tab.c"
break;
case 26:
  if (!yytrial)
#line 196 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1180 "y.tab.c"
break;
case 27:
  if (!yytrial)
#line 199 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NMemberAccess>(dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-3].expr)),
                                                          std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1189 "y.tab.c"
break;
case 28:
  if (!yytrial)
#line 206 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1197 "y.tab.c"
break;
case 29:
  if (!yytrial)
#line 209 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-4].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec), *yyvsp[-3].stringvec);
      }
#line 1205 "y.tab.c"
break;
case 30:
  if (!yytrial)
#line 215 "parser.y"
{
        yyval.stringvec = yyvsp[-1].stringvec;
      }
#line 1213 "y.tab.c"
break;
case 31:
  if (!yytrial)
#line 221 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
      }
#line 1221 "y.tab.c"
break;
case 32:
  if (!yytrial)
#line 224 "parser.y"
{
        yyvsp[-2].stringvec->push_back(yyvsp[0].type->name);
      }
#line 1229 "y.tab.c"
break;
case 33:
  if (!yytrial)
#line 227 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
        yyval.stringvec->push_back(yyvsp[0].type->name);
      }
#line 1238 "y.tab.c"
break;
case 34:
  if (!yytrial)
#line 234 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
      }
#line 1246 "y.tab.c"
break;
case 35:
  if (!yytrial)
#line 237 "parser.y"
{
        yyvsp[-2].exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1254 "y.tab.c"
break;
case 36:
  if (!yytrial)
#line 240 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
        yyval.exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1263 "y.tab.c"
break;
case 37:
  if (!yytrial)
#line 247 "parser.y"
{
        dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-2].expr)->ids.push_back(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier));
      }
#line 1271 "y.tab.c"
break;
case 38:
  if (!yytrial)
#line 250 "parser.y"
{
        yyval.expr = new ddlbx::ir::NMemberAccess(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), {std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier)});
      }
#line 1279 "y.tab.c"
break;
case 39:
  if (!yytrial)
#line 256 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1287 "y.tab.c"
break;
case 40:
  if (!yytrial)
#line 259 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1295 "y.tab.c"
break;
case 41:
  if (!yytrial)
#line 262 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1303 "y.tab.c"
break;
case 42:
  if (!yytrial)
#line 265 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1311 "y.tab.c"
break;
case 43:
  if (!yytrial)
#line 268 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1319 "y.tab.c"
break;
case 44:
  if (!yytrial)
#line 271 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1327 "y.tab.c"
break;
case 45:
  if (!yytrial)
#line 274 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1335 "y.tab.c"
break;
case 46:
  if (!yytrial)
#line 280 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1343 "y.tab.c"
break;
case 47:
  if (!yytrial)
#line 283 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1351 "y.tab.c"
break;
case 48:
  if (!yytrial)
#line 286 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1359 "y.tab.c"
break;
case 52:
  if (!yytrial)
#line 295 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-4].identifier), 
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          nullptr, 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1371 "y.tab.c"
break;
case 53:
  if (!yytrial)
#line 302 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-6].identifier), 
                                          nullptr, 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1383 "y.tab.c"
break;
case 54:
  if (!yytrial)
#line 309 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-8].identifier), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-6].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1395 "y.tab.c"
break;
case 55:
  if (!yytrial)
#line 316 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(nullptr, nullptr, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), nullptr, std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1403 "y.tab.c"
break;
case 56:
  if (!yytrial)
#line 322 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NOptStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1411 "y.tab.c"
break;
case 57:
  if (!yytrial)
#line 328 "parser.y"
{
        yyval.block = yyvsp[-1].block;
      }
#line 1419 "y.tab.c"
break;
case 58:
  if (!yytrial)
#line 334 "parser.y"
{
        yyval.block = new ddlbx::ir::NBlock();
      }
#line 1427 "y.tab.c"
break;
case 59:
  if (!yytrial)
#line 337 "parser.y"
{
        yyvsp[-1].block->statements.push_back(yyvsp[0].stmt);
      }
#line 1435 "y.tab.c"
break;
case 60:
  if (!yytrial)
#line 343 "parser.y"
{
        std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varList = yyvsp[0].varvec;
        yyval.expr = new ddlbx::ir::NVariableDeclarationList(*varList);
      }
#line 1444 "y.tab.c"
break;
case 61:
  if (!yytrial)
#line 350 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1452 "y.tab.c"
break;
case 62:
  if (!yytrial)
#line 353 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1460 "y.tab.c"
break;
case 63:
  if (!yytrial)
#line 356 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1469 "y.tab.c"
break;
case 64:
  if (!yytrial)
#line 360 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1478 "y.tab.c"
break;
case 65:
  if (!yytrial)
#line 367 "parser.y"
{
        yyval.expr = new ddlbx::ir::NAssignment(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-2].identifier), std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1486 "y.tab.c"
break;
case 66:
  if (!yytrial)
#line 373 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1494 "y.tab.c"
break;
case 67:
  if (!yytrial)
#line 376 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1502 "y.tab.c"
break;
case 68:
  if (!yytrial)
#line 379 "parser.y"
{
        yyval.expr = new ddlbx::ir::NUnaryOperator(yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1510 "y.tab.c"
break;
case 69:
  if (!yytrial)
#line 382 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1518 "y.tab.c"
break;
case 70:
  if (!yytrial)
#line 388 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1526 "y.tab.c"
break;
case 71:
  if (!yytrial)
#line 391 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1534 "y.tab.c"
break;
case 72:
  if (!yytrial)
#line 394 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1542 "y.tab.c"
break;
case 73:
  if (!yytrial)
#line 397 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1550 "y.tab.c"
break;
case 74:
  if (!yytrial)
#line 400 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1558 "y.tab.c"
break;
case 75:
  if (!yytrial)
#line 403 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1566 "y.tab.c"
break;
case 76:
  if (!yytrial)
#line 406 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1574 "y.tab.c"
break;
case 77:
  if (!yytrial)
#line 412 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1582 "y.tab.c"
break;
case 78:
  if (!yytrial)
#line 415 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1590 "y.tab.c"
break;
case 79:
  if (!yytrial)
#line 418 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1598 "y.tab.c"
break;
case 80:
  if (!yytrial)
#line 424 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1606 "y.tab.c"
break;
case 81:
  if (!yytrial)
#line 427 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1614 "y.tab.c"
break;
case 82:
  if (!yytrial)
#line 430 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1622 "y.tab.c"
break;
case 83:
  if (!yytrial)
#line 436 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1630 "y.tab.c"
break;
case 84:
  if (!yytrial)
#line 439 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1638 "y.tab.c"
break;
case 85:
  if (!yytrial)
#line 442 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1646 "y.tab.c"
break;
case 86:
  if (!yytrial)
#line 445 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1654 "y.tab.c"
break;
case 87:
  if (!yytrial)
#line 448 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1662 "y.tab.c"
break;
case 88:
  if (!yytrial)
#line 451 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1670 "y.tab.c"
break;
case 89:
  if (!yytrial)
#line 454 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1678 "y.tab.c"
break;
case 90:
  if (!yytrial)
#line 457 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1686 "y.tab.c"
break;
case 91:
  if (!yytrial)
#line 463 "parser.y"
{
        yyval.identifier = new ddlbx::ir::NIdentifier(*(yyvsp[0].string));
        delete yyvsp[0].string;
      }
#line 1695 "y.tab.c"
break;
case 92:
  if (!yytrial)
#line 470 "parser.y"
{
        yyval.expr = new ddlbx::ir::NInteger(atol(yyvsp[0].string->c_str()));
      }
#line 1703 "y.tab.c"
break;
case 93:
  if (!yytrial)
#line 473 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFloat(atof(yyvsp[0].string->c_str()));
      }
#line 1711 "y.tab.c"
break;
case 94:
  if (!yytrial)
#line 479 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBoolean(*yyvsp[0].string);
      }
#line 1719 "y.tab.c"
break;
case 95:
  if (!yytrial)
#line 485 "parser.y"
{
        yyval.expr = new ddlbx::ir::NString(*yyvsp[0].string);
      }
#line 1727 "y.tab.c"
break;
case 96:
  if (!yytrial)
#line 491 "parser.y"
{
        yyval.type = new ddlbx::ir::NType(*yyvsp[0].string);
      }
#line 1735 "y.tab.c"
break;
#line 1737 "y.tab.c"
#line 573 "btyaccpa.ske"

  default:
    break;
  }

#if YYDEBUG && defined(YYDBPR)
  if (yydebug) {
    printf("yydebug[%d]: after reduction, result is ", yytrial);
    YYDBPR(yyps->val);
    printf("\n");
  }
#endif

  // Perform user-defined position reduction
#ifdef YYREDUCEPOSNFUNC
  if(!yytrial) {
    YYCALLREDUCEPOSN(YYREDUCEPOSNFUNCARG);
  }
#endif

  yyps->ssp -= yym;
  yystate = *(yyps->ssp);
  yyps->vsp -= yym;
  yyps->psp -= yym;

  yym = yylhs[yyn];
  if (yystate == 0 && yym == 0) {
#if YYDEBUG
    if (yydebug) {
      printf("yydebug[%d,%d]: after reduction, shifting from state 0 to state %d\n", 
	     yydepth, (int)yytrial, YYFINAL);
    }
#endif
    yystate = YYFINAL;
    *++(yyps->ssp) = YYFINAL;
    *++(yyps->vsp) = yyps->val;
    yyretlval = yyps->val;	// return value of root non-terminal to yylval
    *++(yyps->psp) = yyps->pos;
    yyretposn = yyps->pos;	// return value of root position to yyposn
    if (yychar < 0) {
      if ((yychar = YYLex1()) < 0) {
        yychar = 0;
      }
#if YYDEBUG
      if (yydebug) {
        yys = 0;
        if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
        if (!yys) yys = "illegal-symbol";
        printf("yydebug[%d,%d]: state %d, reading %d (%s)\n", 
	       yydepth, (int)yytrial, YYFINAL, yychar, yys); 
      }
#endif
    }
    if (yychar == 0) goto yyaccept;
    goto yyloop;
  }

  if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
      yyn <= YYTABLESIZE && yycheck[yyn] == yystate) {
    yystate = yytable[yyn];
  } else {
    yystate = yydgoto[yym];
  }
#if YYDEBUG
  if (yydebug)
    printf("yydebug[%d,%d]: after reduction, shifting from state %d to state %d\n",
           yydepth, (int)yytrial, *(yyps->ssp), yystate);
#endif
  if (yyps->ssp >= yyps->ss + yyps->stacksize - 1) {
    YYMoreStack(yyps);
  }
  *++(yyps->ssp) = yystate;
  *++(yyps->vsp) = yyps->val;
  *++(yyps->psp) = yyps->pos;
  goto yyloop;


  //
  // Reduction declares that this path is valid.
  // Set yypath and do a full parse
  //
yyvalid:
  if (yypath) {
    goto yyabort;
  }
  while (yyps->save) {
    yyparsestate *save = yyps->save;
    yyps->save = save->save;
    save->save = yypath;
    yypath = save;
  }
#if YYDEBUG
  if (yydebug)
    printf("yydebug[%d,%d]: CONFLICT trial successful, backtracking to state %d, %d tokens\n",
           yydepth, (int)yytrial, yypath->state, yylvp - yylvals - yypath->lexeme);
#endif
  if(yyerrctx) {
    YYFreeState(yyerrctx); yyerrctx = NULL;
  }
  yychar = -1;
  yyps->ssp = yyps->ss + (yypath->ssp - yypath->ss);
  yyps->vsp = yyps->vs + (yypath->vsp - yypath->vs);
  yyps->psp = yyps->ps + (yypath->psp - yypath->ps);
  memcpy (yyps->ss, yypath->ss, (yyps->ssp - yyps->ss + 1) * sizeof(Yshort));
  YYSCopy(yyps->vs, yypath->vs,  yyps->vsp - yyps->vs + 1);
  YYPCopy(yyps->ps, yypath->ps,  yyps->psp - yyps->ps + 1);
  yylvp = yylvals + yypath->lexeme;
  yylpp = yylpsns + yypath->lexeme;
  yylexp = yylexemes + yypath->lexeme;
  yystate = yypath->state;
  goto yyloop;


yyabort:
  if(yyerrctx) {
    YYFreeState(yyerrctx); yyerrctx = NULL;
  }

  YYSTYPE *pv;
  for(pv=yyps->vs; pv<yyps->vsp; pv++) {
    YYDELETEVAL(*pv,2);
  }

  YYPOSN *pp;
  for(pp=yyps->ps; pp<yyps->psp; pp++) {
    YYDELETEPOSN(*pp,2);
  }

  while (yyps) {
    yyparsestate *save = yyps;
    yyps = save->save;
    YYFreeState(save);
  }
  while (yypath) {
    yyparsestate *save = yypath;
    yypath = save->save;
    YYFreeState(save); 
  }
  return (1);


yyaccept:
  if (yyps->save) goto yyvalid;
  if(yyerrctx) {
    YYFreeState(yyerrctx); yyerrctx = NULL;
  }
  while (yyps) {
    yyparsestate *save = yyps;
    yyps = save->save;
    YYFreeState(save);
  }
  while (yypath) {
    yyparsestate *save = yypath;
    yypath = save->save;
    YYFreeState(save); 
  }
  return (0);
}


int YYLex1() {
  if(yylvp<yylve) {
    yylval = *yylvp++;
    yyposn = *yylpp++;
    return *yylexp++;
  } else {
    if(yyps->save) {
      if(yylvp==yylvlim) {
	yyexpand();
      }
      *yylexp = yylex();
      *yylvp++ = yylval;
      yylve++;
      *yylpp++ = yyposn;
      yylpe++;
      return *yylexp++;
    } else {
      return yylex();
    }
  }
}

int yyexpand() {
  int p = yylvp-yylvals;
  int s = yylvlim-yylvals;
  s += YYSTACKGROWTH;
  { Yshort  *tl = yylexemes; 
    YYSTYPE *tv = yylvals;
    YYPOSN  *tp = yylpsns;
    yylvals = new YYSTYPE[s];
    yylpsns = new YYPOSN[s];
    yylexemes = new Yshort[s];
    memcpy(yylexemes, tl, (s-YYSTACKGROWTH)*sizeof(Yshort));
    YYSCopy(yylvals, tv, s-YYSTACKGROWTH);
    YYPCopy(yylpsns, tp, s-YYSTACKGROWTH);
    delete[] tl;
    delete[] tv;
    delete[] tp;
  }
  yylvp = yylve = yylvals + p;
  yylvlim = yylvals + s;
  yylpp = yylpe = yylpsns + p;
  yylplim = yylpsns + s;
  yylexp = yylexemes + p;
  return 0;
}

void YYSCopy(YYSTYPE *to, YYSTYPE *from, int size) {
  int i;                             
  for (i = size-1; i >= 0; i--) {
    to[i] = from[i];
  }
}

void YYPCopy(YYPOSN *to, YYPOSN *from, int size) {
  int i;                             
  for (i = size-1; i >= 0; i--) {
    to[i] = from[i];
  }
}

void YYMoreStack(yyparsestate *yyps) {
  int p = yyps->ssp - yyps->ss;                               
  Yshort  *tss = yyps->ss;
  YYSTYPE *tvs = yyps->vs;
  YYPOSN  *tps = yyps->ps;
  yyps->ss = new Yshort [yyps->stacksize + YYSTACKGROWTH];   
  yyps->vs = new YYSTYPE[yyps->stacksize + YYSTACKGROWTH];  
  yyps->ps = new YYPOSN [yyps->stacksize + YYSTACKGROWTH];  
  memcpy(yyps->ss, tss, yyps->stacksize * sizeof(Yshort));  
  YYSCopy(yyps->vs, tvs, yyps->stacksize);                  
  YYPCopy(yyps->ps, tps, yyps->stacksize);                  
  yyps->stacksize += YYSTACKGROWTH;                           
  delete[] tss;
  delete[] tvs;
  delete[] tps;
  yyps->ssp = yyps->ss + p;                                   
  yyps->vsp = yyps->vs + p;                                   
  yyps->psp = yyps->ps + p;                                   
}

yyparsestate *YYNewState(int size) {
  yyparsestate *p = new yyparsestate;
  p->stacksize = size+4;
  p->ss = new Yshort [size + 4];
  p->vs = new YYSTYPE[size + 4];
  p->ps = new YYPOSN [size + 4];
  memset(&p->vs[0], 0, (size+4)*sizeof(YYSTYPE));
  memset(&p->ps[0], 0, (size+4)*sizeof(YYPOSN));
  return p;
}

void YYFreeState(yyparsestate *p) {
  delete[] p->ss;
  delete[] p->vs;
  delete[] p->ps;
  delete p;
}
