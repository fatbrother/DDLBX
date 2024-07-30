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
    0,    1,    1,    5,    5,    5,    5,    7,    7,    6,
   29,   29,   29,   24,   11,   11,   34,   33,   33,   33,
   12,   10,   10,   22,   22,   27,   27,   32,   31,   31,
   31,   30,   30,   30,   26,   26,   25,   25,   25,   25,
   25,   25,   25,    4,    4,    4,    4,    4,    4,    9,
    9,    9,    9,    8,    2,    3,    3,   23,   28,   28,
   28,   28,   21,   13,   13,   13,   13,   14,   14,   14,
   14,   14,   14,   14,   15,   15,   15,   16,   16,   16,
   17,   17,   17,   17,   17,   17,   17,   17,   35,   18,
   18,   19,   20,   36,
};
static int yylen[] = {                                         2,
    1,    1,    2,    2,    1,    1,    1,    7,    8,    2,
    0,    3,    1,    3,    5,    6,    3,    0,    3,    1,
   10,    3,    2,    4,    4,    4,    5,    3,    0,    3,
    1,    0,    3,    1,    3,    3,    1,    1,    1,    1,
    3,    1,    1,    2,    2,    2,    1,    1,    1,    7,
    9,   11,    5,    5,    3,    0,    2,    2,    3,    3,
    1,    1,    3,    3,    3,    2,    1,    3,    3,    3,
    3,    3,    3,    1,    1,    3,    3,    1,    3,    3,
    1,    1,    1,    1,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,
};
static int yydefred[] = {                                      0,
    0,    0,    0,    0,    2,    6,    0,    7,    5,    0,
    0,    3,   56,    4,   10,    0,    0,    0,    0,    0,
    0,    0,   94,    0,   31,    0,   13,    0,    0,    0,
    0,    0,   20,    0,   90,   91,    0,   93,   92,    0,
    0,    0,    0,    0,    0,   55,   57,   47,   48,   49,
    0,    0,    0,    0,   78,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   28,    0,    0,    0,    0,
    0,    0,    0,   15,    0,    0,    0,    0,    0,   23,
    0,    0,   89,   61,    0,    0,    0,    0,   66,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   46,   45,    0,    0,    0,    0,   30,
   14,    0,   12,    0,    0,   17,   19,   16,   34,    0,
    0,    0,   22,    0,    0,    0,    0,    0,   64,   65,
    0,    0,    0,    0,    0,    0,    0,    0,   79,   80,
   36,    0,   35,   63,    8,    0,    0,   24,    0,   26,
    0,   60,    0,    0,    0,    0,    0,   25,    0,    9,
   33,   27,   54,   53,    0,    0,    0,    0,    0,    0,
   21,    0,   50,    0,    0,    0,    0,   51,    0,   52,
};
static int yydgoto[] = {                                       3,
    4,   15,   22,   47,    5,    6,    7,   48,   49,   50,
    8,    9,  119,   52,   53,   54,   55,   56,   57,   58,
   59,   60,   61,   27,   62,   63,   64,   85,   28,  120,
   24,   19,   32,   33,   82,   25,
};
static int yysindex[] = {                                   -203,
 -224, -201,    0, -203,    0,    0, -204,    0,    0, -215,
 -260,    0,    0,    0,    0, -196, -190, -184, -183, -170,
 -173, -220,    0, -254,    0, -168,    0, -211, -130, -190,
 -128, -164,    0, -170,    0,    0, -135,    0,    0, -250,
  -74, -115,  -90, -231, -231,    0,    0,    0,    0,    0,
  -82, -265,  274, -172,    0,    0,    0,    0,  -75,    0,
  -68,  -62, -269,    0,  -49,    0, -196, -196,  -52, -190,
 -190, -202,   -9,    0, -170, -117, -231, -231,  -32,    0,
  -25,    0,    0,    0,  -41,  -49, -205, -231,    0,  -12,
    0, -231, -231, -205, -205, -205, -205, -205, -205, -205,
 -205, -205, -205,    0,    0,  -74, -231,  -74, -231,    0,
    0, -196,    0, -193,  -11,    0,    0,    0,    0, -191,
 -111, -231,    0,  -74,   -8,    3, -148,    0,    0,    0,
 -125, -125, -125, -125, -125, -125, -172, -172,    0,    0,
    0, -186,    0,    0,    0,    8, -196,    0, -231,    0,
  -92,    0,  -49,   16,   16, -231, -231,    0, -196,    0,
    0,    0,    0,    0,   11, -267,   16, -231,   16, -231,
    0,   19,    0,   38, -231,   16,   42,    0,   16,    0,
};
static int yyrindex[] = {                                      0,
    0,    0,    0,  327,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -214, -185,    0,    0,  -86,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -185,
    0,    0,    0,  -86,    0,    0, -161,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  249, -147,   87,    0, -114,  -89,  -63,    0,  -38,
    0,    0,   62,  -13,  162,    0,    0,    0,    0,    0,
 -185,    0,    0,    0,    0,    0, -146,  -66,    0,    0,
    0,   12,    0,    0,   50,  -43,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -146,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -66,    0,    0,    0,    0,  184,   37,    0,    0,
  189,  199,  209,  219,  229,  239,  112,  137,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -18,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static int yycindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   71,    0,    0,    0,
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
};
static int yygindex[] = {                                      0,
    0,  -76,    0,    0,  340,    0,    0,    0,    0,    0,
    0,    0,  -22,  259,  457,  193,  216,    0,    0,    0,
  -40,    0,    0,  280,    0,    0,    0,    0,  -24,  -73,
    0,    6,  317,  277,  -20,  -64,
};
#define YYTABLESIZE 556
static int yytable[] = {                                      51,
   84,   65,  110,  111,  121,   72,   35,   36,   37,   38,
   39,   16,  107,   92,   93,  169,   21,   81,   66,  108,
   86,   89,   90,   20,  170,   35,   36,   37,   38,   39,
   44,   45,   67,  142,   10,   80,   35,   36,   37,   38,
   39,   40,   79,   41,   42,   43,  114,  145,  151,   44,
   45,   35,   36,   37,   38,   39,   16,   11,   29,    1,
   44,   45,   23,    2,   46,  126,   17,  127,   26,  129,
  130,   69,   29,   18,   29,   70,   45,  163,  164,   13,
  115,   14,  160,  152,   70,  141,  144,  143,   31,  146,
  171,  148,  173,   70,  167,  149,  158,   11,   30,  178,
  149,   11,  180,  153,  102,  103,   89,   89,   89,   89,
   34,   89,   89,   89,   89,   89,   89,   89,   89,   68,
   74,   89,   75,   89,   89,   89,  161,   89,   89,   89,
   89,   74,   74,  165,  166,   74,   32,   74,   74,   74,
   32,  156,  157,   74,   74,  172,   77,  174,   78,  100,
  101,   71,  177,   82,   82,   82,   82,   82,   82,   73,
   82,   82,   82,   82,   82,   82,   87,  118,   82,   75,
   82,   82,   82,  150,   38,  149,   82,   82,   83,   83,
   83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
   83,   88,  162,   83,  149,   83,   83,   83,   18,   39,
   18,   83,   83,   91,   84,   84,   84,   84,   84,   84,
  104,   84,   84,   84,   84,   84,   84,  105,   32,   84,
   32,   84,   84,   84,  109,   40,  106,   84,   84,   86,
   86,   86,   86,   86,   86,  112,   86,   86,   86,   86,
   86,   86,   62,   62,   86,  124,   86,   86,   86,  116,
   42,  122,   86,   86,   87,   87,   87,   87,   87,   87,
  123,   87,   87,   87,   87,   87,   87,   59,   59,   87,
  128,   87,   87,   87,  154,   43,  147,   87,   87,   81,
   81,   81,   81,   81,   81,  155,   81,   81,   81,   81,
   81,   81,  137,  138,   81,  159,   81,   81,   81,   13,
   37,  168,   81,   81,   85,   85,   85,   85,   85,   85,
  175,   85,   85,   85,   85,   85,   85,  139,  140,   85,
  176,   85,   85,   85,  179,   41,    1,   85,   85,   88,
   88,   88,   88,   88,   88,   58,   88,   88,   88,   88,
   88,   88,    0,   12,   88,  125,   88,   88,   88,  113,
   76,  117,   88,   88,   75,   75,   75,   75,   75,   75,
    0,   75,   75,    0,    0,   75,   75,    0,    0,   75,
    0,   75,   75,   75,    0,    0,    0,   75,   75,   76,
   76,   76,   76,   76,   76,    0,   76,   76,    0,    0,
   76,   76,    0,    0,   76,    0,   76,   76,   76,    0,
    0,    0,   76,   76,   77,   77,   77,   77,   77,   77,
    0,   77,   77,    0,    0,   77,   77,    0,    0,   77,
    0,   77,   77,   77,    0,    0,    0,   77,   77,   81,
   81,   81,   81,   81,   81,    0,   81,   81,   81,   81,
   81,   81,    0,    0,    0,    0,    0,   81,    0,    0,
   37,   81,   81,   81,   81,   81,   81,    0,   81,   81,
   81,   81,   81,   81,    0,    0,   81,   70,   70,    0,
    0,   70,   37,   70,   70,   70,    0,   73,   73,   70,
   70,   73,    0,   73,   73,   73,    0,   71,   71,   73,
   73,   71,    0,   71,   71,   71,    0,   72,   72,   71,
   71,   72,    0,   72,   72,   72,    0,   68,   68,   72,
   72,   68,    0,   68,   68,   68,    0,   69,   69,   68,
   68,   69,    0,   69,   69,   69,    0,    0,    0,   69,
   69,   67,    0,   67,   67,   67,    0,    0,    0,   67,
   67,   94,   95,   96,   97,   98,   99,    0,  100,  101,
  131,  132,  133,  134,  135,  136,
};
static int yycheck[] = {                                      22,
   41,   22,   67,   68,   78,   30,  257,  258,  259,  260,
  261,  272,  282,  279,  280,  283,   11,   40,  273,  289,
   41,   44,   45,  284,  292,  257,  258,  259,  260,  261,
  281,  282,  287,  107,  259,  286,  257,  258,  259,  260,
  261,  262,   37,  264,  265,  266,   71,  112,  122,  281,
  282,  257,  258,  259,  260,  261,  272,  259,  273,  263,
  281,  282,  259,  267,  285,   88,  282,   88,  259,   92,
   93,  283,  287,  289,  259,  287,  282,  154,  155,  284,
  283,  286,  147,  124,  287,  106,  109,  108,  259,  283,
  167,  283,  169,  287,  159,  287,  283,  283,  282,  176,
  287,  287,  179,  124,  277,  278,  268,  269,  270,  271,
  284,  273,  274,  275,  276,  277,  278,  279,  280,  288,
  285,  283,  287,  285,  286,  287,  149,  289,  290,  291,
  292,  279,  280,  156,  157,  283,  283,  285,  286,  287,
  287,  290,  291,  291,  292,  168,  282,  170,  284,  275,
  276,  282,  175,  268,  269,  270,  271,  272,  273,  288,
  275,  276,  277,  278,  279,  280,  282,  285,  283,  287,
  285,  286,  287,  285,  289,  287,  291,  292,  268,  269,
  270,  271,  272,  273,  259,  275,  276,  277,  278,  279,
  280,  282,  285,  283,  287,  285,  286,  287,  285,  289,
  287,  291,  292,  286,  268,  269,  270,  271,  272,  273,
  286,  275,  276,  277,  278,  279,  280,  286,  285,  283,
  287,  285,  286,  287,  274,  289,  289,  291,  292,  268,
  269,  270,  271,  272,  273,  288,  275,  276,  277,  278,
  279,  280,  286,  287,  283,  287,  285,  286,  287,  259,
  289,  284,  291,  292,  268,  269,  270,  271,  272,  273,
  286,  275,  276,  277,  278,  279,  280,  286,  287,  283,
  283,  285,  286,  287,  283,  289,  288,  291,  292,  268,
  269,  270,  271,  272,  273,  283,  275,  276,  277,  278,
  279,  280,  100,  101,  283,  288,  285,  286,  287,  284,
  289,  291,  291,  292,  268,  269,  270,  271,  272,  273,
  292,  275,  276,  277,  278,  279,  280,  102,  103,  283,
  283,  285,  286,  287,  283,  289,    0,  291,  292,  268,
  269,  270,  271,  272,  273,  286,  275,  276,  277,  278,
  279,  280,  272,    4,  283,   87,  285,  286,  287,   70,
   34,   75,  291,  292,  268,  269,  270,  271,  272,  273,
   -1,  275,  276,   -1,   -1,  279,  280,   -1,   -1,  283,
   -1,  285,  286,  287,   -1,   -1,   -1,  291,  292,  268,
  269,  270,  271,  272,  273,   -1,  275,  276,   -1,   -1,
  279,  280,   -1,   -1,  283,   -1,  285,  286,  287,   -1,
   -1,   -1,  291,  292,  268,  269,  270,  271,  272,  273,
   -1,  275,  276,   -1,   -1,  279,  280,   -1,   -1,  283,
   -1,  285,  286,  287,   -1,   -1,   -1,  291,  292,  268,
  269,  270,  271,  272,  273,   -1,  275,  276,  277,  278,
  279,  280,   -1,   -1,   -1,   -1,   -1,  286,   -1,   -1,
  289,  268,  269,  270,  271,  272,  273,   -1,  275,  276,
  277,  278,  279,  280,   -1,   -1,  283,  279,  280,   -1,
   -1,  283,  289,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,   -1,   -1,  291,
  292,  283,   -1,  285,  286,  287,   -1,   -1,   -1,  291,
  292,  268,  269,  270,  271,  272,  273,   -1,  275,  276,
   94,   95,   96,   97,   98,   99,
};
static int yyctable[] = {                                     16,
   89,   -1,
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


#line 485 "parser.y"
  

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
#line 591 "y.tab.c"
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
#line 987 "y.tab.c"
break;
case 2:
  if (!yytrial)
#line 82 "parser.y"
{
        yyval.stmtvec = new std::vector<std::shared_ptr<ddlbx::ir::NStatement>>();
        yyval.stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 996 "y.tab.c"
break;
case 3:
  if (!yytrial)
#line 86 "parser.y"
{
        yyvsp[-1].stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1004 "y.tab.c"
break;
case 4:
  if (!yytrial)
#line 92 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1012 "y.tab.c"
break;
case 8:
  if (!yytrial)
#line 101 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), 
                                                *yyvsp[-5].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)));
      }
