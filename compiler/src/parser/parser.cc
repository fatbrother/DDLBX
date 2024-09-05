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
    0,    1,    1,    5,    5,    5,    5,    5,    7,   14,
    6,    6,   31,   31,   31,   26,   11,   11,   36,   35,
   35,   35,   12,   13,   10,   10,   24,   24,   24,   29,
   29,   34,   33,   33,   33,   32,   32,   32,   28,   28,
   27,   27,   27,   27,   27,   27,   27,    4,    4,    4,
    4,    4,    4,    9,    9,    9,    9,    8,    2,    3,
    3,   25,   30,   30,   30,   30,   23,   15,   15,   15,
   15,   16,   16,   16,   16,   16,   16,   16,   17,   17,
   17,   18,   18,   18,   19,   19,   19,   19,   19,   19,
   19,   19,   37,   20,   20,   21,   22,   38,
};
static int yylen[] = {                                         2,
    1,    1,    2,    2,    1,    1,    1,    1,    7,    8,
    2,    2,    0,    3,    1,    3,    5,    6,    3,    0,
    3,    1,   10,   12,    3,    2,    4,    5,    4,    4,
    5,    3,    0,    3,    1,    0,    3,    1,    3,    3,
    1,    1,    1,    1,    3,    1,    1,    2,    2,    2,
    1,    1,    1,    7,    9,   11,    5,    5,    3,    0,
    2,    2,    3,    3,    1,    1,    3,    3,    3,    2,
    1,    3,    3,    3,    3,    3,    3,    1,    1,    3,
    3,    1,    3,    3,    1,    1,    1,    1,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
};
static int yydefred[] = {                                      0,
    0,    0,    0,    0,    2,    6,    0,    7,    5,    8,
    0,    0,    0,    0,    3,   60,    4,   11,   12,    0,
    0,    0,    0,    0,    0,   22,    0,    0,    0,   98,
    0,   35,    0,   15,    0,    0,    0,    0,    0,    0,
    0,    0,   94,   95,    0,   97,   96,    0,    0,    0,
    0,    0,    0,   59,   61,   51,   52,   53,    0,    0,
    0,    0,   82,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   32,    0,    0,    0,    0,    0,    0,
   19,    0,   21,   17,    0,    0,    0,    0,   26,    0,
    0,   93,   65,    0,    0,    0,    0,   70,    0,   48,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   50,   49,    0,    0,    0,    0,   34,   16,
    0,   14,    0,    0,    0,   18,   38,    0,    0,    0,
    0,   25,    0,    0,    0,    0,    0,   68,   69,    0,
    0,    0,    0,    0,    0,    0,    0,   83,   84,   40,
    0,   39,   67,    9,    0,    0,    0,   27,    0,   30,
    0,    0,   64,    0,    0,    0,    0,    0,   29,    0,
   10,    0,   37,   28,   31,   58,   57,    0,    0,    0,
    0,    0,    0,    0,   23,    0,    0,   54,    0,    0,
    0,    0,   24,    0,   55,    0,   56,
};
static int yydgoto[] = {                                       3,
    4,   18,   29,   55,    5,    6,    7,   56,   57,   58,
    8,    9,   10,   11,  127,   60,   61,   62,   63,   64,
   65,   66,   67,   68,   69,   34,   70,   71,   72,   94,
   35,  128,   31,   23,   25,   26,   91,   32,
};
static int yysindex[] = {                                   -231,
 -253, -226,    0, -231,    0,    0, -140,    0,    0,    0,
 -218, -210, -158, -191,    0,    0,    0,    0,    0, -153,
 -150, -137, -208, -148, -222,    0, -158, -127, -241,    0,
 -245,    0, -145,    0, -223, -114, -150,  -75,  -99, -158,
 -138, -158,    0,    0, -132,    0,    0, -247,  -53, -102,
  -83, -212, -212,    0,    0,    0,    0,    0,  -69, -154,
  274,   -2,    0,    0,    0,    0,  -62,    0,  -44,  -40,
 -221,    0,  -18,    0, -153, -153,  -30, -150, -150, -196,
    0,    2,    0,    0, -134, -212, -212,  -51,    0,   -8,
    0,    0,    0,  -19,  -18, -204, -212,    0,   -1,    0,
 -212, -212, -204, -204, -204, -204, -204, -204, -204, -204,
 -204, -204,    0,    0,  -53, -212,  -53, -212,    0,    0,
 -153,    0, -193,   -4,   11,    0,    0, -187, -112, -212,
 -212,    0,  -53,   20,   24,   10,    0,    0,    0,   50,
   50,   50,   50,   50,   50,   -2,   -2,    0,    0,    0,
 -185,    0,    0,    0,   21, -153, -150,    0, -212,    0,
 -180,  -85,    0,  -18, -218, -218, -212, -212,    0, -153,
    0, -169,    0,    0,    0,    0,    0,   27, -225, -218,
   40, -212, -218, -212,    0, -153,   42,    0,   49, -218,
 -212, -218,    0,   60,    0, -218,    0,
};
static int yyrindex[] = {                                      0,
    0,    0,    0,  353,    0,    0,    0,    0,    0,    0,
    0,    0,  -60,    0,    0,    0,    0,    0,    0, -214,
 -164,    0,    0,    0,    0,    0,  -60,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -164,    0,    0,    0,
    0,  -60,    0,    0,  -82,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -203,
 -175, -109,    0,  -57,  -32,   -6,    0,   19,    0,    0,
  119,   44, -141,    0,    0,    0,    0,    0, -164,    0,
    0,    0,    0,    0,    0, -163,  -35,    0,    0,    0,
   69,    0,    0,   71,   64,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -163,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -163,
  -35,    0,    0,    0,    0,  194,   94,    0,    0,  199,
  209,  219,  229,  239,  249,  144,  169,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -164,    0,    0,    0,
    0,    0,    0,   89,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static int yycindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   87,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,
};
static int yygindex[] = {                                      0,
    0,  -11,    0,    0,  364,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -26,  282,  448,  291,  296,    0,
    0,    0,  -47,    0,    0,  304,    0,    0,    0,    0,
  -36,  -79,    0,   -7,  -12,  344,  -20,  -71,
};
#define YYTABLESIZE 556
static int yytable[] = {                                      19,
   80,   93,   59,  119,  120,   12,   28,  129,   73,   43,
   44,   45,   46,   47,   41,   43,   44,   45,   46,   47,
   48,   90,   49,   50,   51,   98,   99,   74,   95,   85,
   13,    1,   14,   52,   53,    2,  151,   88,   89,   52,
   53,   75,  123,   54,   43,   44,   45,   46,   47,  154,
  161,  162,   43,   44,   45,   46,   47,  183,   33,   77,
  116,   20,   39,   78,   40,   16,  184,  117,   52,   53,
  135,   21,   33,   37,  138,  139,  136,   53,   22,   71,
   20,   71,   71,   71,  171,  163,  124,   71,   71,  155,
   78,  153,   27,   78,  150,  158,  152,  169,  180,  159,
   24,  159,  174,   78,   78,   30,  159,   78,   33,   78,
   78,   78,  164,  181,  190,   78,   78,   78,   13,   36,
  172,   36,   13,   36,  101,  102,   85,   85,   85,   85,
   85,   85,  173,   85,   85,   85,   85,   85,   85,   38,
  178,  179,   76,   16,   85,   17,   84,   41,   40,   86,
  126,   87,   40,  176,  177,  187,   42,  189,   79,   79,
   79,   79,   79,   79,  194,   79,   79,   79,  185,   79,
   79,  188,  160,   79,  159,   79,   79,   79,  193,   96,
  195,   79,   79,   81,  197,   93,   93,   93,   93,   82,
   93,   93,   93,   93,   93,   93,   93,   93,   97,  175,
   93,  159,   93,   93,   93,   92,   93,   93,   93,   93,
   86,   86,   86,   86,   86,   86,  100,   86,   86,   86,
   86,   86,   86,  113,   20,   86,   20,   86,   86,   86,
  130,   42,  131,   86,   86,   87,   87,   87,   87,   87,
   87,  114,   87,   87,   87,   87,   87,   87,  115,   36,
   87,   36,   87,   87,   87,  118,   43,  121,   87,   87,
  125,   88,   88,   88,   88,   88,   88,  133,   88,   88,
   88,   88,   88,   88,  111,  112,   88,  132,   88,   88,
   88,  137,   44,  156,   88,   88,   90,   90,   90,   90,
   90,   90,  157,   90,   90,   90,   90,   90,   90,  167,
  168,   90,  165,   90,   90,   90,  166,   46,  170,   90,
   90,   91,   91,   91,   91,   91,   91,  182,   91,   91,
   91,   91,   91,   91,  109,  110,   91,  186,   91,   91,
   91,  192,   47,  191,   91,   91,   85,   85,   85,   85,
   85,   85,  196,   85,   85,   85,   85,   85,   85,   66,
   66,   85,    1,   85,   85,   85,   62,   41,    0,   85,
   85,   89,   89,   89,   89,   89,   89,   15,   89,   89,
   89,   89,   89,   89,   63,   63,   89,  134,   89,   89,
   89,  122,   45,   83,   89,   89,   92,   92,   92,   92,
   92,   92,    0,   92,   92,   92,   92,   92,   92,  146,
  147,   92,    0,   92,   92,   92,  148,  149,    0,   92,
   92,   80,   80,   80,   80,   80,   80,    0,   80,   80,
    0,    0,   80,   80,    0,    0,   80,    0,   80,   80,
   80,    0,    0,    0,   80,   80,   81,   81,   81,   81,
   81,   81,    0,   81,   81,    0,    0,   81,   81,    0,
    0,   81,    0,   81,   81,   81,    0,    0,    0,   81,
   81,   85,   85,   85,   85,   85,   85,    0,   85,   85,
   85,   85,   85,   85,    0,    0,   85,   74,   74,    0,
    0,   74,   41,   74,   74,   74,    0,   77,   77,   74,
   74,   77,    0,   77,   77,   77,    0,   75,   75,   77,
   77,   75,    0,   75,   75,   75,    0,   76,   76,   75,
   75,   76,    0,   76,   76,   76,    0,   72,   72,   76,
   76,   72,    0,   72,   72,   72,    0,   73,   73,   72,
   72,   73,    0,   73,   73,   73,    0,    0,    0,   73,
   73,  103,  104,  105,  106,  107,  108,    0,  109,  110,
  140,  141,  142,  143,  144,  145,
};
static int yycheck[] = {                                      11,
   37,   49,   29,   75,   76,  259,   14,   87,   29,  257,
  258,  259,  260,  261,   27,  257,  258,  259,  260,  261,
  262,   48,  264,  265,  266,   52,   53,  273,   49,   42,
  284,  263,  259,  281,  282,  267,  116,   45,  286,  281,
  282,  287,   79,  285,  257,  258,  259,  260,  261,  121,
  130,  131,  257,  258,  259,  260,  261,  283,  273,  283,
  282,  272,  285,  287,  287,  284,  292,  289,  281,  282,
   97,  282,  287,  282,  101,  102,   97,  282,  289,  283,
  272,  285,  286,  287,  156,  133,  283,  291,  292,  283,
  287,  118,  284,  287,  115,  283,  117,  283,  170,  287,
  259,  287,  283,  279,  280,  259,  287,  283,  259,  285,
  286,  287,  133,  283,  186,  291,  292,  287,  283,  283,
  157,  259,  287,  287,  279,  280,  268,  269,  270,  271,
  272,  273,  159,  275,  276,  277,  278,  279,  280,  288,
  167,  168,  288,  284,  286,  286,  285,  289,  287,  282,
  285,  284,  287,  165,  166,  182,  284,  184,  268,  269,
  270,  271,  272,  273,  191,  275,  276,  282,  180,  279,
  280,  183,  285,  283,  287,  285,  286,  287,  190,  282,
  192,  291,  292,  259,  196,  268,  269,  270,  271,  289,
  273,  274,  275,  276,  277,  278,  279,  280,  282,  285,
  283,  287,  285,  286,  287,  259,  289,  290,  291,  292,
  268,  269,  270,  271,  272,  273,  286,  275,  276,  277,
  278,  279,  280,  286,  285,  283,  287,  285,  286,  287,
  282,  289,  284,  291,  292,  268,  269,  270,  271,  272,
  273,  286,  275,  276,  277,  278,  279,  280,  289,  285,
  283,  287,  285,  286,  287,  274,  289,  288,  291,  292,
  259,  268,  269,  270,  271,  272,  273,  287,  275,  276,
  277,  278,  279,  280,  277,  278,  283,  286,  285,  286,
  287,  283,  289,  288,  291,  292,  268,  269,  270,  271,
  272,  273,  282,  275,  276,  277,  278,  279,  280,  290,
  291,  283,  283,  285,  286,  287,  283,  289,  288,  291,
  292,  268,  269,  270,  271,  272,  273,  291,  275,  276,
  277,  278,  279,  280,  275,  276,  283,  288,  285,  286,
  287,  283,  289,  292,  291,  292,  268,  269,  270,  271,
  272,  273,  283,  275,  276,  277,  278,  279,  280,  286,
  287,  283,    0,  285,  286,  287,  286,  289,  272,  291,
  292,  268,  269,  270,  271,  272,  273,    4,  275,  276,
  277,  278,  279,  280,  286,  287,  283,   96,  285,  286,
  287,   78,  289,   40,  291,  292,  268,  269,  270,  271,
  272,  273,   -1,  275,  276,  277,  278,  279,  280,  109,
  110,  283,   -1,  285,  286,  287,  111,  112,   -1,  291,
  292,  268,  269,  270,  271,  272,  273,   -1,  275,  276,
   -1,   -1,  279,  280,   -1,   -1,  283,   -1,  285,  286,
  287,   -1,   -1,   -1,  291,  292,  268,  269,  270,  271,
  272,  273,   -1,  275,  276,   -1,   -1,  279,  280,   -1,
   -1,  283,   -1,  285,  286,  287,   -1,   -1,   -1,  291,
  292,  268,  269,  270,  271,  272,  273,   -1,  275,  276,
  277,  278,  279,  280,   -1,   -1,  283,  279,  280,   -1,
   -1,  283,  289,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,  279,  280,  291,
  292,  283,   -1,  285,  286,  287,   -1,   -1,   -1,  291,
  292,  268,  269,  270,  271,  272,  273,   -1,  275,  276,
  103,  104,  105,  106,  107,  108,
};
static int yyctable[] = {                                     20,
   93,   -1,
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
"TemplateFunctionDefinition : KW_FUNCTION IDENTIFIER TemplateDeclaration LPAREN FPDeclarationList RPAREN COLON Type",
"FunctionDeclaration : FunctionDefinition Block",
"FunctionDeclaration : TemplateFunctionDefinition Block",
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
"FunctionCallExpression : IDENTIFIER TemplateDeclaration LPAREN FCParameterList RPAREN",
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


#line 505 "parser.y"
  

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
#line 603 "y.tab.c"
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
#line 999 "y.tab.c"
break;
case 2:
  if (!yytrial)
#line 82 "parser.y"
{
        yyval.stmtvec = new std::vector<std::shared_ptr<ddlbx::ir::NStatement>>();
        yyval.stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1008 "y.tab.c"
break;
case 3:
  if (!yytrial)
#line 86 "parser.y"
{
        yyvsp[-1].stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1016 "y.tab.c"
break;
case 4:
  if (!yytrial)
#line 92 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1024 "y.tab.c"
break;
case 9:
  if (!yytrial)
#line 102 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), 
                                                *yyvsp[-5].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)));
      }
