/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <string>
#include <iostream>
#include <vector>
#include "ir/node.hpp"
#include "utils/logger.hpp"

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


#line 97 "src/parser/parser.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_FRAC_NUMBER = 4,                /* FRAC_NUMBER  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_KW_NONE = 8,                    /* KW_NONE  */
  YYSYMBOL_KW_INT = 9,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 10,                  /* KW_FLOAT  */
  YYSYMBOL_KW_BOOL = 11,                   /* KW_BOOL  */
  YYSYMBOL_KW_STRING = 12,                 /* KW_STRING  */
  YYSYMBOL_KW_RETURN = 13,                 /* KW_RETURN  */
  YYSYMBOL_KW_FUNCTION = 14,               /* KW_FUNCTION  */
  YYSYMBOL_KW_VAR = 15,                    /* KW_VAR  */
  YYSYMBOL_KW_OPT = 16,                    /* KW_OPT  */
  YYSYMBOL_KW_FOR = 17,                    /* KW_FOR  */
  YYSYMBOL_KW_OBJECT = 18,                 /* KW_OBJECT  */
  YYSYMBOL_COM_EQ = 19,                    /* COM_EQ  */
  YYSYMBOL_COM_NE = 20,                    /* COM_NE  */
  YYSYMBOL_COM_LE = 21,                    /* COM_LE  */
  YYSYMBOL_COM_GE = 22,                    /* COM_GE  */
  YYSYMBOL_COM_LT = 23,                    /* COM_LT  */
  YYSYMBOL_COM_GT = 24,                    /* COM_GT  */
  YYSYMBOL_OP_ASSIGN = 25,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_PLUS = 26,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 27,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULT = 28,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 29,                    /* OP_DIV  */
  YYSYMBOL_OP_AND = 30,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 31,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 32,                    /* OP_NOT  */
  YYSYMBOL_LPAREN = 33,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 34,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 35,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 36,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 37,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_DOT = 40,                       /* DOT  */
  YYSYMBOL_KW_FROM = 41,                   /* KW_FROM  */
  YYSYMBOL_KW_TO = 42,                     /* KW_TO  */
  YYSYMBOL_KW_STEP = 43,                   /* KW_STEP  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_Program = 45,                   /* Program  */
  YYSYMBOL_GlobalStatements = 46,          /* GlobalStatements  */
  YYSYMBOL_GlobalStatement = 47,           /* GlobalStatement  */
  YYSYMBOL_FunctionDefinition = 48,        /* FunctionDefinition  */
  YYSYMBOL_FunctionDeclaration = 49,       /* FunctionDeclaration  */
  YYSYMBOL_FPDeclarationList = 50,         /* FPDeclarationList  */
  YYSYMBOL_FPDeclaration = 51,             /* FPDeclaration  */
  YYSYMBOL_ObjectDeclaration = 52,         /* ObjectDeclaration  */
  YYSYMBOL_MemberDeclaration = 53,         /* MemberDeclaration  */
  YYSYMBOL_MemberDeclarationList = 54,     /* MemberDeclarationList  */
  YYSYMBOL_MethodDeclaration = 55,         /* MethodDeclaration  */
  YYSYMBOL_ReturnStatement = 56,           /* ReturnStatement  */
  YYSYMBOL_FunctionCallExpression = 57,    /* FunctionCallExpression  */
  YYSYMBOL_FCParameterList = 58,           /* FCParameterList  */
  YYSYMBOL_MemberAccessExpression = 59,    /* MemberAccessExpression  */
  YYSYMBOL_Primary = 60,                   /* Primary  */
  YYSYMBOL_Statement = 61,                 /* Statement  */
  YYSYMBOL_ForStatement = 62,              /* ForStatement  */
  YYSYMBOL_OptStatement = 63,              /* OptStatement  */
  YYSYMBOL_Block = 64,                     /* Block  */
  YYSYMBOL_Statements = 65,                /* Statements  */
  YYSYMBOL_DeclarationExpression = 66,     /* DeclarationExpression  */
  YYSYMBOL_DeclarationList = 67,           /* DeclarationList  */
  YYSYMBOL_AssignExpression = 68,          /* AssignExpression  */
  YYSYMBOL_Expression = 69,                /* Expression  */
  YYSYMBOL_Condition = 70,                 /* Condition  */
  YYSYMBOL_Calculation = 71,               /* Calculation  */
  YYSYMBOL_Term = 72,                      /* Term  */
  YYSYMBOL_Factor = 73,                    /* Factor  */
  YYSYMBOL_Identifier = 74,                /* Identifier  */
  YYSYMBOL_Numeric = 75,                   /* Numeric  */
  YYSYMBOL_Boolean = 76,                   /* Boolean  */
  YYSYMBOL_String = 77,                    /* String  */
  YYSYMBOL_Type = 78                       /* Type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    80,    84,    90,    93,    94,    95,    99,
     107,   114,   117,   120,   127,   133,   138,   144,   147,   150,
     157,   167,   170,   176,   179,   186,   189,   192,   199,   202,
     208,   211,   214,   217,   220,   223,   229,   232,   235,   238,
     239,   240,   244,   251,   258,   265,   271,   277,   283,   286,
     292,   299,   302,   305,   309,   316,   322,   325,   328,   331,
     337,   340,   343,   346,   349,   352,   355,   361,   364,   367,
     373,   376,   379,   385,   388,   391,   394,   397,   400,   403,
     409,   416,   419,   425,   431,   437,   440,   443,   446,   449
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER",
  "FRAC_NUMBER", "IDENTIFIER", "STRING", "BOOL", "KW_NONE", "KW_INT",
  "KW_FLOAT", "KW_BOOL", "KW_STRING", "KW_RETURN", "KW_FUNCTION", "KW_VAR",
  "KW_OPT", "KW_FOR", "KW_OBJECT", "COM_EQ", "COM_NE", "COM_LE", "COM_GE",
  "COM_LT", "COM_GT", "OP_ASSIGN", "OP_PLUS", "OP_MINUS", "OP_MULT",
  "OP_DIV", "OP_AND", "OP_OR", "OP_NOT", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "SEMICOLON", "COMMA", "COLON", "DOT", "KW_FROM", "KW_TO",
  "KW_STEP", "$accept", "Program", "GlobalStatements", "GlobalStatement",
  "FunctionDefinition", "FunctionDeclaration", "FPDeclarationList",
  "FPDeclaration", "ObjectDeclaration", "MemberDeclaration",
  "MemberDeclarationList", "MethodDeclaration", "ReturnStatement",
  "FunctionCallExpression", "FCParameterList", "MemberAccessExpression",
  "Primary", "Statement", "ForStatement", "OptStatement", "Block",
  "Statements", "DeclarationExpression", "DeclarationList",
  "AssignExpression", "Expression", "Condition", "Calculation", "Term",
  "Factor", "Identifier", "Numeric", "Boolean", "String", "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      32,     6,     9,    45,    32,   -64,   -25,   -64,   -64,   -64,
     -24,    20,   -64,   -64,   -64,   -64,   -64,    35,    54,    75,
      62,    48,    13,   -64,    59,    58,   -64,    47,   -64,   -64,
     -64,   -64,   -64,     1,   100,    85,   101,    16,    16,   -64,
     -64,    93,     2,    96,   -64,   -64,   -64,   102,   103,   104,
      33,    80,    86,   -64,     4,    97,    98,   105,   112,   107,
      35,    35,   112,   -64,    75,   -64,   106,     3,   109,   -64,
     117,    21,    16,   -64,   110,    16,   100,   100,   -64,   -64,
     -64,    16,    16,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    16,    16,   -64,   -64,   -64,   -64,   -64,
     -64,   112,   -64,    22,   -64,   -64,   -64,   100,   114,   115,
      49,   111,    36,   -64,   -64,   -64,   -64,   -64,     5,     5,
       5,     5,     5,     5,    86,    86,   -64,   -64,   -64,    91,
     -64,   113,   -64,   117,   118,   118,    16,    16,   -64,    16,
     -64,   112,   -64,   -64,   108,    -4,   -64,   118,    16,   118,
      16,   -64,   116,   -64,   120,    16,   118,   121,   -64,   118,
     -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     0,     7,     8,     6,
       0,     0,     1,     4,    48,     5,    10,    11,     0,    17,
       0,     0,     0,    13,     0,     0,    19,     0,    81,    82,
      80,    84,    83,     0,     0,     0,     0,     0,     0,    47,
      41,    78,    79,     0,    49,    40,    39,     0,     0,     0,
      59,    66,    67,    70,    73,    74,    75,    76,     0,     0,
       0,    11,     0,    15,     0,    22,     0,    73,    50,    53,
      54,     0,     0,    58,     0,    25,     0,     0,    37,    38,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    87,    85,    86,    88,    89,
      14,     0,    12,     0,    16,    18,    21,     0,     0,     0,
      73,    77,     0,    27,    28,    29,    56,    57,    62,    65,
      63,    64,    60,    61,    68,    69,    71,    72,    55,     0,
       9,     0,    52,    51,     0,     0,     0,     0,    24,     0,
      23,     0,    46,    45,     0,     0,    26,     0,     0,     0,
       0,    20,     0,    42,     0,     0,     0,     0,    43,     0,
      44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   -64,   152,   -64,   -64,    99,   119,   -64,    94,
     -64,   -64,   -64,   -64,    63,   -64,   -64,   -64,   -64,   -64,
     -63,   -64,   -64,   -64,   -31,   -20,    90,    25,    37,    40,
     -19,   -64,   -64,   -64,   -60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    22,    23,     8,    26,
      27,     9,    40,    41,   112,    42,    43,    44,    45,    46,
      16,    20,    47,    68,    48,   113,    50,    51,    52,    53,
      67,    55,    56,    57,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    54,   104,    69,    28,    29,    30,    31,    32,    17,
      14,    10,    15,    66,    11,    70,    18,    73,    74,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    93,
     149,    89,    90,    37,    38,    75,    94,    94,    65,   150,
      21,   130,    76,   -30,   -30,    12,     1,    59,    37,    38,
       2,    60,   109,   110,    38,    19,   131,   114,   115,    24,
      60,   116,   117,    81,    82,    28,    29,    30,    31,    32,
     138,   142,   143,   128,   139,    33,   132,    34,    35,    36,
      25,   147,    94,    63,   151,    64,   153,    58,   133,   -30,
     136,   137,    61,   158,    37,    38,   160,    62,    39,    83,
      84,    85,    86,    87,    88,    30,    89,    90,   118,   119,
     120,   121,   122,   123,    91,    92,   144,   145,    71,   146,
      95,    96,    97,    98,    99,   140,   124,   125,   152,   139,
     154,   126,   127,   -35,    72,   157,    77,   -31,   -32,    78,
      79,    80,    93,   106,   111,   -33,   101,   107,   134,   135,
     148,   -34,   141,    14,   156,   159,    13,   129,   105,   155,
     103,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102
};

static const yytype_int16 yycheck[] =
{
      20,    20,    62,    34,     3,     4,     5,     6,     7,    33,
      35,     5,    37,    33,     5,    34,    40,    37,    38,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    25,
      34,    26,    27,    32,    33,    33,    33,    33,    37,    43,
       5,   101,    40,    40,    40,     0,    14,    34,    32,    33,
      18,    38,    72,    72,    33,    35,    34,    76,    77,     5,
      38,    81,    82,    30,    31,     3,     4,     5,     6,     7,
      34,   134,   135,    93,    38,    13,   107,    15,    16,    17,
       5,   141,    33,    36,   147,    38,   149,    39,   107,    40,
      41,    42,    33,   156,    32,    33,   159,    39,    36,    19,
      20,    21,    22,    23,    24,     5,    26,    27,    83,    84,
      85,    86,    87,    88,    28,    29,   136,   137,    33,   139,
       8,     9,    10,    11,    12,    34,    89,    90,   148,    38,
     150,    91,    92,    40,    33,   155,    40,    40,    40,    37,
      37,    37,    25,    37,    34,    40,    39,    38,    34,    34,
      42,    40,    39,    35,    34,    34,     4,    94,    64,    43,
      61,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    18,    45,    46,    47,    48,    49,    52,    55,
       5,     5,     0,    47,    35,    37,    64,    33,    40,    35,
      65,     5,    50,    51,     5,     5,    53,    54,     3,     4,
       5,     6,     7,    13,    15,    16,    17,    32,    33,    36,
      56,    57,    59,    60,    61,    62,    63,    66,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    39,    34,
      38,    33,    39,    36,    38,    37,    69,    74,    67,    68,
      74,    33,    33,    69,    69,    33,    40,    40,    37,    37,
      37,    30,    31,    19,    20,    21,    22,    23,    24,    26,
      27,    28,    29,    25,    33,     8,     9,    10,    11,    12,
      78,    39,    51,    50,    78,    53,    37,    38,    70,    69,
      74,    34,    58,    69,    74,    74,    69,    69,    71,    71,
      71,    71,    71,    71,    72,    72,    73,    73,    69,    58,
      78,    34,    68,    74,    34,    34,    41,    42,    34,    38,
      34,    39,    64,    64,    69,    69,    69,    78,    42,    34,
      43,    64,    69,    64,    69,    43,    34,    69,    64,    34,
      64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    48,
      49,    50,    50,    50,    51,    52,    53,    54,    54,    54,
      55,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    63,    64,    65,    65,
      66,    67,    67,    67,    67,    68,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    75,    75,    76,    77,    78,    78,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     7,
       2,     0,     3,     1,     3,     5,     3,     0,     3,     1,
      10,     3,     2,     4,     4,     0,     3,     1,     3,     3,
       1,     1,     1,     1,     3,     1,     2,     2,     2,     1,
       1,     1,     7,     9,    11,     5,     5,     3,     0,     2,
       2,     3,     3,     1,     1,     3,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: GlobalStatements  */
