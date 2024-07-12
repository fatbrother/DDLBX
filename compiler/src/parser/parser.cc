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


#line 96 "src/parser/parser.cc"

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
  YYSYMBOL_COM_EQ = 18,                    /* COM_EQ  */
  YYSYMBOL_COM_NE = 19,                    /* COM_NE  */
  YYSYMBOL_COM_LE = 20,                    /* COM_LE  */
  YYSYMBOL_COM_GE = 21,                    /* COM_GE  */
  YYSYMBOL_COM_LT = 22,                    /* COM_LT  */
  YYSYMBOL_COM_GT = 23,                    /* COM_GT  */
  YYSYMBOL_OP_ASSIGN = 24,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_PLUS = 25,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 26,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULT = 27,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 28,                    /* OP_DIV  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 30,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 31,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 32,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_COLON = 35,                     /* COLON  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_Program = 38,                   /* Program  */
  YYSYMBOL_GlobalStatements = 39,          /* GlobalStatements  */
  YYSYMBOL_GlobalStatement = 40,           /* GlobalStatement  */
  YYSYMBOL_FunctionDefinition = 41,        /* FunctionDefinition  */
  YYSYMBOL_FunctionDeclaration = 42,       /* FunctionDeclaration  */
  YYSYMBOL_FPDeclarationList = 43,         /* FPDeclarationList  */
  YYSYMBOL_FPDeclaration = 44,             /* FPDeclaration  */
  YYSYMBOL_ReturnStatement = 45,           /* ReturnStatement  */
  YYSYMBOL_FunctionCallExpression = 46,    /* FunctionCallExpression  */
  YYSYMBOL_FCParameterList = 47,           /* FCParameterList  */
  YYSYMBOL_MemberAccessExpression = 48,    /* MemberAccessExpression  */
  YYSYMBOL_Primary = 49,                   /* Primary  */
  YYSYMBOL_Statement = 50,                 /* Statement  */
  YYSYMBOL_ForStatement = 51,              /* ForStatement  */
  YYSYMBOL_ForInitExpression = 52,         /* ForInitExpression  */
  YYSYMBOL_OptStatement = 53,              /* OptStatement  */
  YYSYMBOL_Block = 54,                     /* Block  */
  YYSYMBOL_Statements = 55,                /* Statements  */
  YYSYMBOL_DeclarationExpression = 56,     /* DeclarationExpression  */
  YYSYMBOL_DeclarationList = 57,           /* DeclarationList  */
  YYSYMBOL_AssignExpression = 58,          /* AssignExpression  */
  YYSYMBOL_Condition = 59,                 /* Condition  */
  YYSYMBOL_Expression = 60,                /* Expression  */
  YYSYMBOL_Term = 61,                      /* Term  */
  YYSYMBOL_Factor = 62,                    /* Factor  */
  YYSYMBOL_Identifier = 63,                /* Identifier  */
  YYSYMBOL_Numeric = 64,                   /* Numeric  */
  YYSYMBOL_Boolean = 65,                   /* Boolean  */
  YYSYMBOL_String = 66,                    /* String  */
  YYSYMBOL_Type = 67                       /* Type  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    74,    78,    84,    85,    91,    99,   106,
     109,   112,   119,   125,   128,   134,   137,   144,   147,   150,
     157,   160,   166,   169,   172,   175,   178,   181,   187,   190,
     193,   196,   197,   198,   202,   208,   211,   217,   223,   229,
     232,   238,   245,   248,   251,   255,   262,   268,   271,   274,
     277,   280,   283,   288,   291,   294,   300,   303,   306,   312,
     315,   318,   321,   324,   327,   330,   336,   343,   346,   352,
     358,   364,   367,   370,   373,   376
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
  "KW_OPT", "KW_FOR", "COM_EQ", "COM_NE", "COM_LE", "COM_GE", "COM_LT",
  "COM_GT", "OP_ASSIGN", "OP_PLUS", "OP_MINUS", "OP_MULT", "OP_DIV",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "COLON",
  "DOT", "$accept", "Program", "GlobalStatements", "GlobalStatement",
  "FunctionDefinition", "FunctionDeclaration", "FPDeclarationList",
  "FPDeclaration", "ReturnStatement", "FunctionCallExpression",
  "FCParameterList", "MemberAccessExpression", "Primary", "Statement",
  "ForStatement", "ForInitExpression", "OptStatement", "Block",
  "Statements", "DeclarationExpression", "DeclarationList",
  "AssignExpression", "Condition", "Expression", "Term", "Factor",
  "Identifier", "Numeric", "Boolean", "String", "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,    24,    36,    13,  -105,   -27,  -105,  -105,    12,  -105,
    -105,  -105,  -105,  -105,    24,    15,    45,  -105,    27,  -105,
    -105,  -105,  -105,     5,    24,    16,    43,    47,  -105,  -105,
      53,    -3,    71,  -105,  -105,  -105,    75,    76,    11,  -105,
    -105,  -105,    69,    24,    88,    47,  -105,    74,    -3,    32,
     -11,  -105,    10,    77,    78,    79,    82,  -105,    87,    47,
       0,    30,  -105,    47,    24,    24,  -105,  -105,    47,    47,
      88,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    52,    47,
      47,  -105,    47,    47,    24,    89,    48,    84,  -105,  -105,
      87,  -105,    50,    68,  -105,  -105,    68,    51,  -105,    85,
     -11,   -11,  -105,  -105,  -105,    87,    81,    47,    47,    47,
      47,    47,    47,    47,  -105,    47,  -105,  -105,    68,    68,
      68,    68,    68,    68,    90,    68,    24,    92,    81,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     5,    66,     0,     1,
       4,    39,     6,     8,     9,     0,     0,    11,     0,    67,
      68,    70,    69,     0,     0,     0,     0,     0,    38,    33,
      27,     0,     0,    40,    32,    31,     0,     0,    22,    23,
      24,    25,     0,     0,     0,     0,    14,    64,    65,     0,
      53,    56,    59,    60,    61,    62,    41,    44,    45,     0,
       0,     0,    30,    17,     0,     0,    28,    29,     0,    17,
       0,    10,    73,    71,    72,    74,    75,    12,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    35,    36,
       0,    26,     0,    19,    20,    21,    46,     0,     7,    63,
      54,    55,    57,    58,    43,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,    15,    37,    49,    52,
      50,    51,    47,    48,     0,    18,     0,     0,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,  -105,   115,  -105,  -105,  -105,    83,  -105,   105,
      55,   112,  -105,  -105,  -105,  -105,  -105,  -104,  -105,    70,
    -105,   -23,    18,   -20,    22,    23,    -1,   113,   114,   117,
      63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     6,    16,    17,    29,    47,
      92,    48,    32,    33,    34,    87,    35,    13,    15,    36,
      56,    37,    85,    86,    50,    51,    52,    53,    54,    55,
      77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       8,    57,   117,    49,    11,     7,    12,    61,    19,    20,
       7,    21,    22,    18,    38,    24,    82,    83,    19,    20,
       7,    21,    22,    58,   129,    78,    63,     1,    23,     7,
      24,    25,    26,    64,    45,    68,     9,    89,    46,    69,
      69,    14,    18,    93,    27,    59,   -22,    28,    96,    93,
      19,    20,     7,    21,    22,    79,    80,    79,    80,    90,
      91,   104,    44,    94,    95,    81,   107,   108,   109,   110,
     111,   112,    60,    79,    80,    42,    45,    79,    80,    43,
     114,   116,    99,   105,   115,   115,    62,   118,   119,   120,
     121,   122,   123,    79,    80,   125,    72,    73,    74,    75,
      76,   100,   101,   127,    70,   102,   103,    65,    66,    67,
     -27,    68,    11,   -23,   -24,   -25,    84,   113,    10,   106,
      30,   -26,   128,   126,    97,    90,    71,    31,    39,    40,
      88,   124,    41,    98
};

static const yytype_uint8 yycheck[] =
{
       1,    24,   106,    23,    31,     5,    33,    27,     3,     4,
       5,     6,     7,    14,    15,    15,    27,    28,     3,     4,
       5,     6,     7,    24,   128,    45,    29,    14,    13,     5,
      15,    16,    17,    36,    29,    24,     0,    60,    33,    29,
      29,    29,    43,    63,    29,    29,    36,    32,    68,    69,
       3,     4,     5,     6,     7,    25,    26,    25,    26,    60,
      30,    84,    35,    64,    65,    33,    18,    19,    20,    21,
      22,    23,    29,    25,    26,    30,    29,    25,    26,    34,
      30,    30,    30,    84,    34,    34,    33,   107,   108,   109,
     110,   111,   112,    25,    26,   115,     8,     9,    10,    11,
      12,    79,    80,   126,    35,    82,    83,    36,    33,    33,
      36,    24,    31,    36,    36,    36,    34,    33,     3,    30,
      15,    36,    30,    33,    69,   126,    43,    15,    15,    15,
      60,   113,    15,    70
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    38,    39,    40,    41,    42,     5,    63,     0,
      40,    31,    33,    54,    29,    55,    43,    44,    63,     3,
       4,     6,     7,    13,    15,    16,    17,    29,    32,    45,
      46,    48,    49,    50,    51,    53,    56,    58,    63,    64,
      65,    66,    30,    34,    35,    29,    33,    46,    48,    60,
      61,    62,    63,    64,    65,    66,    57,    58,    63,    29,
      29,    60,    33,    29,    36,    36,    33,    33,    24,    29,
      35,    44,     8,     9,    10,    11,    12,    67,    60,    25,
      26,    33,    27,    28,    34,    59,    60,    52,    56,    58,
      63,    30,    47,    60,    63,    63,    60,    47,    67,    30,
      61,    61,    62,    62,    58,    63,    30,    18,    19,    20,
      21,    22,    23,    33,    30,    34,    30,    54,    60,    60,
      60,    60,    60,    60,    59,    60,    33,    58,    30,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    42,    43,
      43,    43,    44,    45,    45,    46,    46,    47,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    50,    50,
      50,    50,    50,    50,    51,    52,    52,    53,    54,    55,
      55,    56,    57,    57,    57,    57,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    63,    64,    64,    65,
      66,    67,    67,    67,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     7,     2,     0,
       3,     1,     3,     3,     2,     4,     4,     0,     3,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     2,     2,
       2,     1,     1,     1,     9,     1,     1,     5,     3,     0,
       2,     2,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 66 "parser.y"
                       {
        (yyval.program) = new ddlbx::ir::NProgram();
        (yyval.program)->statements = *(yyvsp[0].stmtvec);
        program = (yyval.program);
      }
#line 1245 "src/parser/parser.cc"
    break;

  case 3: /* GlobalStatements: GlobalStatement  */
