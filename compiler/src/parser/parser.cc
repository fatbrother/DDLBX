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
    5,    6,    8,   16,    7,    7,   33,   33,   33,   28,
   12,   12,   38,   37,   37,   37,   13,   14,   15,   11,
   11,   26,   26,   26,   31,   31,   36,   35,   35,   35,
   34,   34,   34,   30,   30,   29,   29,   29,   29,   29,
   29,   29,    4,    4,    4,    4,    4,    4,   10,   10,
   10,   10,    9,    2,    3,    3,   27,   32,   32,   32,
   32,   25,   17,   17,   17,   17,   18,   18,   18,   18,
   18,   18,   18,   19,   19,   19,   20,   20,   20,   21,
   21,   21,   21,   21,   21,   21,   21,   39,   22,   22,
   23,   24,   40,
};
static int yylen[] = {                                         2,
    1,    1,    2,    2,    2,    2,    1,    1,    1,    1,
    1,    3,    7,    8,    2,    2,    0,    3,    1,    3,
    5,    6,    3,    0,    3,    1,    9,    2,   12,    3,
    2,    4,    5,    4,    4,    5,    3,    0,    3,    1,
    0,    3,    1,    3,    3,    1,    1,    1,    1,    3,
    1,    1,    2,    2,    2,    1,    1,    1,    7,    9,
   11,    5,    5,    3,    0,    2,    2,    3,    3,    1,
    1,    3,    3,    3,    2,    1,    3,    3,    3,    3,
    3,    3,    1,    1,    3,    3,    1,    3,    3,    1,
    1,    1,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,
};
static int yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    2,   11,    8,    0,    9,
    0,    7,   10,    0,    0,    0,    0,    0,    3,   65,
    4,   15,    6,   28,    5,   16,    0,    0,    0,    0,
    0,    0,   26,    0,    0,   12,    0,  103,    0,   40,
    0,   19,    0,    0,    0,    0,    0,    0,    0,    0,
   99,  100,    0,  102,  101,    0,    0,    0,    0,    0,
    0,   64,   66,   56,   57,   58,    0,    0,    0,    0,
   87,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   37,    0,    0,    0,    0,    0,    0,   23,    0,
   25,   21,    0,    0,    0,    0,   31,    0,    0,   98,
   70,    0,    0,    0,    0,   75,    0,   53,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   55,   54,    0,    0,    0,    0,   39,   20,    0,   18,
    0,    0,    0,   22,   43,    0,    0,    0,    0,   30,
    0,    0,    0,    0,    0,   73,   74,    0,    0,    0,
    0,    0,    0,    0,    0,   88,   89,   45,    0,   44,
   72,   13,    0,    0,    0,   32,    0,   35,    0,    0,
   69,    0,    0,    0,    0,    0,   34,    0,   14,    0,
   42,   33,   36,   63,   62,    0,    0,   27,    0,    0,
    0,    0,    0,    0,   59,    0,    0,    0,    0,   29,
    0,   60,    0,   61,
};
static int yydgoto[] = {                                       4,
    5,   22,   37,   63,    6,    7,    8,    9,   64,   65,
   66,   10,   11,   12,   13,   14,  135,   68,   69,   70,
   71,   72,   73,   74,   75,   76,   77,   42,   78,   79,
   80,  102,   43,  136,   39,   30,   32,   33,   99,   40,
};
static int yysindex[] = {                                   -143,
 -235, -225, -173,    0, -143,    0,    0,    0, -256,    0,
 -220,    0,    0, -219, -258, -167, -204, -183,    0,    0,
    0,    0,    0,    0,    0,    0, -162, -118, -114, -164,
 -139, -213,    0, -167, -127,    0, -203,    0, -214,    0,
 -136,    0, -199, -119, -118,  -87, -111, -167,  -54, -167,
    0,    0, -201,    0,    0, -247,  -77,  -92,  -59, -241,
 -241,    0,    0,    0,    0,    0,  -90, -168,  269, -152,
    0,    0,    0,    0,  -56,    0,  -38,  -16, -257,    0,
  -10,    0, -162, -162,   -8, -118, -118, -190,    0,   40,
    0,    0,  -48, -241, -241,    5,    0,   28,    0,    0,
    0,   36,  -10, -212, -241,    0,   56,    0, -241, -241,
 -212, -212, -212, -212, -212, -212, -212, -212, -212, -212,
    0,    0,  -77, -241,  -77, -241,    0,    0, -162,    0,
 -179,   60,   73,    0,    0, -140,   -4, -241, -241,    0,
  -77,   90,   97,  -85,    0,    0,    0,  -20,  -20,  -20,
  -20,  -20,  -20, -152, -152,    0,    0,    0, -137,    0,
    0,    0,  101, -162, -118,    0, -241,    0,  -75,   71,
    0,  -10,  114,  114, -241, -241,    0, -162,    0,  -25,
    0,    0,    0,    0,    0,  115, -254,    0,  117, -241,
  114, -241, -162,  116,    0,  129,  114, -241,  114,    0,
  130,    0,  114,    0,
};
static int yyrindex[] = {                                      0,
    0,    0,    0,    0,  415,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   77,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -210,   25,    0,    0,
    0,    0,    0,   77,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   25,    0,    0,    0,    0,   77,
    0,    0,  -76,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -132, -185,  124,
    0, -103,  -51,  -26,    0,   -1,    0,    0,   99,   24,
 -141,    0,    0,    0,    0,    0,   25,    0,    0,    0,
    0,    0,    0,   50,   96,    0,    0,    0,   49,    0,
    0,  137,   19,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   50,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   50,   96,    0,
    0,    0,    0,  199,   74,    0,    0, -170,  204,  214,
  224,  234,  244,  149,  174,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   25,    0,    0,    0,    0,    0,
    0,   44,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static int yycindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  154,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,
};
static int yygindex[] = {                                      0,
    0,  -11,    0,    0,  423,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -33,  327,  436,  271,
  283,    0,    0,    0,  -50,    0,    0,  346,    0,    0,
    0,    0,  -44,  -86,    0,   -9,  -13,  386,  -35,  -78,
};
#define YYTABLESIZE 552
static int yytable[] = {                                      24,
   88,   81,   26,   67,  127,  128,  101,   35,  137,   51,
   52,   53,   54,   55,   27,   51,   52,   53,   54,   55,
   49,  103,   98,   15,   28,  124,  106,  107,   20,  191,
   21,   29,  125,   17,   60,   61,   93,  159,  192,   97,
   60,   61,  131,   96,   51,   52,   53,   54,   55,   16,
  162,  169,  170,   51,   52,   53,   54,   55,   56,   82,
   57,   58,   59,   38,   20,   20,   23,   25,   27,  144,
   61,  143,   47,   83,   48,  146,  147,   38,   60,   61,
   34,   94,   62,   95,   85,  179,   18,  158,   86,  160,
  171,   31,  161,  132,   83,   83,   38,   86,   83,  188,
   83,   83,   83,   36,  163,  172,   83,   83,   86,   79,
   79,  109,  110,   79,  197,   79,   79,   79,   45,    1,
  180,   79,   79,    2,    3,  119,  120,   90,   90,   90,
   90,   90,   90,  181,   90,   90,   90,   90,   90,   90,
   41,  186,  187,  166,   44,   90,  177,  167,   46,   46,
  167,   76,   84,   76,   76,   76,  194,   50,  196,   76,
   76,  184,  185,   87,  201,   91,   91,   91,   91,   91,
   91,   89,   91,   91,   91,   91,   91,   91,   90,  195,
   91,  100,   91,   91,   91,  200,   47,  202,   91,   91,
  104,  204,   98,   98,   98,   98,  108,   98,   98,   98,
   98,   98,   98,   98,   98,  175,  176,   98,  182,   98,
   98,   98,  167,   98,   98,   98,   98,   92,   92,   92,
   92,   92,   92,  105,   92,   92,   92,   92,   92,   92,
  121,   92,   92,   48,   92,   92,   92,  134,   48,   48,
   92,   92,   93,   93,   93,   93,   93,   93,  122,   93,
   93,   93,   93,   93,   93,  117,  118,   93,  189,   93,
   93,   93,   86,   49,  126,   93,   93,   95,   95,   95,
   95,   95,   95,  123,   95,   95,   95,   95,   95,   95,
  129,  168,   95,  167,   95,   95,   95,  138,   51,  139,
   95,   95,   96,   96,   96,   96,   96,   96,  133,   96,
   96,   96,   96,   96,   96,   71,   71,   96,   17,   96,
   96,   96,   17,   52,  140,   96,   96,   90,   90,   90,
   90,   90,   90,  141,   90,   90,   90,   90,   90,   90,
   68,   68,   90,   41,   90,   90,   90,   41,   46,  145,
   90,   90,   94,   94,   94,   94,   94,   94,  164,   94,
   94,   94,   94,   94,   94,  165,  183,   94,  167,   94,
   94,   94,   24,   50,   24,   94,   94,   97,   97,   97,
   97,   97,   97,  173,   97,   97,   97,   97,   97,   97,
  174,   41,   97,   41,   97,   97,   97,  154,  155,  178,
   97,   97,   84,   84,   84,   84,   84,   84,   20,   84,
   84,  156,  157,   84,   84,  193,  190,   84,  198,   84,
   84,   84,  199,  203,    1,   84,   84,   85,   85,   85,
   85,   85,   85,   67,   85,   85,    0,   19,   85,   85,
  142,  130,   85,   91,   85,   85,   85,    0,    0,    0,
   85,   85,   86,   86,   86,   86,   86,   86,    0,   86,
   86,    0,    0,   86,   86,    0,    0,   86,    0,   86,
   86,   86,    0,    0,    0,   86,   86,   90,   90,   90,
   90,   90,   90,    0,   90,   90,   90,   90,   90,   90,
    0,    0,   90,   82,   82,    0,    0,   82,   46,   82,
   82,   82,    0,   80,   80,   82,   82,   80,    0,   80,
   80,   80,    0,   81,   81,   80,   80,   81,    0,   81,
   81,   81,    0,   77,   77,   81,   81,   77,    0,   77,
   77,   77,    0,   78,   78,   77,   77,   78,    0,   78,
   78,   78,    0,    0,    0,   78,   78,  111,  112,  113,
  114,  115,  116,    0,  117,  118,  148,  149,  150,  151,
  152,  153,
};
static int yycheck[] = {                                      11,
   45,   37,   14,   37,   83,   84,   57,   17,   95,  257,
  258,  259,  260,  261,  273,  257,  258,  259,  260,  261,
   34,   57,   56,  259,  283,  283,   60,   61,  285,  284,
  287,  290,  290,  259,  282,  283,   50,  124,  293,  287,
  282,  283,   87,   53,  257,  258,  259,  260,  261,  285,
  129,  138,  139,  257,  258,  259,  260,  261,  262,  274,
  264,  265,  266,  274,  285,  285,  287,  287,  273,  105,
  283,  105,  286,  288,  288,  109,  110,  288,  282,  283,
  285,  283,  286,  285,  284,  164,  260,  123,  288,  125,
  141,  259,  126,  284,  280,  281,  259,  288,  284,  178,
  286,  287,  288,  287,  284,  141,  292,  293,  288,  280,
  281,  280,  281,  284,  193,  286,  287,  288,  283,  263,
  165,  292,  293,  267,  268,  278,  279,  269,  270,  271,
  272,  273,  274,  167,  276,  277,  278,  279,  280,  281,
  259,  175,  176,  284,  259,  287,  284,  288,  290,  289,
  288,  284,  289,  286,  287,  288,  190,  285,  192,  292,
  293,  173,  174,  283,  198,  269,  270,  271,  272,  273,
  274,  259,  276,  277,  278,  279,  280,  281,  290,  191,
  284,  259,  286,  287,  288,  197,  290,  199,  292,  293,
  283,  203,  269,  270,  271,  272,  287,  274,  275,  276,
  277,  278,  279,  280,  281,  291,  292,  284,  284,  286,
  287,  288,  288,  290,  291,  292,  293,  269,  270,  271,
  272,  273,  274,  283,  276,  277,  278,  279,  280,  281,
  287,  286,  284,  288,  286,  287,  288,  286,  290,  288,
  292,  293,  269,  270,  271,  272,  273,  274,  287,  276,
  277,  278,  279,  280,  281,  276,  277,  284,  284,  286,
  287,  288,  288,  290,  275,  292,  293,  269,  270,  271,
  272,  273,  274,  290,  276,  277,  278,  279,  280,  281,
  289,  286,  284,  288,  286,  287,  288,  283,  290,  285,
  292,  293,  269,  270,  271,  272,  273,  274,  259,  276,
  277,  278,  279,  280,  281,  287,  288,  284,  284,  286,
  287,  288,  288,  290,  287,  292,  293,  269,  270,  271,
  272,  273,  274,  288,  276,  277,  278,  279,  280,  281,
  287,  288,  284,  284,  286,  287,  288,  288,  290,  284,
  292,  293,  269,  270,  271,  272,  273,  274,  289,  276,
  277,  278,  279,  280,  281,  283,  286,  284,  288,  286,
  287,  288,  286,  290,  288,  292,  293,  269,  270,  271,
  272,  273,  274,  284,  276,  277,  278,  279,  280,  281,
  284,  286,  284,  288,  286,  287,  288,  117,  118,  289,
  292,  293,  269,  270,  271,  272,  273,  274,  285,  276,
  277,  119,  120,  280,  281,  289,  292,  284,  293,  286,
  287,  288,  284,  284,    0,  292,  293,  269,  270,  271,
  272,  273,  274,  287,  276,  277,  273,    5,  280,  281,
  104,   86,  284,   48,  286,  287,  288,   -1,   -1,   -1,
  292,  293,  269,  270,  271,  272,  273,  274,   -1,  276,
  277,   -1,   -1,  280,  281,   -1,   -1,  284,   -1,  286,
  287,  288,   -1,   -1,   -1,  292,  293,  269,  270,  271,
  272,  273,  274,   -1,  276,  277,  278,  279,  280,  281,
   -1,   -1,  284,  280,  281,   -1,   -1,  284,  290,  286,
  287,  288,   -1,  280,  281,  292,  293,  284,   -1,  286,
  287,  288,   -1,  280,  281,  292,  293,  284,   -1,  286,
  287,  288,   -1,  280,  281,  292,  293,  284,   -1,  286,
  287,  288,   -1,  280,  281,  292,  293,  284,   -1,  286,
  287,  288,   -1,   -1,   -1,  292,  293,  269,  270,  271,
  272,  273,  274,   -1,  276,  277,  111,  112,  113,  114,
  115,  116,
};
static int yyctable[] = {                                     27,
   98,   -1,
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
"GlobalStatement : MethodDeclaration",
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


#line 526 "parser.y"

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
#line 617 "y.tab.c"
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
#line 1013 "y.tab.c"
break;
case 2:
  if (!yytrial)
#line 84 "parser.y"
{
        yyval.stmtvec = new std::vector<std::shared_ptr<ddlbx::ir::NStatement>>();
        yyval.stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1022 "y.tab.c"
break;
case 3:
  if (!yytrial)
#line 88 "parser.y"
{
        yyvsp[-1].stmtvec->push_back(std::shared_ptr<ddlbx::ir::NStatement>(yyvsp[0].stmt));
      }
#line 1030 "y.tab.c"
break;
case 4:
  if (!yytrial)
#line 94 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1038 "y.tab.c"
break;
case 5:
  if (!yytrial)
#line 97 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1046 "y.tab.c"
break;
case 6:
  if (!yytrial)
#line 100 "parser.y"
{
        yyval.stmt = yyvsp[-1].stmt;
      }
#line 1054 "y.tab.c"
break;
case 12:
  if (!yytrial)
#line 111 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NGetModule(*yyvsp[-1].string);
      }
#line 1062 "y.tab.c"
break;
case 13:
  if (!yytrial)
#line 117 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type),
                                                *yyvsp[-5].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)));
      }