#line 72 "parser.y"
                       {
        (yyval.program) = new ddlbx::ir::NProgram();
        (yyval.program)->statements = *(yyvsp[0].stmtvec);
        program = (yyval.program);
      }
#line 1282 "src/parser/parser.cc"
    break;

  case 3: /* GlobalStatements: GlobalStatement  */
#line 80 "parser.y"
                      {
        (yyval.stmtvec) = new std::vector<std::shared_ptr<ddlbx::ir::NStatement>>();
        (yyval.stmtvec)->push_back(std::shared_ptr<ddlbx::ir::NStatement>((yyvsp[0].stmt)));
      }
#line 1291 "src/parser/parser.cc"
    break;

  case 4: /* GlobalStatements: GlobalStatements GlobalStatement  */
#line 84 "parser.y"
                                       {
        (yyvsp[-1].stmtvec)->push_back(std::shared_ptr<ddlbx::ir::NStatement>((yyvsp[0].stmt)));
      }
#line 1299 "src/parser/parser.cc"
    break;

  case 5: /* GlobalStatement: FunctionDefinition SEMICOLON  */
#line 90 "parser.y"
                                   {
        (yyval.stmt) = (yyvsp[-1].stmt);
      }
#line 1307 "src/parser/parser.cc"
    break;

  case 9: /* FunctionDefinition: KW_FUNCTION IDENTIFIER LPAREN FPDeclarationList RPAREN COLON Type  */