#line 74 "parser.y"
                      {
        (yyval.stmtvec) = new std::vector<std::shared_ptr<ddlbx::ir::NStatement>>();
        (yyval.stmtvec)->push_back(std::shared_ptr<ddlbx::ir::NStatement>((yyvsp[0].stmt)));
      }
#line 1254 "src/parser/parser.cc"
    break;

  case 4: /* GlobalStatements: GlobalStatements GlobalStatement  */
#line 78 "parser.y"
                                       {
        (yyvsp[-1].stmtvec)->push_back(std::shared_ptr<ddlbx::ir::NStatement>((yyvsp[0].stmt)));
      }
#line 1262 "src/parser/parser.cc"
    break;

  case 6: /* GlobalStatement: FunctionDefinition SEMICOLON  */
#line 85 "parser.y"
                                   {
        (yyval.stmt) = (yyvsp[-1].stmt);
      }
#line 1270 "src/parser/parser.cc"
    break;

  case 7: /* FunctionDefinition: KW_FUNCTION Identifier LPAREN FPDeclarationList RPAREN COLON Type  */
#line 91 "parser.y"
                                                                        {
        (yyval.stmt) = new ddlbx::ir::NFunctionDefinition(std::shared_ptr<ddlbx::ir::NType>((yyvsp[0].type)), 
                                                std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-5].identifier)), 
                                                *(dynamic_cast<std::vector<std::shared_ptr<ddlbx::ir::NArgument>>*>((yyvsp[-3].argvec))));
      }
