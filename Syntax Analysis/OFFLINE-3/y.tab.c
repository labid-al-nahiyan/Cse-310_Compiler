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
#line 1 "1905110.y"

#include<bits/stdc++.h>
#include "1905110_SymbolInfo.cpp"
#include "1905110_ScopeTable.cpp"
#include "1905110_SymbolTable.cpp"
     /* yyparse() stack type */

using namespace std;
typedef long long ll;


ofstream logout;
ofstream errout;

extern int line_count,interal_line,error;
extern FILE *yyin;

SymbolTable *symTable = new SymbolTable(10);
ScopeTable *sc = symTable->EnterScope();

void yyerror(char *s){
	printf("%s\n",s);
}

int yylex(void);


#line 99 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    DO = 258,                      /* DO  */
    CHAR = 259,                    /* CHAR  */
    BREAK = 260,                   /* BREAK  */
    DOUBLE = 261,                  /* DOUBLE  */
    SWITCH = 262,                  /* SWITCH  */
    CASE = 263,                    /* CASE  */
    DEFAULT = 264,                 /* DEFAULT  */
    CONTINUE = 265,                /* CONTINUE  */
    NEWLINE = 266,                 /* NEWLINE  */
    SEMICOLON = 267,               /* SEMICOLON  */
    ID = 268,                      /* ID  */
    PLUS = 269,                    /* PLUS  */
    MINUS = 270,                   /* MINUS  */
    SLASH = 271,                   /* SLASH  */
    ASTERISK = 272,                /* ASTERISK  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    LCURL = 275,                   /* LCURL  */
    RCURL = 276,                   /* RCURL  */
    LSQUARE = 277,                 /* LSQUARE  */
    RSQUARE = 278,                 /* RSQUARE  */
    COMMA = 279,                   /* COMMA  */
    NOT = 280,                     /* NOT  */
    KEYWORD = 281,                 /* KEYWORD  */
    CONST_INT = 282,               /* CONST_INT  */
    CONST_FLOAT = 283,             /* CONST_FLOAT  */
    IF = 284,                      /* IF  */
    FOR = 285,                     /* FOR  */
    ELSE = 286,                    /* ELSE  */
    INT = 287,                     /* INT  */
    FLOAT = 288,                   /* FLOAT  */
    VOID = 289,                    /* VOID  */
    LTHIRD = 290,                  /* LTHIRD  */
    RTHIRD = 291,                  /* RTHIRD  */
    WHILE = 292,                   /* WHILE  */
    PRINTLN = 293,                 /* PRINTLN  */
    RETURN = 294,                  /* RETURN  */
    ADDOP = 295,                   /* ADDOP  */
    LOGICOP = 296,                 /* LOGICOP  */
    DECOP = 297,                   /* DECOP  */
    RELOP = 298,                   /* RELOP  */
    ASSIGNOP = 299,                /* ASSIGNOP  */
    MULOP = 300,                   /* MULOP  */
    INCOP = 301                    /* INCOP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DO 258
#define CHAR 259
#define BREAK 260
#define DOUBLE 261
#define SWITCH 262
#define CASE 263
#define DEFAULT 264
#define CONTINUE 265
#define NEWLINE 266
#define SEMICOLON 267
#define ID 268
#define PLUS 269
#define MINUS 270
#define SLASH 271
#define ASTERISK 272
#define LPAREN 273
#define RPAREN 274
#define LCURL 275
#define RCURL 276
#define LSQUARE 277
#define RSQUARE 278
#define COMMA 279
#define NOT 280
#define KEYWORD 281
#define CONST_INT 282
#define CONST_FLOAT 283
#define IF 284
#define FOR 285
#define ELSE 286
#define INT 287
#define FLOAT 288
#define VOID 289
#define LTHIRD 290
#define RTHIRD 291
#define WHILE 292
#define PRINTLN 293
#define RETURN 294
#define ADDOP 295
#define LOGICOP 296
#define DECOP 297
#define RELOP 298
#define ASSIGNOP 299
#define MULOP 300
#define INCOP 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DO = 3,                         /* DO  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_BREAK = 5,                      /* BREAK  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_SWITCH = 7,                     /* SWITCH  */
  YYSYMBOL_CASE = 8,                       /* CASE  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_NEWLINE = 11,                   /* NEWLINE  */
  YYSYMBOL_SEMICOLON = 12,                 /* SEMICOLON  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_PLUS = 14,                      /* PLUS  */
  YYSYMBOL_MINUS = 15,                     /* MINUS  */
  YYSYMBOL_SLASH = 16,                     /* SLASH  */
  YYSYMBOL_ASTERISK = 17,                  /* ASTERISK  */
  YYSYMBOL_LPAREN = 18,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 19,                    /* RPAREN  */
  YYSYMBOL_LCURL = 20,                     /* LCURL  */
  YYSYMBOL_RCURL = 21,                     /* RCURL  */
  YYSYMBOL_LSQUARE = 22,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 23,                   /* RSQUARE  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_KEYWORD = 26,                   /* KEYWORD  */
  YYSYMBOL_CONST_INT = 27,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 28,               /* CONST_FLOAT  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_FOR = 30,                       /* FOR  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_FLOAT = 33,                     /* FLOAT  */
  YYSYMBOL_VOID = 34,                      /* VOID  */
  YYSYMBOL_LTHIRD = 35,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 36,                    /* RTHIRD  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_PRINTLN = 38,                   /* PRINTLN  */
  YYSYMBOL_RETURN = 39,                    /* RETURN  */
  YYSYMBOL_ADDOP = 40,                     /* ADDOP  */
  YYSYMBOL_LOGICOP = 41,                   /* LOGICOP  */
  YYSYMBOL_DECOP = 42,                     /* DECOP  */
  YYSYMBOL_RELOP = 43,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 44,                  /* ASSIGNOP  */
  YYSYMBOL_MULOP = 45,                     /* MULOP  */
  YYSYMBOL_INCOP = 46,                     /* INCOP  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_start = 48,                     /* start  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_unit = 50,                      /* unit  */
  YYSYMBOL_func_declaration = 51,          /* func_declaration  */
  YYSYMBOL_func_definition = 52,           /* func_definition  */
  YYSYMBOL_parameter_list = 53,            /* parameter_list  */
  YYSYMBOL_compound_statement = 54,        /* compound_statement  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_var_declaration = 56,           /* var_declaration  */
  YYSYMBOL_type_specifier = 57,            /* type_specifier  */
  YYSYMBOL_declaration_list = 58,          /* declaration_list  */
  YYSYMBOL_statements = 59,                /* statements  */
  YYSYMBOL_statement = 60,                 /* statement  */
  YYSYMBOL_expression_statement = 61,      /* expression_statement  */
  YYSYMBOL_variable = 62,                  /* variable  */
  YYSYMBOL_expression = 63,                /* expression  */
  YYSYMBOL_logic_expression = 64,          /* logic_expression  */
  YYSYMBOL_rel_expression = 65,            /* rel_expression  */
  YYSYMBOL_simple_expression = 66,         /* simple_expression  */
  YYSYMBOL_term = 67,                      /* term  */
  YYSYMBOL_unary_expression = 68,          /* unary_expression  */
  YYSYMBOL_factor = 69,                    /* factor  */
  YYSYMBOL_argument_list = 70,             /* argument_list  */
  YYSYMBOL_arguments = 71                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    37,    38,    40,    41,    42,    44,    45,
      48,    52,    58,    59,    60,    61,    65,    64,    75,    78,
      80,    81,    82,    85,    90,    93,    97,   102,   103,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   117,   118,
     120,   121,   124,   125,   128,   129,   132,   133,   135,   136,
     138,   139,   142,   143,   144,   147,   148,   149,   150,   151,
     152,   153,   156,   157,   160,   161
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
  "\"end of file\"", "error", "\"invalid token\"", "DO", "CHAR", "BREAK",
  "DOUBLE", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "NEWLINE",
  "SEMICOLON", "ID", "PLUS", "MINUS", "SLASH", "ASTERISK", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LSQUARE", "RSQUARE", "COMMA", "NOT",
  "KEYWORD", "CONST_INT", "CONST_FLOAT", "IF", "FOR", "ELSE", "INT",
  "FLOAT", "VOID", "LTHIRD", "RTHIRD", "WHILE", "PRINTLN", "RETURN",
  "ADDOP", "LOGICOP", "DECOP", "RELOP", "ASSIGNOP", "MULOP", "INCOP",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "parameter_list", "compound_statement", "$@1",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      68,   -65,   -65,   -65,     5,    68,   -65,   -65,   -65,   -65,
      -6,   -65,   -65,   -12,     6,    25,    12,   -65,    19,    33,
      17,    38,    26,    20,   -65,    51,   -65,    40,    68,   -65,
     -65,    34,   -65,    79,   -65,   -65,    67,    42,   -65,     3,
      97,    97,   -65,   -65,    69,    80,    85,    87,    97,    97,
     -65,   -65,   101,    56,   -65,   -65,    29,   108,   -65,    82,
      39,    76,   -65,   -65,   -65,   -65,    97,    97,   107,   -26,
     -65,    97,    -3,    97,   114,   116,   -65,    94,   -65,   -65,
     -65,    97,   -65,   -65,    97,    97,    97,    97,   -65,   111,
     109,    95,   -65,   113,    -3,   115,   117,   -65,   -65,   -65,
      76,    98,   -65,   -65,    97,   -65,    79,    97,    79,   123,
     -65,   110,   120,   -65,   -65,    79,    79,   -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    20,    21,    22,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    25,     0,     0,     0,    19,     0,     0,
       0,    15,     0,    23,     9,    16,    11,     0,     0,    14,
      26,     0,    18,     0,     8,    10,    13,     0,    38,    40,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
      31,    29,     0,     0,    27,    30,    55,     0,    42,    44,
      46,    48,    50,    54,    12,    24,    63,     0,     0,    55,
      53,     0,     0,     0,     0,     0,    52,    25,    17,    28,
      61,     0,    60,    39,     0,     0,     0,     0,    65,     0,
      62,     0,    57,     0,     0,     0,     0,    37,    43,    45,
      49,    47,    51,    56,     0,    41,     0,     0,     0,     0,
      64,    33,     0,    35,    36,     0,     0,    34,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   135,   -65,   -65,   -65,     7,   -65,    65,
      14,   -65,   -65,   -52,   -59,   -38,   -40,   -64,    58,    57,
      59,   -37,   -65,   -65,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    20,    50,    33,    51,
      52,    14,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    89,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    79,    88,    69,    70,    11,    15,    13,    75,    38,
      39,    69,    76,    94,    10,    40,    80,    98,    17,    10,
      82,    66,    41,    16,    42,    43,    26,    91,    69,    21,
      18,    93,    23,    95,    35,   107,    27,    49,    67,    22,
     110,    28,    36,    69,    19,    24,    69,    69,    69,    69,
     102,    29,    34,    25,   111,    31,   113,     1,     2,     3,
      25,    37,    30,   117,   118,     9,    69,   112,    38,    39,
       9,    80,    32,    81,    40,    82,    25,    78,    65,    85,
      64,    41,    86,    42,    43,    44,    45,    71,     1,     2,
       3,    38,    39,    46,    47,    48,    49,    40,    72,    25,
       1,     2,     3,    73,    41,    74,    42,    43,    44,    45,
      39,     1,     2,     3,    77,    40,    46,    47,    48,    49,
      83,    87,    41,    84,    42,    43,    92,    96,    97,    16,
     103,   105,   106,   104,   108,   114,   109,    49,    85,   116,
      12,   115,    99,   101,   100
};

