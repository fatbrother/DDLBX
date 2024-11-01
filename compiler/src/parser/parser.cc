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
#include "ir/statement.hpp"
#include "ir/expression.hpp"
#include "ir/object.hpp"
#include "ir/function.hpp"
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
std::vector<std::shared_ptr<ddlbx::ir::NProgram>> programs;
#line 31 "parser.y"
#line 44 "y.tab.c"
static int yylhs[] = {                                        -1,
    0,    1,    1,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    6,    8,   16,    7,    7,   35,   35,
   35,   30,   12,   12,   40,   39,   39,   39,   13,   14,
   17,   18,   15,   11,   11,   28,   28,   28,   33,   33,
   38,   37,   37,   37,   36,   36,   36,   32,   32,   31,
   31,   31,   31,   31,   31,   31,    4,    4,    4,    4,
    4,    4,   10,   10,   10,   10,    9,    2,    3,    3,
   29,   34,   34,   34,   34,   27,   19,   19,   19,   19,
   20,   20,   20,   20,   20,   20,   20,   21,   21,   21,
   22,   22,   22,   23,   23,   23,   23,   23,   23,   23,
   23,   41,   24,   24,   25,   26,   42,
};
static int yylen[] = {                                         2,
    1,    1,    2,    2,    2,    2,    2,    1,    1,    1,
    1,    1,    1,    3,    7,    8,    2,    2,    0,    3,
    1,    3,    5,    6,    3,    0,    3,    1,    9,    2,
   10,    2,   12,    3,    2,    4,    5,    4,    4,    5,
    3,    0,    3,    1,    0,    3,    1,    3,    3,    1,
    1,    1,    1,    3,    1,    1,    2,    2,    2,    1,
    1,    1,    7,    9,   11,    5,    5,    3,    0,    2,
    2,    3,    3,    1,    1,    3,    3,    3,    2,    1,
    3,    3,    3,    3,    3,    3,    1,    1,    3,    3,
    1,    3,    3,    1,    1,    1,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,
};
static int yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    2,   13,   10,    0,   11,
    0,    8,   12,    0,    0,    9,    0,    0,    0,    0,
    3,   69,    4,   17,    6,   30,    5,   18,    7,   32,
    0,    0,    0,    0,    0,    0,   28,    0,    0,   14,
    0,  107,    0,   44,    0,   21,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  103,  104,    0,  106,  105,
    0,    0,    0,    0,    0,    0,   68,   70,   60,   61,
   62,    0,    0,    0,    0,   91,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   41,    0,    0,    0,
    0,    0,    0,    0,   25,    0,   27,   23,    0,    0,
    0,    0,   35,    0,    0,  102,   74,    0,    0,    0,
    0,   79,    0,   57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   59,   58,    0,    0,
    0,    0,   43,   22,    0,   20,    0,    0,    0,    0,
   24,   47,    0,    0,    0,    0,   34,    0,    0,    0,
    0,    0,   77,   78,    0,    0,    0,    0,    0,    0,
    0,    0,   92,   93,   49,    0,   48,   76,   15,    0,
    0,    0,    0,   36,    0,   39,    0,    0,   73,    0,
    0,    0,    0,    0,   38,    0,   16,    0,    0,   46,
   37,   40,   67,   66,    0,    0,   29,    0,    0,    0,
    0,    0,   31,    0,    0,   63,    0,    0,    0,    0,
   33,    0,   64,    0,   65,
};
static int yydgoto[] = {                                       4,
    5,   24,   41,   68,    6,    7,    8,    9,   69,   70,
   71,   10,   11,   12,   13,   14,   15,   16,  142,   73,
   74,   75,   76,   77,   78,   79,   80,   81,   82,   46,
   83,   84,   85,  108,   47,  143,   43,   34,   36,   37,
  105,   44,
};
static int yysindex[] = {                                   -235,
 -250, -186, -237,    0, -235,    0,    0,    0, -236,    0,
  -94,    0,    0,  -67,  -41,    0, -256, -182, -255, -225,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -179, -176, -128, -216, -195, -113,    0, -182, -143,    0,
 -201,    0, -222,    0, -138,    0, -264, -116, -176,  -85,
  -76,  -88, -182,  -36, -182,    0,    0,   17,    0,    0,
 -245,  -51,  -66,  -59, -214, -214,    0,    0,    0,    0,
    0,  -58, -240,  291, -171,    0,    0,    0,    0,  -26,
    0,  -12,  -54, -211,    0,  -32,    0, -179, -179,  -21,
 -176, -176, -198,   -6,    0,   27,    0,    0,  -17, -214,
 -214,   42,    0,    6,    0,    0,    0,   23,  -32, -158,
 -214,    0,   34,    0, -214, -214, -158, -158, -158, -158,
 -158, -158, -158, -158, -158, -158,    0,    0,  -51, -214,
  -51, -214,    0,    0, -179,    0, -197,   47, -176,   60,
    0,    0, -191,    8, -214, -214,    0,  -51,   77,   87,
 -133,    0,    0,    0,   92,   92,   92,   92,   92,   92,
 -171, -171,    0,    0,    0, -174,    0,    0,    0,   88,
 -179, -165, -176,    0, -214,    0, -154,   33,    0,  -32,
   90,   90, -214, -214,    0, -179,    0,   97, -123,    0,
    0,    0,    0,    0,  104, -262,    0, -179,  122, -214,
   90, -214,    0, -179,  109,    0,  137,   90, -214,   90,
    0,  141,    0,   90,    0,
};
static int yyrindex[] = {                                      0,
    0,    0,    0,    0,  426,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -204, -120,    0,    0,    0,    0,    0,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -120,    0,
    0,    0,    0,    0,   58,    0,    0,  -65,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  266, -175,  136,    0,  -92,  -39,  -14,    0,
   11,    0,    0,  111,   36, -124,    0,    0,    0,    0,
    0, -120,    0,    0,    0,    0,    0,    0,    0, -112,
   64,    0,    0,    0,   61,    0,    0,  140,  106,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -112,
    0,    0,    0,    0,    0,    0,    0,    0, -120,    0,
    0,    0,    0,    0, -112,   64,    0,    0,    0,    0,
  211,   86,    0,    0, -160,  216,  226,  236,  246,  256,
  161,  186,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -120,    0,    0,    0,    0,    0,    0,  113,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static int yycindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  163,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static int yygindex[] = {                                      0,
    0,  -11,    0,    0,  434,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -40,  330,
   19,  295,  289,    0,    0,    0,  -60,    0,    0,  352,
    0,    0,    0,    0,  -44,  -91,    0,   -8,  -19,  391,
  -33,  -82,
};
#define YYTABLESIZE 568
static int yytable[] = {                                      26,
   72,  107,   28,   30,   93,  133,  134,   86,   17,  144,
   39,   56,   57,   58,   59,   60,   31,   31,   54,   90,
  104,  201,   20,   91,  112,  113,   32,    1,  109,   38,
  202,    2,    3,   33,   18,   99,   65,   66,  166,  115,
  116,  103,   56,   57,   58,   59,   60,  137,   22,  102,
   23,   87,  169,  177,  178,   56,   57,   58,   59,   60,
   61,   40,   62,   63,   64,   88,   49,   65,   66,   42,
  150,  130,   19,   50,  153,  154,   35,  151,  131,   42,
   65,   66,   45,   42,   67,  138,  170,  179,  187,   91,
   91,  168,  174,   51,  172,  165,  175,  167,   56,   57,
   58,   59,   60,  197,   87,   87,  125,  126,   87,  185,
   87,   87,   87,  175,  180,  203,   87,   87,  188,   83,
   83,  208,   91,   83,   66,   83,   83,   83,  189,  191,
   48,   83,   83,  175,  190,  155,  156,  157,  158,  159,
  160,   55,  195,  196,   94,   94,   94,   94,   94,   94,
   89,   94,   94,   94,   94,   94,   94,  183,  184,  205,
  199,  207,   94,   19,   91,   50,   92,   19,  212,  193,
  194,   45,   52,   94,   53,   45,   95,   95,   95,   95,
   95,   95,   95,   95,   95,   95,   95,   95,   95,  206,
   22,   95,   25,   95,   95,   95,  211,   51,  213,   95,
   95,   96,  215,  102,  102,  102,  102,  106,  102,  102,
  102,  102,  102,  102,  102,  102,  110,   22,  102,   27,
  102,  102,  102,  111,  102,  102,  102,  102,  114,   96,
   96,   96,   96,   96,   96,  129,   96,   96,   96,   96,
   96,   96,  132,   22,   96,   29,   96,   96,   96,   98,
   52,   53,   96,   96,   97,   97,   97,   97,   97,   97,
  127,   97,   97,   97,   97,   97,   97,  135,  141,   97,
   53,   97,   97,   97,  128,   53,  139,   97,   97,   99,
   99,   99,   99,   99,   99,  140,   99,   99,   99,   99,
   99,   99,  147,  176,   99,  175,   99,   99,   99,  100,
   55,  101,   99,   99,  100,  100,  100,  100,  100,  100,
  148,  100,  100,  100,  100,  100,  100,  152,  192,  100,
  175,  100,  100,  100,  145,   56,  146,  100,  100,   94,
   94,   94,   94,   94,   94,  171,   94,   94,   94,   94,
   94,   94,  173,   26,   94,   26,   94,   94,   94,   45,
   50,   45,   94,   94,   98,   98,   98,   98,   98,   98,
  181,   98,   98,   98,   98,   98,   98,  123,  124,   98,
  182,   98,   98,   98,   22,   54,  186,   98,   98,  101,
  101,  101,  101,  101,  101,  198,  101,  101,  101,  101,
  101,  101,   75,   75,  101,  200,  101,  101,  101,   72,
   72,  209,  101,  101,   88,   88,   88,   88,   88,   88,
  204,   88,   88,  163,  164,   88,   88,  161,  162,   88,
  210,   88,   88,   88,  214,    1,   71,   88,   88,   89,
   89,   89,   89,   89,   89,    0,   89,   89,   21,  149,
   89,   89,  136,   97,   89,    0,   89,   89,   89,    0,
    0,    0,   89,   89,   90,   90,   90,   90,   90,   90,
    0,   90,   90,    0,    0,   90,   90,    0,    0,   90,
    0,   90,   90,   90,    0,    0,    0,   90,   90,   94,
   94,   94,   94,   94,   94,    0,   94,   94,   94,   94,
   94,   94,    0,    0,   94,   86,   86,    0,    0,   86,
   50,   86,   86,   86,    0,   84,   84,   86,   86,   84,
    0,   84,   84,   84,    0,   85,   85,   84,   84,   85,
    0,   85,   85,   85,    0,   81,   81,   85,   85,   81,
    0,   81,   81,   81,    0,   82,   82,   81,   81,   82,
    0,   82,   82,   82,    0,    0,    0,   82,   82,   80,
    0,   80,   80,   80,    0,    0,    0,   80,   80,  117,
  118,  119,  120,  121,  122,    0,  123,  124,
};
static int yycheck[] = {                                      11,
   41,   62,   14,   15,   49,   88,   89,   41,  259,  101,
   19,  257,  258,  259,  260,  261,  273,  273,   38,  284,
   61,  284,  260,  288,   65,   66,  283,  263,   62,  285,
  293,  267,  268,  290,  285,   55,  282,  283,  130,  280,
  281,  287,  257,  258,  259,  260,  261,   92,  285,   58,
  287,  274,  135,  145,  146,  257,  258,  259,  260,  261,
  262,  287,  264,  265,  266,  288,  283,  282,  283,  274,
  111,  283,  259,  290,  115,  116,  259,  111,  290,  259,
  282,  283,  259,  288,  286,  284,  284,  148,  171,  288,
  288,  132,  284,  289,  139,  129,  288,  131,  257,  258,
  259,  260,  261,  186,  280,  281,  278,  279,  284,  284,
  286,  287,  288,  288,  148,  198,  292,  293,  284,  280,
  281,  204,  288,  284,  283,  286,  287,  288,  173,  284,
  259,  292,  293,  288,  175,  117,  118,  119,  120,  121,
  122,  285,  183,  184,  269,  270,  271,  272,  273,  274,
  289,  276,  277,  278,  279,  280,  281,  291,  292,  200,
  284,  202,  287,  284,  288,  290,  283,  288,  209,  181,
  182,  284,  286,  259,  288,  288,  269,  270,  271,  272,
  273,  274,  259,  276,  277,  278,  279,  280,  281,  201,
  285,  284,  287,  286,  287,  288,  208,  290,  210,  292,
  293,  290,  214,  269,  270,  271,  272,  259,  274,  275,
  276,  277,  278,  279,  280,  281,  283,  285,  284,  287,
  286,  287,  288,  283,  290,  291,  292,  293,  287,  269,
  270,  271,  272,  273,  274,  290,  276,  277,  278,  279,
  280,  281,  275,  285,  284,  287,  286,  287,  288,  286,
  290,  288,  292,  293,  269,  270,  271,  272,  273,  274,
  287,  276,  277,  278,  279,  280,  281,  289,  286,  284,
  288,  286,  287,  288,  287,  290,  283,  292,  293,  269,
  270,  271,  272,  273,  274,  259,  276,  277,  278,  279,
  280,  281,  287,  286,  284,  288,  286,  287,  288,  283,
  290,  285,  292,  293,  269,  270,  271,  272,  273,  274,
  288,  276,  277,  278,  279,  280,  281,  284,  286,  284,
  288,  286,  287,  288,  283,  290,  285,  292,  293,  269,
  270,  271,  272,  273,  274,  289,  276,  277,  278,  279,
  280,  281,  283,  286,  284,  288,  286,  287,  288,  286,
  290,  288,  292,  293,  269,  270,  271,  272,  273,  274,
  284,  276,  277,  278,  279,  280,  281,  276,  277,  284,
  284,  286,  287,  288,  285,  290,  289,  292,  293,  269,
  270,  271,  272,  273,  274,  289,  276,  277,  278,  279,
  280,  281,  287,  288,  284,  292,  286,  287,  288,  287,
  288,  293,  292,  293,  269,  270,  271,  272,  273,  274,
  289,  276,  277,  125,  126,  280,  281,  123,  124,  284,
  284,  286,  287,  288,  284,    0,  287,  292,  293,  269,
  270,  271,  272,  273,  274,  273,  276,  277,    5,  110,
  280,  281,   91,   53,  284,   -1,  286,  287,  288,   -1,
   -1,   -1,  292,  293,  269,  270,  271,  272,  273,  274,
   -1,  276,  277,   -1,   -1,  280,  281,   -1,   -1,  284,
   -1,  286,  287,  288,   -1,   -1,   -1,  292,  293,  269,
  270,  271,  272,  273,  274,   -1,  276,  277,  278,  279,
  280,  281,   -1,   -1,  284,  280,  281,   -1,   -1,  284,
  290,  286,  287,  288,   -1,  280,  281,  292,  293,  284,
   -1,  286,  287,  288,   -1,  280,  281,  292,  293,  284,
   -1,  286,  287,  288,   -1,  280,  281,  292,  293,  284,
   -1,  286,  287,  288,   -1,  280,  281,  292,  293,  284,
   -1,  286,  287,  288,   -1,   -1,   -1,  292,  293,  284,
   -1,  286,  287,  288,   -1,   -1,   -1,  292,  293,  269,
  270,  271,  272,  273,  274,   -1,  276,  277,
};
static int yyctable[] = {                                     31,
  102,   -1,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 293
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
"KW_FOR","KW_OBJECT","KW_GET","COM_EQ","COM_NE","COM_LE","COM_GE","COM_LT",
"COM_GT","OP_ASSIGN","OP_PLUS","OP_MINUS","OP_MULT","OP_DIV","OP_AND","OP_OR",
"OP_NOT","LPAREN","RPAREN","LBRACE","RBRACE","SEMICOLON","COMMA","COLON","DOT",
"KW_FROM","KW_TO","KW_STEP",
};
static char *yyrule[] = {
"$accept : Program",
"Program : GlobalStatements",
"GlobalStatements : GlobalStatement",
"GlobalStatements : GlobalStatements GlobalStatement",
"GlobalStatement : FunctionDefinition SEMICOLON",
"GlobalStatement : TemplateFunctionDefinition SEMICOLON",
"GlobalStatement : MethodDefinition SEMICOLON",
"GlobalStatement : TemplateObjectMethodDefinition SEMICOLON",
"GlobalStatement : MethodDeclaration",
"GlobalStatement : TemplateObjectMethodDeclaration",
"GlobalStatement : FunctionDeclaration",
"GlobalStatement : ObjectDeclaration",
"GlobalStatement : TraitMethodDeclaration",
"GlobalStatement : GetModule",
"GetModule : KW_GET STRING SEMICOLON",
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
"MethodDefinition : KW_FUNCTION IDENTIFIER DOT IDENTIFIER LPAREN FPDeclarationList RPAREN COLON Type",
"MethodDeclaration : MethodDefinition Block",
"TemplateObjectMethodDefinition : KW_FUNCTION IDENTIFIER TemplateDeclaration DOT IDENTIFIER LPAREN FPDeclarationList RPAREN COLON Type",
"TemplateObjectMethodDeclaration : TemplateObjectMethodDefinition Block",
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


#line 549 "parser.y"

void yyerror(const char *s) {
    ddlbx::utility::LOG_ERROR("Error: " + std::string(s) + " at " + std::to_string(yylineno) + ":" + std::to_string(yycolumn) + " near " + std::string(yytext));
    return;
}

void parseText(const char* text) {
    YY_BUFFER_STATE buffer = yy_scan_string(text);
    yyparse();
    yy_delete_buffer(buffer);
    return;
}
#line 629 "y.tab.c"
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
#line 76 "parser.y"
{
        yyval.program = new ddlbx::ir::NProgram();
        yyval.program->statements = *yyvsp[0].stmtvec;
        programs.push_back(std::shared_ptr<ddlbx::ir::NProgram>(yyval.program));
      }
#line 1025 "y.tab.c"
break;
case 2:
  if (!yytrial)
#line 84 "parser.y"
{
        yyval.stmtvec = new std::vector<std::shared_ptr<ddlbx::ir::NStatement>>();
        yyval.stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1034 "y.tab.c"
break;
case 3:
  if (!yytrial)
#line 88 "parser.y"
{
        yyvsp[-1].stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1042 "y.tab.c"
break;
case 4:
  if (!yytrial)
#line 94 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1050 "y.tab.c"
break;
case 5:
  if (!yytrial)
#line 97 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1058 "y.tab.c"
break;
case 6:
  if (!yytrial)
#line 100 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1066 "y.tab.c"
break;
case 7:
  if (!yytrial)
#line 103 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1074 "y.tab.c"
break;
case 14:
  if (!yytrial)
#line 115 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NGetModule(*yyvsp[-1].string);
      }
#line 1082 "y.tab.c"
break;
case 15:
  if (!yytrial)
#line 121 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type),
                                                *yyvsp[-5].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)));
      }