#line 1072 "y.tab.c"
break;
case 14:
  if (!yytrial)
#line 125 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type),
                                                *yyvsp[-6].string,
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)),
                                                *yyvsp[-5].stringvec);
      }
#line 1083 "y.tab.c"
break;
case 15:
  if (!yytrial)
#line 134 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>(yyvsp[-1].stmt)),
                                                 std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1092 "y.tab.c"
break;
case 16:
  if (!yytrial)
#line 138 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>(yyvsp[-1].stmt)),
                                                         std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1101 "y.tab.c"
break;
case 17:
  if (!yytrial)
#line 145 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
      }
#line 1109 "y.tab.c"
break;
case 18:
  if (!yytrial)
#line 148 "parser.y"
{
        yyvsp[-2].argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1117 "y.tab.c"
break;
case 19:
  if (!yytrial)
#line 151 "parser.y"
{
        yyval.argvec = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
        yyval.argvec->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>(yyvsp[0].expr)));
      }
#line 1126 "y.tab.c"
break;
case 20:
  if (!yytrial)
#line 158 "parser.y"
{
        yyval.expr = new ddlbx::ir::NArgument(std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), *yyvsp[-2].string);
      }
#line 1134 "y.tab.c"
break;
case 21:
  if (!yytrial)
#line 164 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NObjectDeclaration(*yyvsp[-3].string, *yyvsp[-1].membervec);
      }