#line 99 "parser.y"
                                                                        {
        (yyval.stmt) = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>((yyvsp[0].type)), 
                                                *(yyvsp[-5].string),
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>((yyvsp[-3].argvec))));
      }
#line 1317 "src/parser/parser.cc"
    break;

  case 10: /* FunctionDeclaration: FunctionDefinition Block  */
#line 107 "parser.y"
                               {
        (yyval.stmt) = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>((yyvsp[-1].stmt))),
                                                 std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1326 "src/parser/parser.cc"
    break;

  case 11: /* FPDeclarationList: %empty  */
#line 114 "parser.y"
                  {
        (yyval.argvec) = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
      }
#line 1334 "src/parser/parser.cc"
    break;

  case 12: /* FPDeclarationList: FPDeclarationList COMMA FPDeclaration  */
#line 117 "parser.y"
                                            {
        (yyvsp[-2].argvec)->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>((yyvsp[0].expr))));
      }
#line 1342 "src/parser/parser.cc"
    break;

  case 13: /* FPDeclarationList: FPDeclaration  */
#line 120 "parser.y"
                    {
        (yyval.argvec) = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
        (yyval.argvec)->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>((yyvsp[0].expr))));
      }
#line 1351 "src/parser/parser.cc"
    break;

  case 14: /* FPDeclaration: IDENTIFIER COLON Type  */