#line 1280 "src/parser/parser.cc"
    break;

  case 8: /* FunctionDeclaration: FunctionDefinition Block  */
#line 99 "parser.y"
                               {
        (yyval.stmt) = new ddlbx::ir::NFunctionDeclaration(std::shared_ptr<ddlbx::ir::NFunctionDefinition>(dynamic_cast<ddlbx::ir::NFunctionDefinition*>((yyvsp[-1].stmt))),
                                                 std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1289 "src/parser/parser.cc"
    break;

  case 9: /* FPDeclarationList: %empty  */
#line 106 "parser.y"
                  {
        (yyval.argvec) = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
      }
#line 1297 "src/parser/parser.cc"
    break;

  case 10: /* FPDeclarationList: FPDeclarationList COMMA FPDeclaration  */
#line 109 "parser.y"
                                            {
        (yyvsp[-2].argvec)->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>((yyvsp[0].expr))));
      }
#line 1305 "src/parser/parser.cc"
    break;

  case 11: /* FPDeclarationList: FPDeclaration  */
#line 112 "parser.y"
                    {
        (yyval.argvec) = new std::vector<std::shared_ptr<ddlbx::ir::NArgument>>();
        (yyval.argvec)->push_back(std::shared_ptr<ddlbx::ir::NArgument>(dynamic_cast<ddlbx::ir::NArgument*>((yyvsp[0].expr))));
      }