#line 1092 "y.tab.c"
break;
case 16:
  if (!yytrial)
#line 129 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type),
                                                *yyvsp[-6].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)),
                                                *yyvsp[-5].stringvec);
      }
#line 1103 "y.tab.c"
break;
case 17:
  if (!yytrial)
#line 138 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>(yyvsp[-1].stmt)),
                                                 std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1112 "y.tab.c"
break;
case 18:
  if (!yytrial)
#line 142 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>(yyvsp[-1].stmt)),
                                                         std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1121 "y.tab.c"
break;
case 19:
  if (!yytrial)
#line 149 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
      }
#line 1129 "y.tab.c"
break;
case 20:
  if (!yytrial)
#line 152 "parser.y"
{
        yyvsp[-2].argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1137 "y.tab.c"
break;
case 21:
  if (!yytrial)
#line 155 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
        yyval.argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1146 "y.tab.c"
break;
case 22:
  if (!yytrial)
#line 162 "parser.y"
{
        yyval.expr = new ddlbx::ir::NArgument(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), *yyvsp[-2].string);
      }
#line 1154 "y.tab.c"
break;
case 23:
  if (!yytrial)
#line 168 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NObjectDeclaration(*yyvsp[-3].string, *yyvsp[-1].membervec);
      }
#line 1162 "y.tab.c"
break;
case 24:
  if (!yytrial)