#line 1022 "y.tab.c"
break;
case 9:
  if (!yytrial)
#line 106 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), 
                                                *yyvsp[-6].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)),
                                                *yyvsp[-5].stringvec);
      }
#line 1033 "y.tab.c"
break;
case 10:
  if (!yytrial)
#line 115 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>(yyvsp[-1].stmt)),
                                                 std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1042 "y.tab.c"
break;
case 11:
  if (!yytrial)
#line 122 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
      }
#line 1050 "y.tab.c"
break;
case 12:
  if (!yytrial)
#line 125 "parser.y"
{
        yyvsp[-2].argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1058 "y.tab.c"
break;
case 13:
  if (!yytrial)
#line 128 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
        yyval.argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1067 "y.tab.c"
break;
case 14:
  if (!yytrial)
#line 135 "parser.y"
{
        yyval.expr = new ddlbx::ir::NArgument(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), *yyvsp[-2].string);
      }
#line 1075 "y.tab.c"
break;
case 15:
  if (!yytrial)
#line 141 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NObjectDeclaration(*yyvsp[-3].string, *yyvsp[-1].membervec);
      }
#line 1083 "y.tab.c"
break;
case 16:
  if (!yytrial)
#line 144 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateObjectDeclaration(*yyvsp[-4].string, *yyvsp[-1].membervec, *yyvsp[-3].stringvec);
      }