#line 1314 "src/parser/parser.cc"
    break;

  case 12: /* FPDeclaration: Identifier COLON Type  */
#line 119 "parser.y"
                            {
        (yyval.expr) = new ddlbx::ir::NArgument(std::shared_ptr<ddlbx::ir::NType>((yyvsp[0].type)), std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-2].identifier)));
      }
#line 1322 "src/parser/parser.cc"
    break;

  case 13: /* ReturnStatement: KW_RETURN Expression SEMICOLON  */
#line 125 "parser.y"
                                     {
        (yyval.stmt) = new ddlbx::ir::NReturnStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-1].expr)));
      }
#line 1330 "src/parser/parser.cc"
    break;

  case 14: /* ReturnStatement: KW_RETURN SEMICOLON  */
#line 128 "parser.y"
                          {
        (yyval.stmt) = new ddlbx::ir::NReturnStatement();
      }
#line 1338 "src/parser/parser.cc"
    break;

  case 15: /* FunctionCallExpression: Identifier LPAREN FCParameterList RPAREN  */
#line 134 "parser.y"
                                               {
        (yyval.expr) = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-3].identifier)), std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*(yyvsp[-1].exprvec)));
      }
#line 1346 "src/parser/parser.cc"
    break;

  case 16: /* FunctionCallExpression: MemberAccessExpression LPAREN FCParameterList RPAREN  */
#line 137 "parser.y"
                                                           {
        (yyval.expr) = new ddlbx::ir::NFunctionCall(std::shared_ptr<ddlbx::ir::NMemberAccess>(dynamic_cast<ddlbx::ir::NMemberAccess*>((yyvsp[-3].expr))),
                                                          std::vector<std::shared_ptr<ddlbx::ir::NExpression>>(*(yyvsp[-1].exprvec)));
      }
#line 1355 "src/parser/parser.cc"
    break;

  case 17: /* FCParameterList: %empty  */
#line 144 "parser.y"
                  {
        (yyval.exprvec) = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
      }
#line 1363 "src/parser/parser.cc"
    break;

  case 18: /* FCParameterList: FCParameterList COMMA Expression  */