#line 171 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateObjectDeclaration(*yyvsp[-4].string, *yyvsp[-1].membervec, *yyvsp[-3].stringvec);
      }
#line 1170 "y.tab.c"
break;
case 25:
  if (!yytrial)
#line 176 "parser.y"
{
        yyval.member = new ddlbx::ir::NMemberDeclaration(std::make_shared<ddlbx::ir::NType>(*yyvsp[0].string), *yyvsp[-2].string);
      }
#line 1178 "y.tab.c"
break;
case 26:
  if (!yytrial)
#line 182 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
      }
#line 1186 "y.tab.c"
break;
case 27:
  if (!yytrial)
#line 185 "parser.y"
{
        yyvsp[-2].membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1194 "y.tab.c"
break;
case 28:
  if (!yytrial)
#line 188 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
        yyval.membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1203 "y.tab.c"
break;
case 29:
  if (!yytrial)
#line 195 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NMethodDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), *yyvsp[-5].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)), *yyvsp[-7].string);
      }
#line 1212 "y.tab.c"
break;
case 30:
  if (!yytrial)
#line 202 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NMethodDeclaration(std::shared_ptr<ddlbx::ir::NMethodDefinition>(dynamic_cast<ddlbx::ir::NMethodDefinition*>(yyvsp[-1].stmt)),
                                               std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1221 "y.tab.c"