#line 127 "parser.y"
                            {
        (yyval.expr) = new ddlbx::ir::NArgument(std::shared_ptr<ddlbx::ir::NType>((yyvsp[0].type)), *(yyvsp[-2].string));
      }
#line 1359 "src/parser/parser.cc"
    break;

  case 15: /* ObjectDeclaration: KW_OBJECT IDENTIFIER LBRACE MemberDeclarationList RBRACE  */
#line 133 "parser.y"
                                                               {
        (yyval.stmt) = new ddlbx::ir::NObjectDeclaration(*(yyvsp[-3].string), *(yyvsp[-1].membervec));
      }
#line 1367 "src/parser/parser.cc"
    break;

  case 16: /* MemberDeclaration: IDENTIFIER COLON Type  */
#line 138 "parser.y"
                            {
        (yyval.member) = new ddlbx::ir::NMemberDeclaration(std::shared_ptr<ddlbx::ir::NType>((yyvsp[0].type)), *(yyvsp[-2].string));
      }
#line 1375 "src/parser/parser.cc"
    break;

  case 17: /* MemberDeclarationList: %empty  */
#line 144 "parser.y"
                  {
        (yyval.membervec) = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
      }
#line 1383 "src/parser/parser.cc"
    break;

  case 18: /* MemberDeclarationList: MemberDeclarationList COMMA MemberDeclaration  */