#line 1034 "y.tab.c"
break;
case 10:
  if (!yytrial)
#line 110 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), 
                                                *yyvsp[-6].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)),
                                                *yyvsp[-5].stringvec);
      }
#line 1045 "y.tab.c"
break;
case 11:
  if (!yytrial)
#line 119 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>(yyvsp[-1].stmt)),
                                                 std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1054 "y.tab.c"
break;
case 12:
  if (!yytrial)
#line 123 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>(yyvsp[-1].stmt)),
                                                         std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1063 "y.tab.c"
break;
case 13:
  if (!yytrial)
#line 130 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
      }
#line 1071 "y.tab.c"
break;
case 14:
  if (!yytrial)
#line 133 "parser.y"
{
        yyvsp[-2].argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1079 "y.tab.c"
break;
case 15:
  if (!yytrial)
#line 136 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
        yyval.argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1088 "y.tab.c"
break;
case 16:
  if (!yytrial)
#line 143 "parser.y"
{
        yyval.expr = new ddlbx::ir::NArgument(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), *yyvsp[-2].string);
      }
#line 1096 "y.tab.c"
break;
case 17:
  if (!yytrial)
#line 149 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NObjectDeclaration(*yyvsp[-3].string, *yyvsp[-1].membervec);
      }
#line 1104 "y.tab.c"
break;
case 18:
  if (!yytrial)