break;
case 31:
  if (!yytrial)
#line 209 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateObjectMethodDefinition(
          std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type),
          *yyvsp[-5].string,
          *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)),
          *yyvsp[-8].string,
          *yyvsp[-7].stringvec);
      }
#line 1234 "y.tab.c"
break;
case 32:
  if (!yytrial)
#line 220 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateObjectMethodDeclaration(
          std::shared_ptr<ddlbx::ir::NTemplateObjectMethodDefinition>(dynamic_cast<ddlbx::ir::NTemplateObjectMethodDefinition*>(yyvsp[-1].stmt)),
          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1244 "y.tab.c"
break;
case 33:
  if (!yytrial)
#line 228 "parser.y"
{
        ddlbx::ir::NMethodDefinition *funcDef = new ddlbx::ir::NMethodDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[-1].type), *yyvsp[-6].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-4].argvec)), "");
        ddlbx::ir::NFunctionDeclaration *funcDecl = new ddlbx::ir::NFunctionDeclaration(
            std::shared_ptr<ddlbx::ir::NFunctionDefinition>(funcDef), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
        yyval.stmt = new ddlbx::ir::NTraitMethodDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDeclaration>(funcDecl), *yyvsp[-9].membervec);
      }
#line 1256 "y.tab.c"
break;
case 34:
  if (!yytrial)