#line 1091 "y.tab.c"
break;
case 17:
  if (!yytrial)
#line 149 "parser.y"
{
        yyval.member = new ddlbx::ir::NMemberDeclaration(std::make_shared<ddlbx::ir::NType>(*yyvsp[0].string), *yyvsp[-2].string);
      }
#line 1099 "y.tab.c"
break;
case 18:
  if (!yytrial)
#line 155 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
      }
#line 1107 "y.tab.c"
break;
case 19:
  if (!yytrial)
#line 158 "parser.y"
{
        yyvsp[-2].membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1115 "y.tab.c"
break;
case 20:
  if (!yytrial)
#line 161 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
        yyval.membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1124 "y.tab.c"
break;
case 21:
  if (!yytrial)
#line 168 "parser.y"
{
        ddlbx::ir::NFunctionDefinition *funcDef = new ddlbx::ir::NFunctionDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[-1].type), *yyvsp[-6].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-4].argvec)));
        ddlbx::ir::NFunctionDeclaration *funcDecl = new ddlbx::ir::NFunctionDeclaration(
            std::shared_ptr<ddlbx::ir::NFunctionDefinition>(funcDef), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
        yyval.stmt = new ddlbx::ir::NMethodDeclaration(*yyvsp[-8].string, std::shared_ptr<ddlbx::ir::NFunctionDeclaration>(funcDecl));
      }