#line 152 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateObjectDeclaration(*yyvsp[-4].string, *yyvsp[-1].membervec, *yyvsp[-3].stringvec);
      }
#line 1112 "y.tab.c"
break;
case 19:
  if (!yytrial)
#line 157 "parser.y"
{
        yyval.member = new ddlbx::ir::NMemberDeclaration(std::make_shared<ddlbx::ir::NType>(*yyvsp[0].string), *yyvsp[-2].string);
      }
#line 1120 "y.tab.c"
break;
case 20:
  if (!yytrial)
#line 163 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
      }
#line 1128 "y.tab.c"
break;
case 21:
  if (!yytrial)
#line 166 "parser.y"
{
        yyvsp[-2].membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1136 "y.tab.c"
break;
case 22:
  if (!yytrial)
#line 169 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
        yyval.membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1145 "y.tab.c"
break;
case 23:
  if (!yytrial)
#line 176 "parser.y"
{
        ddlbx::ir::NFunctionDefinition *funcDef = new ddlbx::ir::NFunctionDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[-1].type), *yyvsp[-6].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-4].argvec)));
        ddlbx::ir::NFunctionDeclaration *funcDecl = new ddlbx::ir::NFunctionDeclaration(
            std::shared_ptr<ddlbx::ir::NFunctionDefinition>(funcDef), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
        yyval.stmt = new ddlbx::ir::NMethodDeclaration(*yyvsp[-8].string, std::shared_ptr<ddlbx::ir::NFunctionDeclaration>(funcDecl));
      }