#line 237 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1264 "y.tab.c"
break;
case 35:
  if (!yytrial)
#line 240 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement();
      }
#line 1272 "y.tab.c"
break;
case 36:
  if (!yytrial)
#line 246 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1280 "y.tab.c"
break;
case 37:
  if (!yytrial)
#line 249 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(*yyvsp[-4].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec), *yyvsp[-3].stringvec);
      }
#line 1288 "y.tab.c"
break;
case 38:
  if (!yytrial)
#line 252 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NMemberAccess>(dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-3].expr)),
                                                          std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1297 "y.tab.c"
break;
case 39:
  if (!yytrial)
#line 259 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1305 "y.tab.c"
break;
case 40:
  if (!yytrial)
#line 262 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-4].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec), *yyvsp[-3].stringvec);
      }
#line 1313 "y.tab.c"
break;
case 41:
  if (!yytrial)
#line 268 "parser.y"
{
        yyval.stringvec = yyvsp[-1].stringvec;
      }
#line 1321 "y.tab.c"
break;
case 42:
  if (!yytrial)
#line 274 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
      }
#line 1329 "y.tab.c"
break;
case 43:
  if (!yytrial)
#line 277 "parser.y"
{
        yyvsp[-2].stringvec->push_back(yyvsp[0].type->name);
      }