#line 147 "parser.y"
                                                    {
        (yyvsp[-2].membervec)->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>((yyvsp[0].member)));
      }
#line 1391 "src/parser/parser.cc"
    break;

  case 19: /* MemberDeclarationList: MemberDeclaration  */
#line 150 "parser.y"
                        {
        (yyval.membervec) = new std::vector<std::shared_ptr<ddlbx::ir::NMemberDeclaration>>();
        (yyval.membervec)->push_back(std::shared_ptr<ddlbx::ir::NMemberDeclaration>((yyvsp[0].member)));
      }
#line 1400 "src/parser/parser.cc"
    break;

  case 20: /* MethodDeclaration: KW_FUNCTION IDENTIFIER DOT IDENTIFIER LPAREN FPDeclarationList RPAREN COLON Type Block  */
#line 157 "parser.y"
                                                                                             {
        ddlbx::ir::NFunctionDefinition *funcDef = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>((yyvsp[-1].type)), 
                                                                        *(yyvsp[-6].string), 
                                                                        *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>((yyvsp[-4].argvec))));
        ddlbx::ir::NFunctionDeclaration *funcDecl = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(funcDef), 
                                                                           std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
        (yyval.stmt) = new ddlbx::ir::NMethodDeclaration(*(yyvsp[-8].string), std::shared_ptr<ddlbx::ir::NFunctionDeclaration>(funcDecl));
      }
#line 1413 "src/parser/parser.cc"
    break;

  case 21: /* ReturnStatement: KW_RETURN Expression SEMICOLON  */
#line 167 "parser.y"
                                     {
        (yyval.stmt) = new ddlbx::ir::NReturnStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-1].expr)));
      }
#line 1421 "src/parser/parser.cc"
    break;

  case 22: /* ReturnStatement: KW_RETURN SEMICOLON  */
#line 170 "parser.y"
                          {
        (yyval.stmt) = new ddlbx::ir::NReturnStatement();
      }
#line 1429 "src/parser/parser.cc"
    break;

  case 23: /* FunctionCallExpression: Identifier LPAREN FCParameterList RPAREN  */
#line 176 "parser.y"
                                               {
        (yyval.expr) = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-3].identifier)), std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*(yyvsp[-1].exprvec)));
      }
#line 1437 "src/parser/parser.cc"
    break;

  case 24: /* FunctionCallExpression: MemberAccessExpression LPAREN FCParameterList RPAREN  */
#line 179 "parser.y"
                                                           {
        (yyval.expr) = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NMemberAccess>(dynamic_cast<ddlbx::ir::NMemberAccess*>((yyvsp[-3].expr))),
                                                          std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*(yyvsp[-1].exprvec)));
      }