#line 1157 "y.tab.c"
break;
case 24:
  if (!yytrial)
#line 185 "parser.y"
{
        ddlbx::ir::NFunctionDefinition *funcDef = new ddlbx::ir::NFunctionDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[-1].type), *yyvsp[-6].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-4].argvec)));
        ddlbx::ir::NFunctionDeclaration *funcDecl = new ddlbx::ir::NFunctionDeclaration(
            std::shared_ptr<ddlbx::ir::NFunctionDefinition>(funcDef), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
        yyval.stmt = new ddlbx::ir::NTraitMethodDeclaration(*yyvsp[-6].string, std::shared_ptr<ddlbx::ir::NFunctionDeclaration>(funcDecl), *yyvsp[-9].membervec);
      }
#line 1169 "y.tab.c"
break;
case 25:
  if (!yytrial)
#line 194 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1177 "y.tab.c"
break;
case 26:
  if (!yytrial)
#line 197 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement();
      }
#line 1185 "y.tab.c"
break;
case 27:
  if (!yytrial)
#line 203 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1193 "y.tab.c"
break;
case 28:
  if (!yytrial)
#line 206 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(*yyvsp[-4].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec), *yyvsp[-3].stringvec);
      }
#line 1201 "y.tab.c"
break;
case 29:
  if (!yytrial)