#line 1337 "y.tab.c"
break;
case 44:
  if (!yytrial)
#line 280 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
        yyval.stringvec->push_back(yyvsp[0].type->name);
      }
#line 1346 "y.tab.c"
break;
case 45:
  if (!yytrial)
#line 287 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
      }
#line 1354 "y.tab.c"
break;
case 46:
  if (!yytrial)
#line 290 "parser.y"
{
        yyvsp[-2].exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1362 "y.tab.c"
break;
case 47:
  if (!yytrial)
#line 293 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
        yyval.exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1371 "y.tab.c"
break;
case 48:
  if (!yytrial)
#line 300 "parser.y"
{
        dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-2].expr)->ids.push_back(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier));
      }
#line 1379 "y.tab.c"
break;
case 49:
  if (!yytrial)
#line 303 "parser.y"
{
        yyval.expr = new ddlbx::ir::NMemberAccess(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), {std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier)});
      }
#line 1387 "y.tab.c"
break;
case 50:
  if (!yytrial)
#line 309 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1395 "y.tab.c"
break;
case 51:
  if (!yytrial)
#line 312 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1403 "y.tab.c"
break;
case 52:
  if (!yytrial)
#line 315 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1411 "y.tab.c"
break;
case 53:
  if (!yytrial)