#line 1136 "y.tab.c"
break;
case 22:
  if (!yytrial)
#line 177 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1144 "y.tab.c"
break;
case 23:
  if (!yytrial)
#line 180 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement();
      }
#line 1152 "y.tab.c"
break;
case 24:
  if (!yytrial)
#line 186 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1160 "y.tab.c"
break;
case 25:
  if (!yytrial)
#line 189 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NMemberAccess>(dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-3].expr)),
                                                          std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1169 "y.tab.c"
break;
case 26:
  if (!yytrial)
#line 196 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1177 "y.tab.c"
break;
case 27:
  if (!yytrial)
#line 199 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-4].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec), *yyvsp[-3].stringvec);
      }
#line 1185 "y.tab.c"
break;
case 28:
  if (!yytrial)
#line 205 "parser.y"
{
        yyval.stringvec = yyvsp[-1].stringvec;
      }
#line 1193 "y.tab.c"
break;
case 29:
  if (!yytrial)
#line 211 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
      }
#line 1201 "y.tab.c"
break;
case 30:
  if (!yytrial)
#line 214 "parser.y"
{
        yyvsp[-2].stringvec->push_back(yyvsp[0].type->name);
      }
#line 1209 "y.tab.c"
break;
case 31:
  if (!yytrial)