static const yytype_int8 yycheck[] =
{
      40,    53,    66,    41,    41,     0,    18,    13,    48,    12,
      13,    49,    49,    72,     0,    18,    42,    81,    12,     5,
      46,    18,    25,    35,    27,    28,    19,    67,    66,    15,
      24,    71,    13,    73,    27,    94,    19,    40,    35,    27,
     104,    24,    28,    81,    19,    12,    84,    85,    86,    87,
      87,    13,    12,    20,   106,    35,   108,    32,    33,    34,
      20,    27,    36,   115,   116,     0,   104,   107,    12,    13,
       5,    42,    21,    44,    18,    46,    20,    21,    36,    40,
      13,    25,    43,    27,    28,    29,    30,    18,    32,    33,
      34,    12,    13,    37,    38,    39,    40,    18,    18,    20,
      32,    33,    34,    18,    25,    18,    27,    28,    29,    30,
      13,    32,    33,    34,    13,    18,    37,    38,    39,    40,
      12,    45,    25,    41,    27,    28,    19,    13,    12,    35,
      19,    36,    19,    24,    19,    12,    19,    40,    40,    19,
       5,    31,    84,    86,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    33,    34,    48,    49,    50,    51,    52,    56,
      57,     0,    50,    13,    58,    18,    35,    12,    24,    19,
      53,    57,    27,    13,    12,    20,    54,    19,    24,    13,
      36,    35,    21,    55,    12,    54,    57,    27,    12,    13,
      18,    25,    27,    28,    29,    30,    37,    38,    39,    40,
      54,    56,    57,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    13,    36,    18,    35,    63,    62,
      68,    18,    18,    18,    18,    63,    68,    13,    21,    60,
      42,    44,    46,    12,    41,    40,    43,    45,    64,    70,
      71,    63,    19,    63,    61,    63,    13,    12,    64,    65,
      67,    66,    68,    19,    24,    36,    19,    61,    19,    19,
      64,    60,    63,    60,    12,    31,    19,    60,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    55,    54,    54,    56,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     0,     4,     2,     3,
       1,     1,     1,     3,     6,     1,     4,     1,     2,     1,
       1,     1,     7,     5,     7,     5,     5,     3,     1,     2,
       1,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     2,     1,     1,     4,     3,     1,     1,
       2,     2,     1,     0,     3,     1
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
  case 2: /* start: program  */
#line 35 "1905110.y"
                        {logout<<"start : program\n";}
#line 1374 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 37 "1905110.y"
                        {logout<<"program : program unit\n";}
#line 1380 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 38 "1905110.y"
                        {logout<<"program : unit\n";}
#line 1386 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 40 "1905110.y"
                        {logout<<"unit : var_declaration\n";}
#line 1392 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 41 "1905110.y"
                        {logout<<"unit : func_declaration\n";}
#line 1398 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 42 "1905110.y"
                        {logout<<"unit : func_definition \n";}
#line 1404 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 44 "1905110.y"
                                                                           {logout<<"func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n";}
#line 1410 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 45 "1905110.y"
                                                                           {logout<<"func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON\n";}
#line 1416 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement  */
#line 48 "1905110.y"
                                                                                    {
                                                                                        logout<<"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
                                                                                        logout<<yyvsp[-5]<<" "<<yyvsp[-4]<<'\n';
                                                                                    }
#line 1425 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN RPAREN compound_statement  */
#line 52 "1905110.y"
                                                                                    {
                                                                                        logout<<"func_definition : type_specifier ID LPAREN RPAREN compound_statement \n";
                                                                                        logout<<yyvsp[-4]<<" "<<yyvsp[-3]<<'\n';
                                                                                    }
#line 1434 "y.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 58 "1905110.y"
                                                          {logout<<"parameter_list  : parameter_list COMMA type_specifier ID\n";}
#line 1440 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier  */
#line 59 "1905110.y"
                                                          {logout<<"parameter_list  : parameter_list COMMA type_specifier\n";}
#line 1446 "y.tab.c"
    break;

  case 14: /* parameter_list: type_specifier ID  */
#line 60 "1905110.y"
                                                          {logout<<"parameter_list  : type_specifier ID\n";}
#line 1452 "y.tab.c"
    break;

  case 15: /* parameter_list: type_specifier  */
#line 61 "1905110.y"
                                                          {logout<<"parameter_list  : type_specifier\n";}
#line 1458 "y.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 65 "1905110.y"
                     {
                        symTable->EnterScope(); logout<<"AFER LCURL\n";
                     }
#line 1466 "y.tab.c"
    break;

  case 17: /* compound_statement: LCURL $@1 statements RCURL  */
#line 70 "1905110.y"
                     {
                        logout<<"compound_statement : LCURL statements RCURL\n";  
                        symTable->PrintAll(logout);
                        symTable->ExitScope();                              
                     }
#line 1476 "y.tab.c"
    break;

  case 18: /* compound_statement: LCURL RCURL  */
#line 75 "1905110.y"
                                                  {logout<<"compound_statement : LCURL RCURL\n";}
#line 1482 "y.tab.c"
    break;

  case 19: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 78 "1905110.y"
                                                            {logout<<"var_declaration : type_specifier declaration_list SEMICOLON\n";}
#line 1488 "y.tab.c"
    break;

  case 20: /* type_specifier: INT  */
#line 80 "1905110.y"
                            {logout<<"type_specifier : INT\n";}
#line 1494 "y.tab.c"
    break;

  case 21: /* type_specifier: FLOAT  */
#line 81 "1905110.y"
                            {logout<<"type_specifier : FLOAT\n";}
#line 1500 "y.tab.c"
    break;

  case 22: /* type_specifier: VOID  */
#line 82 "1905110.y"
                            {logout<<"type_specifier : VOID\n";}
#line 1506 "y.tab.c"
    break;

  case 23: /* declaration_list: declaration_list COMMA ID  */
#line 85 "1905110.y"
                                            {

                        logout<<"declaration_list: declaration_list COMMA ID\n";

                        }
#line 1516 "y.tab.c"
    break;

  case 24: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 90 "1905110.y"
                                                                    {
                        logout<<"declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
                    }
#line 1524 "y.tab.c"
    break;

  case 25: /* declaration_list: ID  */
#line 93 "1905110.y"
                    {
                        logout<<"declaration_list : ID "<<yylval<<" "<<yyvsp[0]<<'\n';

                    }
#line 1533 "y.tab.c"
    break;

  case 26: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 97 "1905110.y"
                                             {
                        logout<<"declaration_list : ID LTHIRD CONST_INT RTHIRD\n";
                    }
#line 1541 "y.tab.c"
    break;

  case 27: /* statements: statement  */
#line 102 "1905110.y"
                                        {logout<<"statements : statement\n";}
#line 1547 "y.tab.c"
    break;

  case 28: /* statements: statements statement  */
#line 103 "1905110.y"
                                        {logout<<"statements : statements statement\n";}
#line 1553 "y.tab.c"
    break;

  case 29: /* statement: var_declaration  */
#line 106 "1905110.y"
                                                                                                     {logout<<"statement : var_declaration\n";}
#line 1559 "y.tab.c"
    break;

  case 30: /* statement: expression_statement  */
#line 107 "1905110.y"
                                                                                                     {logout<<"statement : expression_statement\n";}
#line 1565 "y.tab.c"
    break;

  case 31: /* statement: compound_statement  */
#line 108 "1905110.y"
                                                                                                     {logout<<"statement : compound_statement\n";}
#line 1571 "y.tab.c"
    break;

  case 32: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 109 "1905110.y"
                                                                                                     {logout<<"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement \n";}
#line 1577 "y.tab.c"
    break;

  case 33: /* statement: IF LPAREN expression RPAREN statement  */
#line 110 "1905110.y"
                                                                                                     {logout<<"statement : IF LPAREN expression RPAREN statement\n";}
#line 1583 "y.tab.c"
    break;

  case 34: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 111 "1905110.y"
                                                                                                     {logout<<"statement : IF LPAREN expression RPAREN statement ELSE statement\n";}
#line 1589 "y.tab.c"
    break;

  case 35: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 112 "1905110.y"
                                                                                                     {logout<<"statement : WHILE LPAREN expression RPAREN statement\n";}
#line 1595 "y.tab.c"
    break;

  case 36: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 113 "1905110.y"
                                                                                                     {logout<<"statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n";}
#line 1601 "y.tab.c"
    break;

  case 37: /* statement: RETURN expression SEMICOLON  */
#line 114 "1905110.y"
                                                                                                     {logout<<"statement : RETURN expression SEMICOLON\n";}
#line 1607 "y.tab.c"
    break;

  case 38: /* expression_statement: SEMICOLON  */
#line 117 "1905110.y"
                                            {logout<<"expression_statement: SEMICOLON\n";}
#line 1613 "y.tab.c"
    break;

  case 39: /* expression_statement: expression SEMICOLON  */
#line 118 "1905110.y"
                                            {logout<<"expression_statement: expression SEMICOLON\n";}
#line 1619 "y.tab.c"
    break;

  case 40: /* variable: ID  */
#line 120 "1905110.y"
                                              {logout<<"variable : ID "<<yyvsp[0]<<'\n';}
#line 1625 "y.tab.c"
    break;

  case 41: /* variable: ID LTHIRD expression RTHIRD  */
#line 121 "1905110.y"
                                              {logout<<"variable : ID LTHIRD expression RTHIRD\n";}
#line 1631 "y.tab.c"
    break;

  case 42: /* expression: logic_expression  */
#line 124 "1905110.y"
                                                       {logout<<"expression      : logic_expression \n";}
#line 1637 "y.tab.c"
    break;

  case 43: /* expression: variable ASSIGNOP logic_expression  */
#line 125 "1905110.y"
                                                       {logout<<"expression      : variable ASSIGNOP logic_expression \n";}
#line 1643 "y.tab.c"
    break;

  case 44: /* logic_expression: rel_expression  */
#line 128 "1905110.y"
                                                        {logout<<"logic_expression: rel_expression\n";}
#line 1649 "y.tab.c"
    break;

  case 45: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 129 "1905110.y"
                                                        {logout<<"logic_expression: rel_expression LOGICOP rel_expression\n";}
#line 1655 "y.tab.c"
    break;

  case 46: /* rel_expression: simple_expression  */
#line 132 "1905110.y"
                                                             {logout<<"rel_expression  : simple_expression\n";}
#line 1661 "y.tab.c"
    break;

  case 47: /* rel_expression: simple_expression RELOP simple_expression  */
#line 133 "1905110.y"
                                                             {logout<<"rel_expression  : simple_expression RELOP simple_expression\n";}
#line 1667 "y.tab.c"
    break;

  case 48: /* simple_expression: term  */
#line 135 "1905110.y"
                                                {logout<<"simple_expression: term\n";}
#line 1673 "y.tab.c"
    break;

  case 49: /* simple_expression: simple_expression ADDOP term  */
#line 136 "1905110.y"
                                                {logout<<"simple_expression: simple_expression ADDOP term\n";}
#line 1679 "y.tab.c"
    break;

  case 50: /* term: unary_expression  */
#line 138 "1905110.y"
                                                {logout<<"term : unary_expression\n";}
#line 1685 "y.tab.c"
    break;

  case 51: /* term: term MULOP unary_expression  */
#line 139 "1905110.y"
                                                {logout<<"term : term MULOP unary_expression\n";}
#line 1691 "y.tab.c"
    break;

  case 52: /* unary_expression: ADDOP unary_expression  */
#line 142 "1905110.y"
                                                {logout<<"unary_expression: ADDOP unary_expressionn\n";}
#line 1697 "y.tab.c"
    break;

  case 53: /* unary_expression: NOT unary_expression  */
#line 143 "1905110.y"
                                                {logout<<"unary_expression: NOT unary_expression\n";}
#line 1703 "y.tab.c"
    break;

  case 54: /* unary_expression: factor  */
#line 144 "1905110.y"
                                                {logout<<"unary_expression: factor\n";}
#line 1709 "y.tab.c"
    break;

  case 55: /* factor: variable  */
#line 147 "1905110.y"
                                                 {logout<<"factor : variable \n";}
#line 1715 "y.tab.c"
    break;

  case 56: /* factor: ID LPAREN argument_list RPAREN  */
#line 148 "1905110.y"
                                                 {logout<<"factor : ID LPAREN argument_list RPAREN \n";}
#line 1721 "y.tab.c"
    break;

  case 57: /* factor: LPAREN expression RPAREN  */
#line 149 "1905110.y"
                                                 {logout<<"factor : LPAREN expression RPAREN \n";}
#line 1727 "y.tab.c"
    break;

  case 58: /* factor: CONST_INT  */
#line 150 "1905110.y"
                                                 {logout<<"factor : CONST_INT \n";}
#line 1733 "y.tab.c"
    break;

  case 59: /* factor: CONST_FLOAT  */
#line 151 "1905110.y"
                                                 {logout<<"factor : CONST_FLOAT \n";}
#line 1739 "y.tab.c"
    break;

  case 60: /* factor: variable INCOP  */
#line 152 "1905110.y"
                                                 {logout<<"factor : variable INCOP\n";}
#line 1745 "y.tab.c"
    break;

  case 61: /* factor: variable DECOP  */
#line 153 "1905110.y"
                                                 {logout<<"factor : variable DECOP\n";}
#line 1751 "y.tab.c"
    break;


#line 1755 "y.tab.c"

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

#line 163 "1905110.y"


int main(int argc,char *argv[]){
	FILE *fp;

	if((fp=fopen(argv[1],"r"))==NULL){
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logout.open("log.txt");
	errout.open("error.txt");

	yyin=fp;
	yyparse();


	logout<<"Total lines: "<<line_count<<endl;
    logout<<"Total errors: "<<error<<endl;

	fclose(yyin);
 	logout.close();
	errout.close();
	return 0;
}
