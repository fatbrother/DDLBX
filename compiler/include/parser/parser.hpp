/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_INCLUDE_PARSER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    FRAC_NUMBER = 259,             /* FRAC_NUMBER  */
    IDENTIFIER = 260,              /* IDENTIFIER  */
    STRING = 261,                  /* STRING  */
    BOOL = 262,                    /* BOOL  */
    KW_NONE = 263,                 /* KW_NONE  */
    KW_INT = 264,                  /* KW_INT  */
    KW_FLOAT = 265,                /* KW_FLOAT  */
    KW_BOOL = 266,                 /* KW_BOOL  */
    KW_STRING = 267,               /* KW_STRING  */
    KW_RETURN = 268,               /* KW_RETURN  */
    KW_FUNCTION = 269,             /* KW_FUNCTION  */
    KW_VAR = 270,                  /* KW_VAR  */
    KW_OPT = 271,                  /* KW_OPT  */
    KW_FOR = 272,                  /* KW_FOR  */
    COM_EQ = 273,                  /* COM_EQ  */
    COM_NE = 274,                  /* COM_NE  */
    COM_LE = 275,                  /* COM_LE  */
    COM_GE = 276,                  /* COM_GE  */
    COM_LT = 277,                  /* COM_LT  */
    COM_GT = 278,                  /* COM_GT  */
    OP_ASSIGN = 279,               /* OP_ASSIGN  */
    OP_PLUS = 280,                 /* OP_PLUS  */
    OP_MINUS = 281,                /* OP_MINUS  */
    OP_MULT = 282,                 /* OP_MULT  */
    OP_DIV = 283,                  /* OP_DIV  */
    OP_AND = 284,                  /* OP_AND  */
    OP_OR = 285,                   /* OP_OR  */
    OP_NOT = 286,                  /* OP_NOT  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    LBRACE = 289,                  /* LBRACE  */
    RBRACE = 290,                  /* RBRACE  */
    SEMICOLON = 291,               /* SEMICOLON  */
    COMMA = 292,                   /* COMMA  */
    COLON = 293,                   /* COLON  */
    DOT = 294,                     /* DOT  */
    KW_FROM = 295,                 /* KW_FROM  */
    KW_TO = 296,                   /* KW_TO  */
    KW_STEP = 297                  /* KW_STEP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"

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

#line 121 "include/parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_PARSER_PARSER_HPP_INCLUDED  */