#line 1446 "src/parser/parser.cc"
    break;

  case 25: /* FCParameterList: %empty  */
#line 186 "parser.y"
                  {
        (yyval.exprvec) = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
      }
#line 1454 "src/parser/parser.cc"
    break;

  case 26: /* FCParameterList: FCParameterList COMMA Expression  */
#line 189 "parser.y"
                                       {
        (yyvsp[-2].exprvec)->push_back(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1462 "src/parser/parser.cc"
    break;

  case 27: /* FCParameterList: Expression  */
#line 192 "parser.y"
                 {
        (yyval.exprvec) = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
        (yyval.exprvec)->push_back(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1471 "src/parser/parser.cc"
    break;

  case 28: /* MemberAccessExpression: MemberAccessExpression DOT Identifier  */
#line 199 "parser.y"
                                            {
        dynamic_cast<ddlbx::ir::NMemberAccess*>((yyvsp[-2].expr))->ids.push_back(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[0].identifier)));
      }
#line 1479 "src/parser/parser.cc"
    break;

  case 29: /* MemberAccessExpression: Primary DOT Identifier  */
#line 202 "parser.y"
                             {
        (yyval.expr) = new ddlbx::ir::NMemberAccess(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), {std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[0].identifier))});
      }
#line 1487 "src/parser/parser.cc"
    break;

  case 30: /* Primary: Identifier  */
#line 208 "parser.y"
                 {
        (yyval.expr) = (yyvsp[0].identifier);
      }
#line 1495 "src/parser/parser.cc"
    break;

  case 31: /* Primary: Numeric  */
#line 211 "parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1503 "src/parser/parser.cc"
    break;

  case 32: /* Primary: Boolean  */
#line 214 "parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1511 "src/parser/parser.cc"
    break;

  case 33: /* Primary: String  */
#line 217 "parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1519 "src/parser/parser.cc"
    break;

  case 34: /* Primary: LPAREN Expression RPAREN  */
#line 220 "parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
      }
#line 1527 "src/parser/parser.cc"
    break;

  case 35: /* Primary: FunctionCallExpression  */
#line 223 "parser.y"
                             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1535 "src/parser/parser.cc"
    break;

  case 36: /* Statement: Expression SEMICOLON  */
#line 229 "parser.y"
                           {
        (yyval.stmt) = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-1].expr)));
      }
#line 1543 "src/parser/parser.cc"
    break;

  case 37: /* Statement: DeclarationExpression SEMICOLON  */
#line 232 "parser.y"
                                      {
        (yyval.stmt) = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-1].expr)));
      }
#line 1551 "src/parser/parser.cc"
    break;

  case 38: /* Statement: AssignExpression SEMICOLON  */
#line 235 "parser.y"
                                 {
        (yyval.stmt) = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-1].expr)));
      }
#line 1559 "src/parser/parser.cc"
    break;

  case 42: /* ForStatement: KW_FOR LPAREN Identifier KW_TO Expression RPAREN Block  */
#line 244 "parser.y"
                                                             {
        (yyval.stmt) = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-4].identifier)), 
                                          nullptr,
                                          std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), 
                                          nullptr, 
                                          std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1571 "src/parser/parser.cc"
    break;

  case 43: /* ForStatement: KW_FOR LPAREN Identifier KW_TO Expression KW_STEP Expression RPAREN Block  */
#line 251 "parser.y"
                                                                                {
        (yyval.stmt) = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-6].identifier)), 
                                          nullptr, 
                                          std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-4].expr)), 
                                          std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), 
                                          std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1583 "src/parser/parser.cc"
    break;

  case 44: /* ForStatement: KW_FOR LPAREN Identifier KW_FROM Expression KW_TO Expression KW_STEP Expression RPAREN Block  */
#line 258 "parser.y"
                                                                                                   {
        (yyval.stmt) = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-8].identifier)), 
                                          std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-6].expr)), 
                                          std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-4].expr)), 
                                          std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), 
                                          std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1595 "src/parser/parser.cc"
    break;

  case 45: /* ForStatement: KW_FOR LPAREN Expression RPAREN Block  */