#line 217 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
        yyval.stringvec->push_back(yyvsp[0].type->name);
      }
#line 1218 "y.tab.c"
break;
case 32:
  if (!yytrial)
#line 224 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
      }
#line 1226 "y.tab.c"
break;
case 33:
  if (!yytrial)
#line 227 "parser.y"
{
        yyvsp[-2].exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1234 "y.tab.c"
break;
case 34:
  if (!yytrial)
#line 230 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
        yyval.exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1243 "y.tab.c"
break;
case 35:
  if (!yytrial)
#line 237 "parser.y"
{
        dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-2].expr)->ids.push_back(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier));
      }
#line 1251 "y.tab.c"
break;
case 36:
  if (!yytrial)
#line 240 "parser.y"
{
        yyval.expr = new ddlbx::ir::NMemberAccess(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), {std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier)});
      }
#line 1259 "y.tab.c"
break;
case 37:
  if (!yytrial)
#line 246 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1267 "y.tab.c"
break;
case 38:
  if (!yytrial)
#line 249 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1275 "y.tab.c"
break;
case 39:
  if (!yytrial)
#line 252 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1283 "y.tab.c"
break;
case 40:
  if (!yytrial)
#line 255 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1291 "y.tab.c"
break;
case 41:
  if (!yytrial)
#line 258 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1299 "y.tab.c"
break;
case 42:
  if (!yytrial)
#line 261 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1307 "y.tab.c"
break;
case 43:
  if (!yytrial)
#line 264 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1315 "y.tab.c"
break;
case 44:
  if (!yytrial)
#line 270 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1323 "y.tab.c"
break;
case 45:
  if (!yytrial)
#line 273 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1331 "y.tab.c"
break;
case 46:
  if (!yytrial)
#line 276 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1339 "y.tab.c"
break;
case 50:
  if (!yytrial)
#line 285 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-4].identifier), 
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          nullptr, 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1351 "y.tab.c"
break;
case 51:
  if (!yytrial)
#line 292 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-6].identifier), 
                                          nullptr, 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1363 "y.tab.c"
break;
case 52:
  if (!yytrial)
#line 299 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-8].identifier), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-6].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1375 "y.tab.c"
break;
case 53:
  if (!yytrial)
#line 306 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(nullptr, nullptr, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), nullptr, std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1383 "y.tab.c"
break;
case 54:
  if (!yytrial)
#line 312 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NOptStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1391 "y.tab.c"
break;
case 55:
  if (!yytrial)
#line 318 "parser.y"
{
        yyval.block = yyvsp[-1].block;
      }
#line 1399 "y.tab.c"
break;
case 56:
  if (!yytrial)
#line 324 "parser.y"
{
        yyval.block = new ddlbx::ir::NBlock();
      }
#line 1407 "y.tab.c"
break;
case 57:
  if (!yytrial)
#line 327 "parser.y"
{
        yyvsp[-1].block->statements.push_back(yyvsp[0].stmt);
      }
#line 1415 "y.tab.c"
break;
case 58:
  if (!yytrial)