#line 1142 "y.tab.c"
break;
case 22:
  if (!yytrial)
#line 167 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NTemplateObjectDeclaration(*yyvsp[-4].string, *yyvsp[-1].membervec, *yyvsp[-3].stringvec);
      }
#line 1150 "y.tab.c"
break;
case 23:
  if (!yytrial)
#line 172 "parser.y"
{
        yyval.member = new ddlbx::ir::NMemberDeclaration(std::make_shared<ddlbx::ir::NType>(*yyvsp[0].string), *yyvsp[-2].string);
      }
#line 1158 "y.tab.c"
break;
case 24:
  if (!yytrial)
#line 178 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
      }
#line 1166 "y.tab.c"
break;
case 25:
  if (!yytrial)
#line 181 "parser.y"
{
        yyvsp[-2].membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1174 "y.tab.c"
break;
case 26:
  if (!yytrial)
#line 184 "parser.y"
{
        yyval.membervec = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
        yyval.membervec->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>(yyvsp[0].member));
      }
#line 1183 "y.tab.c"
break;
case 27:
  if (!yytrial)
#line 191 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NMethodDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[0].type), *yyvsp[-5].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-3].argvec)), *yyvsp[-7].string);
      }
#line 1192 "y.tab.c"
break;
case 28:
  if (!yytrial)