#line 147 "parser.y"
                                       {
        (yyvsp[-2].exprvec)->push_back(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1371 "src/parser/parser.cc"
    break;

  case 19: /* FCParameterList: Expression  */
#line 150 "parser.y"
                 {
        (yyval.exprvec) = new std::vector<std::shared_ptr<ddlbx::ir::NExpression>>();
        (yyval.exprvec)->push_back(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1380 "src/parser/parser.cc"
    break;

  case 20: /* MemberAccessExpression: MemberAccessExpression DOT Identifier  */
#line 157 "parser.y"
                                            {
        dynamic_cast<ddlbx::ir::NMemberAccess*>((yyvsp[-2].expr))->ids.push_back(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[0].identifier)));
      }
#line 1388 "src/parser/parser.cc"
    break;

  case 21: /* MemberAccessExpression: Primary DOT Identifier  */
#line 160 "parser.y"
                             {
        (yyval.expr) = new ddlbx::ir::NMemberAccess(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), {std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[0].identifier))});
      }
#line 1396 "src/parser/parser.cc"
    break;

  case 22: /* Primary: Identifier  */
#line 166 "parser.y"
                 {
        (yyval.expr) = (yyvsp[0].identifier);
      }
#line 1404 "src/parser/parser.cc"
    break;

  case 23: /* Primary: Numeric  */
#line 169 "parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1412 "src/parser/parser.cc"
    break;

  case 24: /* Primary: Boolean  */
#line 172 "parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1420 "src/parser/parser.cc"
    break;

  case 25: /* Primary: String  */
#line 175 "parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1428 "src/parser/parser.cc"
    break;

  case 26: /* Primary: LPAREN Expression RPAREN  */
#line 178 "parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
      }
#line 1436 "src/parser/parser.cc"
    break;

  case 27: /* Primary: FunctionCallExpression  */
#line 181 "parser.y"
                             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1444 "src/parser/parser.cc"
    break;

  case 28: /* Statement: DeclarationExpression SEMICOLON  */
#line 187 "parser.y"
                                      {
        (yyval.stmt) = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-1].expr)));
      }
#line 1452 "src/parser/parser.cc"
    break;

  case 29: /* Statement: AssignExpression SEMICOLON  */
#line 190 "parser.y"
                                 {
        (yyval.stmt) = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-1].expr)));
      }
#line 1460 "src/parser/parser.cc"
    break;

  case 30: /* Statement: FunctionCallExpression SEMICOLON  */
#line 193 "parser.y"
                                       {
        (yyval.stmt) = new ddlbx::ir::NExpressionStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-1].expr)));
      }
#line 1468 "src/parser/parser.cc"
    break;

  case 34: /* ForStatement: KW_FOR LPAREN ForInitExpression SEMICOLON Condition SEMICOLON AssignExpression RPAREN Block  */
#line 202 "parser.y"
                                                                                                  {
        (yyval.stmt) = new ddlbx::ir::NForStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-6].expr)), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-4].expr)), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1476 "src/parser/parser.cc"
    break;

  case 35: /* ForInitExpression: DeclarationExpression  */
#line 208 "parser.y"
                            {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1484 "src/parser/parser.cc"
    break;

  case 36: /* ForInitExpression: AssignExpression  */
#line 211 "parser.y"
                       {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1492 "src/parser/parser.cc"
    break;

  case 37: /* OptStatement: KW_OPT LPAREN Condition RPAREN Block  */
#line 217 "parser.y"
                                           {
        (yyval.stmt) = new ddlbx::ir::NOptStatement(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), std::shared_ptr<ddlbx::ir::NBlock>((yyvsp[0].block)));
      }
#line 1500 "src/parser/parser.cc"
    break;

  case 38: /* Block: LBRACE Statements RBRACE  */
#line 223 "parser.y"
                               {
        (yyval.block) = (yyvsp[-1].block);
      }
#line 1508 "src/parser/parser.cc"
    break;

  case 39: /* Statements: %empty  */
#line 229 "parser.y"
                  {
        (yyval.block) = new ddlbx::ir::NBlock();
      }
#line 1516 "src/parser/parser.cc"
    break;

  case 40: /* Statements: Statements Statement  */
#line 232 "parser.y"
                           {
        (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt));
      }