#line 265 "parser.y"
                                            {
        (yyval.stmt) = new ddlbx::ir::NForStatement(nullptr, nullptr, std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), nullptr, std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1603 "src/parser/parser.cc"
    break;

  case 46: /* OptStatement: KW_OPT LPAREN Condition RPAREN Block  */
#line 271 "parser.y"
                                           {
        (yyval.stmt) = new ddlbx::ir::NOptStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1611 "src/parser/parser.cc"
    break;

  case 47: /* Block: LBRACE Statements RBRACE  */
#line 277 "parser.y"
                               {
        (yyval.block) = (yyvsp[-1].block);
      }
#line 1619 "src/parser/parser.cc"
    break;

  case 48: /* Statements: %empty  */
#line 283 "parser.y"
                  {
        (yyval.block) = new ddlbx::ir::NBlock();
      }
#line 1627 "src/parser/parser.cc"
    break;

  case 49: /* Statements: Statements Statement  */
#line 286 "parser.y"
                           {
        (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt));
      }
#line 1635 "src/parser/parser.cc"
    break;

  case 50: /* DeclarationExpression: KW_VAR DeclarationList  */
#line 292 "parser.y"
                             {
        std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varList = (yyvsp[0].varvec);
        (yyval.expr) = new ddlbx::ir::NVariableDeclarationList(*varList);
      }
#line 1644 "src/parser/parser.cc"
    break;

  case 51: /* DeclarationList: DeclarationList COMMA Identifier  */
#line 299 "parser.y"
                                       {
        (yyvsp[-2].varvec)->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[0].identifier)), nullptr));
      }
#line 1652 "src/parser/parser.cc"
    break;

  case 52: /* DeclarationList: DeclarationList COMMA AssignExpression  */
#line 302 "parser.y"
                                             {
        (yyvsp[-2].varvec)->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>((yyvsp[0].expr)))));
      }
#line 1660 "src/parser/parser.cc"
    break;

  case 53: /* DeclarationList: AssignExpression  */
#line 305 "parser.y"
                       {
        (yyval.varvec) = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        (yyval.varvec)->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>((yyvsp[0].expr)))));
      }
#line 1669 "src/parser/parser.cc"
    break;

  case 54: /* DeclarationList: Identifier  */
#line 309 "parser.y"
                 {
        (yyval.varvec) = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        (yyval.varvec)->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[0].identifier)), nullptr));
      }
#line 1678 "src/parser/parser.cc"
    break;

  case 55: /* AssignExpression: Identifier OP_ASSIGN Expression  */
#line 316 "parser.y"
                                      {
        (yyval.expr) = new ddlbx::ir::NAssignment(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-2].identifier)), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1686 "src/parser/parser.cc"
    break;

  case 56: /* Expression: Condition OP_AND Expression  */