#line 333 "parser.y"
{
        std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varList = yyvsp[0].varvec;
        yyval.expr = new ddlbx::ir::NVariableDeclarationList(*varList);
      }
#line 1424 "y.tab.c"
break;
case 59:
  if (!yytrial)
#line 340 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1432 "y.tab.c"
break;
case 60:
  if (!yytrial)
#line 343 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1440 "y.tab.c"
break;
case 61:
  if (!yytrial)
#line 346 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1449 "y.tab.c"
break;
case 62:
  if (!yytrial)
#line 350 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1458 "y.tab.c"
break;
case 63:
  if (!yytrial)
#line 357 "parser.y"
{
        yyval.expr = new ddlbx::ir::NAssignment(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-2].identifier), std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1466 "y.tab.c"
break;
case 64:
  if (!yytrial)
#line 363 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1474 "y.tab.c"
break;
case 65:
  if (!yytrial)
#line 366 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1482 "y.tab.c"
break;
case 66:
  if (!yytrial)
#line 369 "parser.y"
{
        yyval.expr = new ddlbx::ir::NUnaryOperator(yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1490 "y.tab.c"
break;
case 67:
  if (!yytrial)
#line 372 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1498 "y.tab.c"
break;
case 68:
  if (!yytrial)
#line 378 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1506 "y.tab.c"
break;
case 69:
  if (!yytrial)
#line 381 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1514 "y.tab.c"
break;
case 70:
  if (!yytrial)
#line 384 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1522 "y.tab.c"
break;
case 71:
  if (!yytrial)
#line 387 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1530 "y.tab.c"
break;
case 72:
  if (!yytrial)
#line 390 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1538 "y.tab.c"
break;
case 73:
  if (!yytrial)
#line 393 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1546 "y.tab.c"
break;
case 74:
  if (!yytrial)
#line 396 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1554 "y.tab.c"
break;
case 75:
  if (!yytrial)
#line 402 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1562 "y.tab.c"
break;
case 76:
  if (!yytrial)
#line 405 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1570 "y.tab.c"
break;
case 77:
  if (!yytrial)
#line 408 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1578 "y.tab.c"
break;
case 78:
  if (!yytrial)
#line 414 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1586 "y.tab.c"
break;
case 79:
  if (!yytrial)
#line 417 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1594 "y.tab.c"
break;
case 80:
  if (!yytrial)
#line 420 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1602 "y.tab.c"
break;
case 81:
  if (!yytrial)
#line 426 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1610 "y.tab.c"
break;
case 82:
  if (!yytrial)
#line 429 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1618 "y.tab.c"
break;
case 83:
  if (!yytrial)
#line 432 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1626 "y.tab.c"
break;
case 84:
  if (!yytrial)
#line 435 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1634 "y.tab.c"
break;
case 85:
  if (!yytrial)
#line 438 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1642 "y.tab.c"
break;
case 86:
  if (!yytrial)
#line 441 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1650 "y.tab.c"
break;
case 87:
  if (!yytrial)
#line 444 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1658 "y.tab.c"
break;
case 88:
  if (!yytrial)
#line 447 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1666 "y.tab.c"
break;
case 89:
  if (!yytrial)
#line 453 "parser.y"
{
        yyval.identifier = new ddlbx::ir::NIdentifier(*(yyvsp[0].string));
        delete yyvsp[0].string;
      }
#line 1675 "y.tab.c"
break;
case 90:
  if (!yytrial)
#line 460 "parser.y"
{
        yyval.expr = new ddlbx::ir::NInteger(atol(yyvsp[0].string->c_str()));
      }
#line 1683 "y.tab.c"
break;
case 91:
  if (!yytrial)
#line 463 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFloat(atof(yyvsp[0].string->c_str()));
      }
#line 1691 "y.tab.c"
break;
case 92:
  if (!yytrial)
#line 469 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBoolean(*yyvsp[0].string);
      }
#line 1699 "y.tab.c"
break;
case 93:
  if (!yytrial)
#line 475 "parser.y"
{
        yyval.expr = new ddlbx::ir::NString(*yyvsp[0].string);
      }
#line 1707 "y.tab.c"
break;
case 94:
  if (!yytrial)
#line 481 "parser.y"
{
        yyval.type = new ddlbx::ir::NType(*yyvsp[0].string);
      }
#line 1715 "y.tab.c"
break;
#line 1717 "y.tab.c"
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