#line 318 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1419 "y.tab.c"
break;
case 54:
  if (!yytrial)
#line 321 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1427 "y.tab.c"
break;
case 55:
  if (!yytrial)
#line 324 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1435 "y.tab.c"
break;
case 56:
  if (!yytrial)
#line 327 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1443 "y.tab.c"
break;
case 57:
  if (!yytrial)
#line 333 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1451 "y.tab.c"
break;
case 58:
  if (!yytrial)
#line 336 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1459 "y.tab.c"
break;
case 59:
  if (!yytrial)
#line 339 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1467 "y.tab.c"
break;
case 63:
  if (!yytrial)
#line 348 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-4].identifier),
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr),
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1479 "y.tab.c"
break;
case 64:
  if (!yytrial)
#line 355 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-6].identifier),
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr),
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr),
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1491 "y.tab.c"
break;
case 65:
  if (!yytrial)
#line 362 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-8].identifier),
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-6].expr),
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr),
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr),
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1503 "y.tab.c"
break;
case 66:
  if (!yytrial)
#line 369 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(nullptr, nullptr, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), nullptr, std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1511 "y.tab.c"
break;
case 67:
  if (!yytrial)
#line 375 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NOptStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1519 "y.tab.c"
break;
case 68:
  if (!yytrial)
#line 381 "parser.y"
{
        yyval.block = yyvsp[-1].block;
      }
#line 1527 "y.tab.c"
break;
case 69:
  if (!yytrial)
#line 387 "parser.y"
{
        yyval.block = new ddlbx::ir::NBlock();
      }
#line 1535 "y.tab.c"
break;
case 70:
  if (!yytrial)
#line 390 "parser.y"
{
        yyvsp[-1].block->statements.push_back(yyvsp[0].stmt);
      }
#line 1543 "y.tab.c"
break;
case 71:
  if (!yytrial)
#line 396 "parser.y"
{
        std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varList = yyvsp[0].varvec;
        yyval.expr = new ddlbx::ir::NVariableDeclarationList(*varList);
      }
#line 1552 "y.tab.c"
break;
case 72:
  if (!yytrial)
#line 403 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1560 "y.tab.c"
break;
case 73:
  if (!yytrial)