#line 198 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NMethodDeclaration(std::shared_ptr<ddlbx::ir::NMethodDefinition>(dynamic_cast<ddlbx::ir::NMethodDefinition*>(yyvsp[-1].stmt)),
                                               std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1201 "y.tab.c"
break;
case 29:
  if (!yytrial)
#line 205 "parser.y"
{
        ddlbx::ir::NMethodDefinition *funcDef = new ddlbx::ir::NMethodDefinition(
            std::shared_ptr<ddlbx::ir::NType>(yyvsp[-1].type), *yyvsp[-6].string, *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>(yyvsp[-4].argvec)), "");
        ddlbx::ir::NFunctionDeclaration *funcDecl = new ddlbx::ir::NFunctionDeclaration(
            std::shared_ptr<ddlbx::ir::NFunctionDefinition>(funcDef), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
        yyval.stmt = new ddlbx::ir::NTraitMethodDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDeclaration>(funcDecl), *yyvsp[-9].membervec);
      }
#line 1213 "y.tab.c"
break;
case 30:
  if (!yytrial)
#line 214 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1221 "y.tab.c"
break;
case 31:
  if (!yytrial)
#line 217 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NReturnStatement();
      }
#line 1229 "y.tab.c"
break;
case 32:
  if (!yytrial)
#line 223 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1237 "y.tab.c"
break;
case 33:
  if (!yytrial)