#line 209 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NMemberAccess>(dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-3].expr)),
                                                          std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1210 "y.tab.c"
break;
case 30:
  if (!yytrial)
#line 216 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1218 "y.tab.c"
break;
case 31:
  if (!yytrial)
#line 219 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-4].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec), *yyvsp[-3].stringvec);
      }
#line 1226 "y.tab.c"
break;
case 32:
  if (!yytrial)
#line 225 "parser.y"
{
        yyval.stringvec = yyvsp[-1].stringvec;
      }
#line 1234 "y.tab.c"
break;
case 33:
  if (!yytrial)
#line 231 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
      }
#line 1242 "y.tab.c"
break;
case 34:
  if (!yytrial)
#line 234 "parser.y"
{
        yyvsp[-2].stringvec->push_back(yyvsp[0].type->name);
      }
#line 1250 "y.tab.c"
break;
case 35:
  if (!yytrial)
#line 237 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
        yyval.stringvec->push_back(yyvsp[0].type->name);
      }
#line 1259 "y.tab.c"
break;
case 36:
  if (!yytrial)
#line 244 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
      }
#line 1267 "y.tab.c"
break;
case 37:
  if (!yytrial)
#line 247 "parser.y"
{
        yyvsp[-2].exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1275 "y.tab.c"
break;
case 38:
  if (!yytrial)
#line 250 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
        yyval.exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1284 "y.tab.c"
break;
case 39:
  if (!yytrial)
#line 257 "parser.y"
{
        dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-2].expr)->ids.push_back(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier));
      }