#line 1524 "src/parser/parser.cc"
    break;

  case 41: /* DeclarationExpression: KW_VAR DeclarationList  */
#line 238 "parser.y"
                             {
        std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>> *varList = (yyvsp[0].varvec);
        (yyval.expr) = new ddlbx::ir::NVariableDeclarationList(*varList);
      }
#line 1533 "src/parser/parser.cc"
    break;

  case 42: /* DeclarationList: DeclarationList COMMA Identifier  */
#line 245 "parser.y"
                                       {
        (yyvsp[-2].varvec)->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[0].identifier)), nullptr));
      }
#line 1541 "src/parser/parser.cc"
    break;

  case 43: /* DeclarationList: DeclarationList COMMA AssignExpression  */
#line 248 "parser.y"
                                             {
        (yyvsp[-2].varvec)->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>((yyvsp[0].expr)))));
      }
#line 1549 "src/parser/parser.cc"
    break;

  case 44: /* DeclarationList: AssignExpression  */
#line 251 "parser.y"
                       {
        (yyval.varvec) = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        (yyval.varvec)->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NAssignment>(dynamic_cast<ddlbx::ir::NAssignment*>((yyvsp[0].expr)))));
      }
#line 1558 "src/parser/parser.cc"
    break;

  case 45: /* DeclarationList: Identifier  */
#line 255 "parser.y"
                 {
        (yyval.varvec) = new std::vector<std::shared_ptr<ddlbx::ir::NVariableDeclaration>>();
        (yyval.varvec)->push_back(std::make_shared<ddlbx::ir::NVariableDeclaration>(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[0].identifier)), nullptr));
      }
#line 1567 "src/parser/parser.cc"
    break;

  case 46: /* AssignExpression: Identifier OP_ASSIGN Expression  */