#line 226 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(*yyvsp[-4].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec), *yyvsp[-3].stringvec);
      }
#line 1245 "y.tab.c"
break;
case 34:
  if (!yytrial)
#line 229 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NMemberAccess>(dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-3].expr)),
                                                          std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1254 "y.tab.c"
break;
case 35:
  if (!yytrial)
#line 236 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-3].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec));
      }
#line 1262 "y.tab.c"
break;
case 36:
  if (!yytrial)
#line 239 "parser.y"
{
        yyval.expr = new ddlbx::ir::NObjectCreation(*yyvsp[-4].string, std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*yyvsp[-1].exprvec), *yyvsp[-3].stringvec);
      }
#line 1270 "y.tab.c"
break;
case 37:
  if (!yytrial)
#line 245 "parser.y"
{
        yyval.stringvec = yyvsp[-1].stringvec;
      }
#line 1278 "y.tab.c"
break;
case 38:
  if (!yytrial)
#line 251 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
      }
#line 1286 "y.tab.c"
break;
case 39:
  if (!yytrial)
#line 254 "parser.y"
{
        yyvsp[-2].stringvec->push_back(yyvsp[0].type->name);
      }
#line 1294 "y.tab.c"
break;
case 40:
  if (!yytrial)
#line 257 "parser.y"
{
        yyval.stringvec = new std::vector<std::string>();
        yyval.stringvec->push_back(yyvsp[0].type->name);
      }