#line 1292 "y.tab.c"
break;
case 40:
  if (!yytrial)
#line 260 "parser.y"
{
        yyval.expr = new ddlbx::ir::NMemberAccess(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), {std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier)});
      }
#line 1300 "y.tab.c"
break;
case 41:
  if (!yytrial)
#line 266 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1308 "y.tab.c"
break;
case 42:
  if (!yytrial)
#line 269 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1316 "y.tab.c"
break;
case 43:
  if (!yytrial)
#line 272 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1324 "y.tab.c"
break;
case 44:
  if (!yytrial)
#line 275 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1332 "y.tab.c"
break;
case 45:
  if (!yytrial)
#line 278 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1340 "y.tab.c"
break;
case 46:
  if (!yytrial)
#line 281 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1348 "y.tab.c"
break;
case 47:
  if (!yytrial)
#line 284 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1356 "y.tab.c"
break;
case 48:
  if (!yytrial)
#line 290 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1364 "y.tab.c"
break;
case 49:
  if (!yytrial)
#line 293 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1372 "y.tab.c"
break;
case 50:
  if (!yytrial)
#line 296 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1380 "y.tab.c"
break;
case 54:
  if (!yytrial)
#line 305 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-4].identifier), 
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          nullptr, 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1392 "y.tab.c"
break;
case 55:
  if (!yytrial)
#line 312 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-6].identifier), 
                                          nullptr, 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1404 "y.tab.c"
break;
case 56:
  if (!yytrial)
#line 319 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-8].identifier), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-6].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr), 
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), 
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1416 "y.tab.c"
break;
case 57:
  if (!yytrial)
#line 326 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(nullptr, nullptr, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), nullptr, std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1424 "y.tab.c"
break;
case 58:
  if (!yytrial)
#line 332 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NOptStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1432 "y.tab.c"
break;
case 59:
  if (!yytrial)
#line 338 "parser.y"
{
        yyval.block = yyvsp[-1].block;
      }
#line 1440 "y.tab.c"
break;
case 60:
  if (!yytrial)
#line 344 "parser.y"
{
        yyval.block = new ddlbx::ir::NBlock();
      }
#line 1448 "y.tab.c"
break;
case 61:
  if (!yytrial)
#line 347 "parser.y"
{
        yyvsp[-1].block->statements.push_back(yyvsp[0].stmt);
      }
#line 1456 "y.tab.c"
break;
case 62:
  if (!yytrial)
#line 353 "parser.y"
{
        std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varList = yyvsp[0].varvec;
        yyval.expr = new ddlbx::ir::NVariableDeclarationList(*varList);
      }
#line 1465 "y.tab.c"
break;
case 63:
  if (!yytrial)
#line 360 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1473 "y.tab.c"
break;
case 64:
  if (!yytrial)