#line 262 "parser.y"
                                      {
        (yyval.expr) = new ddlbx::ir::NAssignment(std::shared_ptr<ddlbx::ir::NIdentifier>((yyvsp[-2].identifier)), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1575 "src/parser/parser.cc"
    break;

  case 47: /* Condition: Expression COM_LT Expression  */
#line 268 "parser.y"
                                   {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1583 "src/parser/parser.cc"
    break;

  case 48: /* Condition: Expression COM_GT Expression  */
#line 271 "parser.y"
                                   {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1591 "src/parser/parser.cc"
    break;

  case 49: /* Condition: Expression COM_EQ Expression  */
#line 274 "parser.y"
                                   {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1599 "src/parser/parser.cc"
    break;

  case 50: /* Condition: Expression COM_LE Expression  */
#line 277 "parser.y"
                                   {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1607 "src/parser/parser.cc"
    break;

  case 51: /* Condition: Expression COM_GE Expression  */
#line 280 "parser.y"
                                   {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1615 "src/parser/parser.cc"
    break;

  case 52: /* Condition: Expression COM_NE Expression  */
#line 283 "parser.y"
                                   {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1623 "src/parser/parser.cc"
    break;

  case 53: /* Expression: Term  */
#line 288 "parser.y"
           {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1631 "src/parser/parser.cc"
    break;

  case 54: /* Expression: Expression OP_PLUS Term  */
#line 291 "parser.y"
                              {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1639 "src/parser/parser.cc"
    break;

  case 55: /* Expression: Expression OP_MINUS Term  */
#line 294 "parser.y"
                               {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1647 "src/parser/parser.cc"
    break;

  case 56: /* Term: Factor  */
#line 300 "parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1655 "src/parser/parser.cc"
    break;

  case 57: /* Term: Term OP_MULT Factor  */
#line 303 "parser.y"
                          {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1663 "src/parser/parser.cc"
    break;

  case 58: /* Term: Term OP_DIV Factor  */
#line 306 "parser.y"
                         {
        (yyval.expr) = new ddlbx::ir::NBinaryOperator(std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[-2].expr)), (yyvsp[-1].token), std::shared_ptr<ddlbx::ir::NExpression>((yyvsp[0].expr)));
      }
#line 1671 "src/parser/parser.cc"
    break;

  case 59: /* Factor: Identifier  */
#line 312 "parser.y"
                 {
        (yyval.expr) = (yyvsp[0].identifier);
      }
#line 1679 "src/parser/parser.cc"
    break;

  case 60: /* Factor: Numeric  */
#line 315 "parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1687 "src/parser/parser.cc"
    break;

  case 61: /* Factor: Boolean  */
#line 318 "parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1695 "src/parser/parser.cc"
    break;

  case 62: /* Factor: String  */
#line 321 "parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1703 "src/parser/parser.cc"
    break;

  case 63: /* Factor: LPAREN Expression RPAREN  */
#line 324 "parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
      }
#line 1711 "src/parser/parser.cc"
    break;

  case 64: /* Factor: FunctionCallExpression  */
#line 327 "parser.y"
                             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1719 "src/parser/parser.cc"
    break;

  case 65: /* Factor: MemberAccessExpression  */
#line 330 "parser.y"
                             {
        (yyval.expr) = (yyvsp[0].expr);
      }
#line 1727 "src/parser/parser.cc"
    break;

  case 66: /* Identifier: IDENTIFIER  */
#line 336 "parser.y"
                 {
        (yyval.identifier) = new ddlbx::ir::NIdentifier(*((yyvsp[0].string)));
        delete (yyvsp[0].string);
      }
#line 1736 "src/parser/parser.cc"
    break;

  case 67: /* Numeric: NUMBER  */
#line 343 "parser.y"
             {
        (yyval.expr) = new ddlbx::ir::NInteger(atol((yyvsp[0].string)->c_str()));
      }
#line 1744 "src/parser/parser.cc"
    break;

  case 68: /* Numeric: FRAC_NUMBER  */
#line 346 "parser.y"
                  {
        (yyval.expr) = new ddlbx::ir::NFloat(atof((yyvsp[0].string)->c_str()));
      }
#line 1752 "src/parser/parser.cc"
    break;

  case 69: /* Boolean: BOOL  */
#line 352 "parser.y"
           {
        (yyval.expr) = new ddlbx::ir::NBoolean(*(yyvsp[0].string));
      }
#line 1760 "src/parser/parser.cc"
    break;

  case 70: /* String: STRING  */
#line 358 "parser.y"
             {
        (yyval.expr) = new ddlbx::ir::NString(*(yyvsp[0].string));
      }
#line 1768 "src/parser/parser.cc"
    break;

  case 71: /* Type: KW_INT  */
#line 364 "parser.y"
             {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1776 "src/parser/parser.cc"
    break;

  case 72: /* Type: KW_FLOAT  */
#line 367 "parser.y"
               {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1784 "src/parser/parser.cc"
    break;

  case 73: /* Type: KW_NONE  */
#line 370 "parser.y"
              {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1792 "src/parser/parser.cc"
    break;

  case 74: /* Type: KW_BOOL  */
#line 373 "parser.y"
              {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1800 "src/parser/parser.cc"
    break;

  case 75: /* Type: KW_STRING  */
#line 376 "parser.y"
                {
        (yyval.type) = new ddlbx::ir::NType(*(yyvsp[0].string));
      }
#line 1808 "src/parser/parser.cc"
    break;


#line 1812 "src/parser/parser.cc"

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

#line 380 "parser.y"
  

void yyerror(const char *s) {
    std::cout << "Error: " << s << " at line " << yylineno << ", near '" << yytext << "'\n\n";
    return;
}

void parseText(const char* text) {
    YY_BUFFER_STATE buffer = yy_scan_string(text);
    yyparse();
    yy_delete_buffer(buffer);
    return;
}