#line 1303 "y.tab.c"
break;
case 41:
  if (!yytrial)
#line 264 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
      }
#line 1311 "y.tab.c"
break;
case 42:
  if (!yytrial)
#line 267 "parser.y"
{
        yyvsp[-2].exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1319 "y.tab.c"
break;
case 43:
  if (!yytrial)
#line 270 "parser.y"
{
        yyval.exprvec = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
        yyval.exprvec->push_back(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1328 "y.tab.c"
break;
case 44:
  if (!yytrial)
#line 277 "parser.y"
{
        dynamic_cast<ddlbx::ir::NMemberAccess*>(yyvsp[-2].expr)->ids.push_back(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier));
      }
#line 1336 "y.tab.c"
break;
case 45:
  if (!yytrial)
#line 280 "parser.y"
{
        yyval.expr = new ddlbx::ir::NMemberAccess(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), {std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier)});
      }
#line 1344 "y.tab.c"
break;
case 46:
  if (!yytrial)
#line 286 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1352 "y.tab.c"
break;
case 47:
  if (!yytrial)
#line 289 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1360 "y.tab.c"
break;
case 48:
  if (!yytrial)
#line 292 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1368 "y.tab.c"
break;
case 49:
  if (!yytrial)
#line 295 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1376 "y.tab.c"
break;
case 50:
  if (!yytrial)
#line 298 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1384 "y.tab.c"
break;
case 51:
  if (!yytrial)
#line 301 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1392 "y.tab.c"
break;
case 52:
  if (!yytrial)
#line 304 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1400 "y.tab.c"
break;
case 53:
  if (!yytrial)
#line 310 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1408 "y.tab.c"
break;
case 54:
  if (!yytrial)
#line 313 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1416 "y.tab.c"
break;
case 55:
  if (!yytrial)
#line 316 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-1].expr));
      }
#line 1424 "y.tab.c"
break;
case 59:
  if (!yytrial)
#line 325 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-4].identifier),
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr),
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1436 "y.tab.c"
break;
case 60:
  if (!yytrial)
#line 332 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-6].identifier),
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr),
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr),
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1448 "y.tab.c"
break;
case 61:
  if (!yytrial)
#line 339 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-8].identifier),
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-6].expr),
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-4].expr),
                                          std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr),
                                          std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1460 "y.tab.c"
break;
case 62:
  if (!yytrial)
#line 346 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NForStatement(nullptr, nullptr, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), nullptr, std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1468 "y.tab.c"
break;
case 63:
  if (!yytrial)
#line 352 "parser.y"
{
        yyval.stmt = new ddlbx::ir::NOptStatement(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), std::shared_ptr<ddlbx::ir::NBlock>(yyvsp[0].block));
      }
#line 1476 "y.tab.c"
break;
case 64:
  if (!yytrial)
#line 358 "parser.y"
{
        yyval.block = yyvsp[-1].block;
      }
#line 1484 "y.tab.c"
break;
case 65:
  if (!yytrial)
#line 364 "parser.y"
{
        yyval.block = new ddlbx::ir::NBlock();
      }
#line 1492 "y.tab.c"
break;
case 66:
  if (!yytrial)
#line 367 "parser.y"
{
        yyvsp[-1].block->statements.push_back(yyvsp[0].stmt);
      }
#line 1500 "y.tab.c"
break;
case 67:
  if (!yytrial)
#line 373 "parser.y"
{
        std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varList = yyvsp[0].varvec;
        yyval.expr = new ddlbx::ir::NVariableDeclarationList(*varList);
      }
#line 1509 "y.tab.c"
break;
case 68:
  if (!yytrial)
#line 380 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1517 "y.tab.c"
break;
case 69:
  if (!yytrial)
#line 383 "parser.y"
{
        yyvsp[-2].varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1525 "y.tab.c"
break;
case 70:
  if (!yytrial)
#line 386 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>(yyvsp[0].expr))));
      }
#line 1534 "y.tab.c"
break;
case 71:
  if (!yytrial)
#line 390 "parser.y"
{
        yyval.varvec = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        yyval.varvec->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[0].identifier), nullptr));
      }
#line 1543 "y.tab.c"
break;
case 72:
  if (!yytrial)