#line 363 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1481 "y.tab.c"
break;
case 65:
  if (!yytrial)
#line 366 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1490 "y.tab.c"
break;
case 66:
  if (!yytrial)
#line 370 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1499 "y.tab.c"
break;
case 67:
  if (!yytrial)
#line 377 "parser.y"
{
        yyval.expr = new ddlbx::ir::NAssignment(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-2].identifier), std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1507 "y.tab.c"
break;
case 68:
  if (!yytrial)
#line 383 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1515 "y.tab.c"
break;
case 69:
  if (!yytrial)
#line 386 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1523 "y.tab.c"
break;
case 70:
  if (!yytrial)
#line 389 "parser.y"
{
        yyval.expr = new ddlbx::ir::NUnaryOperator(yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1531 "y.tab.c"
break;
case 71:
  if (!yytrial)
#line 392 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1539 "y.tab.c"
break;
case 72:
  if (!yytrial)
#line 398 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1547 "y.tab.c"
break;
case 73:
  if (!yytrial)
#line 401 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1555 "y.tab.c"
break;
case 74:
  if (!yytrial)
#line 404 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1563 "y.tab.c"
break;
case 75:
  if (!yytrial)
#line 407 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1571 "y.tab.c"
break;
case 76:
  if (!yytrial)
#line 410 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1579 "y.tab.c"
break;
case 77:
  if (!yytrial)
#line 413 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1587 "y.tab.c"
break;
case 78:
  if (!yytrial)
#line 416 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1595 "y.tab.c"
break;
case 79:
  if (!yytrial)
#line 422 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1603 "y.tab.c"
break;
case 80:
  if (!yytrial)
#line 425 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1611 "y.tab.c"
break;
case 81:
  if (!yytrial)
#line 428 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1619 "y.tab.c"
break;
case 82:
  if (!yytrial)
#line 434 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1627 "y.tab.c"
break;
case 83:
  if (!yytrial)
#line 437 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1635 "y.tab.c"
break;
case 84:
  if (!yytrial)
#line 440 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1643 "y.tab.c"
break;
case 85:
  if (!yytrial)
#line 446 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1651 "y.tab.c"
break;
case 86:
  if (!yytrial)
#line 449 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1659 "y.tab.c"
break;
case 87:
  if (!yytrial)
#line 452 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1667 "y.tab.c"
break;
case 88:
  if (!yytrial)
#line 455 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1675 "y.tab.c"
break;
case 89:
  if (!yytrial)
#line 458 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1683 "y.tab.c"
break;
case 90:
  if (!yytrial)
#line 461 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1691 "y.tab.c"
break;
case 91:
  if (!yytrial)
#line 464 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1699 "y.tab.c"
break;
case 92:
  if (!yytrial)
#line 467 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1707 "y.tab.c"
break;
case 93:
  if (!yytrial)
#line 473 "parser.y"
{
        yyval.identifier = new ddlbx::ir::NIdentifier(*(yyvsp[0].string));
        delete yyvsp[0].string;
      }
#line 1716 "y.tab.c"
break;
case 94:
  if (!yytrial)
#line 480 "parser.y"
{
        yyval.expr = new ddlbx::ir::NInteger(atol(yyvsp[0].string->c_str()));
      }
#line 1724 "y.tab.c"
break;
case 95:
  if (!yytrial)
#line 483 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFloat(atof(yyvsp[0].string->c_str()));
      }
#line 1732 "y.tab.c"
break;
case 96:
  if (!yytrial)
#line 489 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBoolean(*yyvsp[0].string);
      }
#line 1740 "y.tab.c"
break;
case 97:
  if (!yytrial)
#line 495 "parser.y"
{
        yyval.expr = new ddlbx::ir::NString(*yyvsp[0].string);
      }
#line 1748 "y.tab.c"
break;
case 98:
  if (!yytrial)
#line 501 "parser.y"
{
        yyval.type = new ddlbx::ir::NType(*yyvsp[0].string);
      }
#line 1756 "y.tab.c"
break;
#line 1758 "y.tab.c"
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