#line 406 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1568 "y.tab.c"
break;
case 74:
  if (!yytrial)
#line 409 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1577 "y.tab.c"
break;
case 75:
  if (!yytrial)
#line 413 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1586 "y.tab.c"
break;
case 76:
  if (!yytrial)
#line 420 "parser.y"
{
        yyval.expr = new ddlbx::ir::NAssignment(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-2].identifier), std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1594 "y.tab.c"
break;
case 77:
  if (!yytrial)
#line 426 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1602 "y.tab.c"
break;
case 78:
  if (!yytrial)
#line 429 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1610 "y.tab.c"
break;
case 79:
  if (!yytrial)
#line 432 "parser.y"
{
        yyval.expr = new ddlbx::ir::NUnaryOperator(yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1618 "y.tab.c"
break;
case 80:
  if (!yytrial)
#line 435 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1626 "y.tab.c"
break;
case 81:
  if (!yytrial)
#line 441 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1634 "y.tab.c"
break;
case 82:
  if (!yytrial)
#line 444 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1642 "y.tab.c"
break;
case 83:
  if (!yytrial)
#line 447 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1650 "y.tab.c"
break;
case 84:
  if (!yytrial)
#line 450 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1658 "y.tab.c"
break;
case 85:
  if (!yytrial)
#line 453 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1666 "y.tab.c"
break;
case 86:
  if (!yytrial)
#line 456 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1674 "y.tab.c"
break;
case 87:
  if (!yytrial)
#line 459 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1682 "y.tab.c"
break;
case 88:
  if (!yytrial)
#line 465 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1690 "y.tab.c"
break;
case 89:
  if (!yytrial)
#line 468 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1698 "y.tab.c"
break;
case 90:
  if (!yytrial)
#line 471 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1706 "y.tab.c"
break;
case 91:
  if (!yytrial)
#line 477 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1714 "y.tab.c"
break;
case 92:
  if (!yytrial)
#line 480 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1722 "y.tab.c"
break;
case 93:
  if (!yytrial)
#line 483 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1730 "y.tab.c"
break;
case 94:
  if (!yytrial)
#line 489 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1738 "y.tab.c"
break;
case 95:
  if (!yytrial)
#line 492 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1746 "y.tab.c"
break;
case 96:
  if (!yytrial)
#line 495 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1754 "y.tab.c"
break;
case 97:
  if (!yytrial)
#line 498 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1762 "y.tab.c"
break;
case 98:
  if (!yytrial)
#line 501 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1770 "y.tab.c"
break;
case 99:
  if (!yytrial)
#line 504 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1778 "y.tab.c"
break;
case 100:
  if (!yytrial)
#line 507 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1786 "y.tab.c"
break;
case 101:
  if (!yytrial)
#line 510 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1794 "y.tab.c"
break;
case 102:
  if (!yytrial)
#line 516 "parser.y"
{
        yyval.identifier = new ddlbx::ir::NIdentifier(*(yyvsp[0].string));
        delete yyvsp[0].string;
      }
#line 1803 "y.tab.c"
break;
case 103:
  if (!yytrial)
#line 523 "parser.y"
{
        yyval.expr = new ddlbx::ir::NInteger(atol(yyvsp[0].string->c_str()));
      }
#line 1811 "y.tab.c"
break;
case 104:
  if (!yytrial)
#line 526 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFloat(atof(yyvsp[0].string->c_str()));
      }
#line 1819 "y.tab.c"
break;
case 105:
  if (!yytrial)
#line 532 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBoolean(*yyvsp[0].string);
      }
#line 1827 "y.tab.c"
break;
case 106:
  if (!yytrial)
#line 538 "parser.y"
{
        yyval.expr = new ddlbx::ir::NString(*yyvsp[0].string);
      }
#line 1835 "y.tab.c"
break;
case 107:
  if (!yytrial)
#line 544 "parser.y"
{
        yyval.type = new ddlbx::ir::NType(*yyvsp[0].string);
      }
#line 1843 "y.tab.c"
break;
#line 1845 "y.tab.c"
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