#line 397 "parser.y"
{
        yyval.expr = new ddlbx::ir::NAssignment(std::shared_ptr<ddlbx::ir::NIdentifier>(yyvsp[-2].identifier), std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1551 "y.tab.c"
break;
case 73:
  if (!yytrial)
#line 403 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1559 "y.tab.c"
break;
case 74:
  if (!yytrial)
#line 406 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1567 "y.tab.c"
break;
case 75:
  if (!yytrial)
#line 409 "parser.y"
{
        yyval.expr = new ddlbx::ir::NUnaryOperator(yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1575 "y.tab.c"
break;
case 76:
  if (!yytrial)
#line 412 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1583 "y.tab.c"
break;
case 77:
  if (!yytrial)
#line 418 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1591 "y.tab.c"
break;
case 78:
  if (!yytrial)
#line 421 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1599 "y.tab.c"
break;
case 79:
  if (!yytrial)
#line 424 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1607 "y.tab.c"
break;
case 80:
  if (!yytrial)
#line 427 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1615 "y.tab.c"
break;
case 81:
  if (!yytrial)
#line 430 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1623 "y.tab.c"
break;
case 82:
  if (!yytrial)
#line 433 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1631 "y.tab.c"
break;
case 83:
  if (!yytrial)
#line 436 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1639 "y.tab.c"
break;
case 84:
  if (!yytrial)
#line 442 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1647 "y.tab.c"
break;
case 85:
  if (!yytrial)
#line 445 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1655 "y.tab.c"
break;
case 86:
  if (!yytrial)
#line 448 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1663 "y.tab.c"
break;
case 87:
  if (!yytrial)
#line 454 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1671 "y.tab.c"
break;
case 88:
  if (!yytrial)
#line 457 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1679 "y.tab.c"
break;
case 89:
  if (!yytrial)
#line 460 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[-2].expr), yyvsp[-1].token, std::shared_ptr<ddlbx::ir::NExpression>(yyvsp[0].expr));
      }
#line 1687 "y.tab.c"
break;
case 90:
  if (!yytrial)
#line 466 "parser.y"
{
        yyval.expr = yyvsp[0].identifier;
      }
#line 1695 "y.tab.c"
break;
case 91:
  if (!yytrial)
#line 469 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1703 "y.tab.c"
break;
case 92:
  if (!yytrial)
#line 472 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1711 "y.tab.c"
break;
case 93:
  if (!yytrial)
#line 475 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1719 "y.tab.c"
break;
case 94:
  if (!yytrial)
#line 478 "parser.y"
{
        yyval.expr = yyvsp[-1].expr;
      }
#line 1727 "y.tab.c"
break;
case 95:
  if (!yytrial)
#line 481 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1735 "y.tab.c"
break;
case 96:
  if (!yytrial)
#line 484 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1743 "y.tab.c"
break;
case 97:
  if (!yytrial)
#line 487 "parser.y"
{
        yyval.expr = yyvsp[0].expr;
      }
#line 1751 "y.tab.c"
break;
case 98:
  if (!yytrial)
#line 493 "parser.y"
{
        yyval.identifier = new ddlbx::ir::NIdentifier(*(yyvsp[0].string));
        delete yyvsp[0].string;
      }
#line 1760 "y.tab.c"
break;
case 99:
  if (!yytrial)
#line 500 "parser.y"
{
        yyval.expr = new ddlbx::ir::NInteger(atol(yyvsp[0].string->c_str()));
      }
#line 1768 "y.tab.c"
break;
case 100:
  if (!yytrial)
#line 503 "parser.y"
{
        yyval.expr = new ddlbx::ir::NFloat(atof(yyvsp[0].string->c_str()));
      }
#line 1776 "y.tab.c"
break;
case 101:
  if (!yytrial)
#line 509 "parser.y"
{
        yyval.expr = new ddlbx::ir::NBoolean(*yyvsp[0].string);
      }
#line 1784 "y.tab.c"
break;
case 102:
  if (!yytrial)
#line 515 "parser.y"
{
        yyval.expr = new ddlbx::ir::NString(*yyvsp[0].string);
      }
#line 1792 "y.tab.c"
break;
case 103:
  if (!yytrial)
#line 521 "parser.y"
{
        yyval.type = new ddlbx::ir::NType(*yyvsp[0].string);
      }
#line 1800 "y.tab.c"
break;
#line 1802 "y.tab.c"
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