#line 322 "parser.y"
                                  {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1694 "src/parser/parser.cc"
    break;

  case 57: /* Expression: Condition OP_OR Expression  */
#line 325 "parser.y"
                                 {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1702 "src/parser/parser.cc"
    break;

  case 58: /* Expression: OP_NOT Expression  */
#line 328 "parser.y"
                        {
        (yyval.expr) = new ddlbx::ir::NUnaryOperator((yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1710 "src/parser/parser.cc"
    break;

  case 59: /* Expression: Condition  */
#line 331 "parser.y"
                {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1718 "src/parser/parser.cc"
    break;

  case 60: /* Condition: Calculation COM_LT Calculation  */
#line 337 "parser.y"
                                     {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1726 "src/parser/parser.cc"
    break;

  case 61: /* Condition: Calculation COM_GT Calculation  */
#line 340 "parser.y"
                                     {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1734 "src/parser/parser.cc"
    break;

  case 62: /* Condition: Calculation COM_EQ Calculation  */
#line 343 "parser.y"
                                     {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1742 "src/parser/parser.cc"
    break;

  case 63: /* Condition: Calculation COM_LE Calculation  */
#line 346 "parser.y"
                                     {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1750 "src/parser/parser.cc"
    break;

  case 64: /* Condition: Calculation COM_GE Calculation  */
#line 349 "parser.y"
                                     {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1758 "src/parser/parser.cc"
    break;

  case 65: /* Condition: Calculation COM_NE Calculation  */
#line 352 "parser.y"
                                     {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1766 "src/parser/parser.cc"
    break;

  case 66: /* Condition: Calculation  */
#line 355 "parser.y"
                  {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1774 "src/parser/parser.cc"
    break;

  case 67: /* Calculation: Term  */
#line 361 "parser.y"
           {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1782 "src/parser/parser.cc"
    break;

  case 68: /* Calculation: Calculation OP_PLUS Term  */
#line 364 "parser.y"
                               {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1790 "src/parser/parser.cc"
    break;

  case 69: /* Calculation: Calculation OP_MINUS Term  */
#line 367 "parser.y"
                                {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1798 "src/parser/parser.cc"
    break;

  case 70: /* Term: Factor  */
#line 373 "parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1806 "src/parser/parser.cc"
    break;

  case 71: /* Term: Term OP_MULT Factor  */
#line 376 "parser.y"
                          {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1814 "src/parser/parser.cc"
    break;

  case 72: /* Term: Term OP_DIV Factor  */
#line 379 "parser.y"
                         {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1822 "src/parser/parser.cc"
    break;

  case 73: /* Factor: Identifier  */
#line 385 "parser.y"
                 {
        (yyval.expr) = (yyvsp[0].identifier);
      }
#line 1830 "src/parser/parser.cc"
    break;

  case 74: /* Factor: Numeric  */
#line 388 "parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1838 "src/parser/parser.cc"
    break;

  case 75: /* Factor: Boolean  */
#line 391 "parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1846 "src/parser/parser.cc"
    break;

  case 76: /* Factor: String  */
#line 394 "parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1854 "src/parser/parser.cc"
    break;

  case 77: /* Factor: LPAREN Expression RPAREN  */
#line 397 "parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
      }
#line 1862 "src/parser/parser.cc"
    break;

  case 78: /* Factor: FunctionCallExpression  */
#line 400 "parser.y"
                             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1870 "src/parser/parser.cc"
    break;

  case 79: /* Factor: MemberAccessExpression  */
#line 403 "parser.y"
                             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1878 "src/parser/parser.cc"
    break;

  case 80: /* Identifier: IDENTIFIER  */
#line 409 "parser.y"
                 {
        (yyval.identifier) = new ddlbx::ir::NIdentifier(*((yyvsp[0].string)));
        delete (yyvsp[0].string);
      }
#line 1887 "src/parser/parser.cc"
    break;

  case 81: /* Numeric: NUMBER  */
#line 416 "parser.y"
             {
        (yyval.expr) = new ddlbx::ir::NInteger(atol((yyvsp[0].string)->c_str()));
      }
#line 1895 "src/parser/parser.cc"
    break;

  case 82: /* Numeric: FRAC_NUMBER  */
#line 419 "parser.y"
                  {
        (yyval.expr) = new ddlbx::ir::NFloat(atof((yyvsp[0].string)->c_str()));
      }
#line 1903 "src/parser/parser.cc"
    break;

  case 83: /* Boolean: BOOL  */
#line 425 "parser.y"
           {
        (yyval.expr) = new ddlbx::ir::NBoolean(*(yyvsp[0].string));
      }
#line 1911 "src/parser/parser.cc"
    break;

  case 84: /* String: STRING  */
#line 431 "parser.y"
             {
        (yyval.expr) = new ddlbx::ir::NString(*(yyvsp[0].string));
      }
#line 1919 "src/parser/parser.cc"
    break;

  case 85: /* Type: KW_INT  */
#line 437 "parser.y"
             {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1927 "src/parser/parser.cc"
    break;

  case 86: /* Type: KW_FLOAT  */
#line 440 "parser.y"
               {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1935 "src/parser/parser.cc"
    break;

  case 87: /* Type: KW_NONE  */
#line 443 "parser.y"
              {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1943 "src/parser/parser.cc"
    break;

  case 88: /* Type: KW_BOOL  */
#line 446 "parser.y"
              {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1951 "src/parser/parser.cc"
    break;

  case 89: /* Type: KW_STRING  */
#line 449 "parser.y"
                {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1959 "src/parser/parser.cc"
    break;


#line 1963 "src/parser/parser.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 453 "parser.y"
  

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
