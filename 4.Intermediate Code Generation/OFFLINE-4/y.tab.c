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
#line 1 "1905110_parser.y"


#include<bits/stdc++.h>
#include"1905110_SymbolTable.h"
#include"1905110_SymbolInfo.h"
#include"1905110_ScopeTable.h"

using namespace std;
typedef long long ll;

ofstream logout;
ofstream errout;
ofstream code;
ofstream parsetree;

extern int line_count,interal_line,error_no;
extern FILE *yyin;



SymbolTable *symTable = new SymbolTable(11);
ScopeTable *sc = symTable->EnterScope();
vector<pair<SymbolInfo,int>> parameter; 
vector<string> argument;
vector<SymbolInfo> declaredVar;
int parameterNum = 0,errorline,label= 0;
vector<SymbolInfo>globalVar; //for ICG

int yylex(void);

void yyerror(string s){
	logout<<"Error at line "<<line_count<<": "<<s<<"\n"<<endl;
    errorline = line_count;
    error_no++;
}
void freeVector(vector<SymbolInfo*>*symInfo){
    for(SymbolInfo* info: *symInfo){
		delete info;
	}
	delete symInfo;
}
void destroyChild(SymbolInfo* parent){
    for(SymbolInfo* info : *parent->get_child()){
        destroyChild(info);
        delete info;
    }
    delete parent->get_child();
}
string assignTypeCast(SymbolInfo *s1, SymbolInfo* s2){
    string a = s1->get_returnType();
    string b = s2->get_returnType();
    string c;

    if(a=="VOID" || b =="VOID"){
        if(a=="VOID" && b=="VOID"){
            c = "VOID";
        }
        else {
            c = (a=="VOID")?b:a;
        }
        errout<<"Line# "<<line_count<<": Void cannot be used in expression \n";
        error_no++;
    }
    else if(a==b){
        c = a;
        
    }
    else if(a=="FLOAT" && b == "INT"){
        c = "FLOAT";
    }
    else if(a=="INT" && b=="FLOAT"){
        c = "INT";
        errout<<"Line# "<<line_count<<": Warning: possible loss of data in assignment of FLOAT to INT\n" ;
        error_no++;
    }

    return c;
}
string operationalTypeCast(SymbolInfo *s1, SymbolInfo* s2){
    string a = s1->get_returnType();
    string b = s2->get_returnType();
    string c;
    
    if(a=="VOID" || b =="VOID"){
        
        if(a=="VOID" && b=="VOID"){
            c = "VOID";
        }

        else {

            c = (a=="VOID")?b:a;
        }
        
        errout<<"Line# "<<line_count<<": Void cannot be used in expression \n";
        error_no++;
    }
    else if(a=="INT" && b == "INT"){
        c = a;
    }
    else if(a=="FLOAT" && b == "INT"){
        c = "FLOAT";
    }
    else if(a=="INT" && b=="FLOAT"){
        c = "FLOAT";
    }
    return c;
}
string getAsmRelop(string relop){
    if(relop==">") return "JG";
    else if(relop==">=")return "JGE";
    else if(relop=="<")return "JL";
    else if(relop=="<=")return "JLE";
    else if(relop=="==")return "JE";
    else if(relop=="!=")return "JNE";

}
string generateLabel(){
    label++;
    return "L"+to_string(label);
}
void functionInsert(string name, string type)
{
    int x = symTable->Insert(name,"FUNCTION",type,logout);


    if(!x){
        SymbolInfo *s = symTable->LookUpCurrent(name);          
        
        if(s==NULL){
            
        }
        else if( s->get_type() != "FUNCTION"){

            errout<<"Line# "<<line_count <<": '"<<s->get_name()<<"' redeclared as different kind of symbol"<<"\n";
            error_no++;
        }

        else if(type != s->get_returnType()){
            errout<<"Line# "<<line_count<<": Conflicting types for '"<<s->get_name()<<"'\n";
            error_no++;
        }

        else if(parameter.size()!= s->get_param().size()){
            errout<<"Line# "<<line_count<<": Conflicting types for '"<<s->get_name()<<"'\n";
            error_no++;
        }
       
    }
    
}
void functionDefinitionFly(string name){
    //.............ICG......
    string onTheFly = name+" PROC\n";
    
    if(name == "main"){
        onTheFly+="\tMOV AX,@DATA\n\tMOV DS,AX\n";
    }

    onTheFly+="\tPUSH BP\n\tMOV BP,SP\n";
    code<<onTheFly;
}
void enterScope(){
    symTable->EnterScope();
    for(auto i: parameter){

        int x = symTable->Insert(i.first.get_name(),i.first.get_type(),i.first.get_returnType(),logout);

        if(!x){
            errout<<"Line# "<<i.second<<": Redefinition of parameter '"<<i.first.get_name()<<"'\n";
            error_no++;
        }
    }
}


#line 248 "y.tab.c"

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
    IF = 260,                      /* IF  */
    FOR = 261,                     /* FOR  */
    ELSE = 262,                    /* ELSE  */
    INT = 263,                     /* INT  */
    FLOAT = 264,                   /* FLOAT  */
    VOID = 265,                    /* VOID  */
    BREAK = 266,                   /* BREAK  */
    DOUBLE = 267,                  /* DOUBLE  */
    PRINTLN = 268,                 /* PRINTLN  */
    RETURN = 269,                  /* RETURN  */
    SWITCH = 270,                  /* SWITCH  */
    CASE = 271,                    /* CASE  */
    DEFAULT = 272,                 /* DEFAULT  */
    WHILE = 273,                   /* WHILE  */
    CONTINUE = 274,                /* CONTINUE  */
    NEWLINE = 275,                 /* NEWLINE  */
    SEMICOLON = 276,               /* SEMICOLON  */
    LPAREN = 277,                  /* LPAREN  */
    RPAREN = 278,                  /* RPAREN  */
    LCURL = 279,                   /* LCURL  */
    RCURL = 280,                   /* RCURL  */
    LSQUARE = 281,                 /* LSQUARE  */
    RSQUARE = 282,                 /* RSQUARE  */
    COMMA = 283,                   /* COMMA  */
    NOT = 284,                     /* NOT  */
    DECOP = 285,                   /* DECOP  */
    RELOP = 286,                   /* RELOP  */
    ASSIGNOP = 287,                /* ASSIGNOP  */
    INCOP = 288,                   /* INCOP  */
    ADDOP = 289,                   /* ADDOP  */
    MULOP = 290,                   /* MULOP  */
    CONST_INT = 291,               /* CONST_INT  */
    CONST_FLOAT = 292,             /* CONST_FLOAT  */
    LOGICOP = 293,                 /* LOGICOP  */
    BITOP = 294,                   /* BITOP  */
    ID = 295,                      /* ID  */
    LOWER_THAN_ELSE = 296          /* LOWER_THAN_ELSE  */
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
#define IF 260
#define FOR 261
#define ELSE 262
#define INT 263
#define FLOAT 264
#define VOID 265
#define BREAK 266
#define DOUBLE 267
#define PRINTLN 268
#define RETURN 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define WHILE 273
#define CONTINUE 274
#define NEWLINE 275
#define SEMICOLON 276
#define LPAREN 277
#define RPAREN 278
#define LCURL 279
#define RCURL 280
#define LSQUARE 281
#define RSQUARE 282
#define COMMA 283
#define NOT 284
#define DECOP 285
#define RELOP 286
#define ASSIGNOP 287
#define INCOP 288
#define ADDOP 289
#define MULOP 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define LOGICOP 293
#define BITOP 294
#define ID 295
#define LOWER_THAN_ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 178 "1905110_parser.y"

    SymbolInfo *symInfo;

#line 387 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
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
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_DOUBLE = 12,                    /* DOUBLE  */
  YYSYMBOL_PRINTLN = 13,                   /* PRINTLN  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_NEWLINE = 20,                   /* NEWLINE  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LCURL = 24,                     /* LCURL  */
  YYSYMBOL_RCURL = 25,                     /* RCURL  */
  YYSYMBOL_LSQUARE = 26,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 27,                   /* RSQUARE  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_DECOP = 30,                     /* DECOP  */
  YYSYMBOL_RELOP = 31,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 32,                  /* ASSIGNOP  */
  YYSYMBOL_INCOP = 33,                     /* INCOP  */
  YYSYMBOL_ADDOP = 34,                     /* ADDOP  */
  YYSYMBOL_MULOP = 35,                     /* MULOP  */
  YYSYMBOL_CONST_INT = 36,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 37,               /* CONST_FLOAT  */
  YYSYMBOL_LOGICOP = 38,                   /* LOGICOP  */
  YYSYMBOL_BITOP = 39,                     /* BITOP  */
  YYSYMBOL_ID = 40,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 41,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_start = 43,                     /* start  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_unit = 45,                      /* unit  */
  YYSYMBOL_func_declaration = 46,          /* func_declaration  */
  YYSYMBOL_func_definition = 47,           /* func_definition  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_parameter_list = 50,            /* parameter_list  */
  YYSYMBOL_compound_statement = 51,        /* compound_statement  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_var_declaration = 54,           /* var_declaration  */
  YYSYMBOL_type_specifier = 55,            /* type_specifier  */
  YYSYMBOL_declaration_list = 56,          /* declaration_list  */
  YYSYMBOL_statements = 57,                /* statements  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_expression_statement = 59,      /* expression_statement  */
  YYSYMBOL_variable = 60,                  /* variable  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_logic_expression = 62,          /* logic_expression  */
  YYSYMBOL_rel_expression = 63,            /* rel_expression  */
  YYSYMBOL_64_5 = 64,                      /* $@5  */
  YYSYMBOL_simple_expression = 65,         /* simple_expression  */
  YYSYMBOL_66_6 = 66,                      /* $@6  */
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
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   192,   192,   235,   248,   260,   271,   281,   297,   323,
     342,   359,   359,   408,   408,   460,   474,   487,   500,   515,
     515,   543,   543,   571,   634,   645,   655,   667,   687,   712,
     729,   758,   772,   791,   806,   820,   836,   855,   870,   887,
     902,   940,   957,   968,   988,  1030,  1076,  1092,  1137,  1151,
    1167,  1183,  1183,  1230,  1244,  1244,  1283,  1297,  1334,  1346,
    1378,  1393,  1409,  1464,  1480,  1496,  1512,  1547,  1584,  1597,
    1602,  1620
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
  "\"end of file\"", "error", "\"invalid token\"", "DO", "CHAR", "IF",
  "FOR", "ELSE", "INT", "FLOAT", "VOID", "BREAK", "DOUBLE", "PRINTLN",
  "RETURN", "SWITCH", "CASE", "DEFAULT", "WHILE", "CONTINUE", "NEWLINE",
  "SEMICOLON", "LPAREN", "RPAREN", "LCURL", "RCURL", "LSQUARE", "RSQUARE",
  "COMMA", "NOT", "DECOP", "RELOP", "ASSIGNOP", "INCOP", "ADDOP", "MULOP",
  "CONST_INT", "CONST_FLOAT", "LOGICOP", "BITOP", "ID", "LOWER_THAN_ELSE",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "$@1", "$@2", "parameter_list", "compound_statement",
  "$@3", "$@4", "var_declaration", "type_specifier", "declaration_list",
  "statements", "statement", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "$@5",
  "simple_expression", "$@6", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      37,   -75,   -75,   -75,    25,    37,   -75,   -75,   -75,   -75,
      -3,   -75,   -75,     4,    -6,     8,    17,   -75,    16,    38,
      39,    -9,    22,    43,    40,    53,   -75,    55,    65,    37,
     -75,   -75,    54,   -75,    64,   -75,   -75,    55,    51,    66,
      96,    69,   -75,   -75,   -75,    73,    74,    76,    14,    85,
     -75,    14,    14,    14,   -75,   -75,    33,   -75,   -75,    68,
      63,   -75,   -75,    50,    90,   -75,    75,    -7,    77,   -75,
     -75,   -75,    14,   105,    79,    94,    14,    93,    45,   -75,
     -75,    14,    14,    95,   -75,   -75,   -75,    14,   -75,   -75,
      14,    91,    89,    14,   101,   105,   106,   -75,   108,   -75,
     -75,   112,   100,   110,   -75,   -75,    14,    14,   -75,    96,
      14,   117,    96,   -75,    14,   -75,   109,    77,   133,   121,
     -75,   -75,   -75,    96,    96,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    24,    25,    26,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    29,     0,     0,     0,    23,     0,     0,
      13,     0,    18,     0,    27,     0,     9,     0,    11,     0,
      17,    30,     0,    10,    19,    14,     8,     0,    16,     0,
       0,     0,    12,    15,    28,     0,     0,     0,     0,     0,
      42,     0,     0,     0,    64,    65,    44,    35,    33,     0,
       0,    31,    34,    61,     0,    46,    48,    50,    53,    56,
      60,    22,     0,     0,     0,     0,     0,     0,    61,    59,
      58,    69,     0,    29,    20,    32,    67,     0,    66,    43,
       0,     0,     0,     0,     0,     0,     0,    41,     0,    63,
      71,     0,    68,     0,    47,    49,     0,     0,    57,     0,
       0,     0,     0,    62,     0,    45,    52,    55,    37,     0,
      40,    39,    70,     0,     0,    38,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   141,   -75,   -75,   -75,   -75,   -75,   -17,
     -75,   -75,    23,     6,   -75,   -75,   -60,   -61,   -49,   -43,
     -74,    57,   -75,    42,   -75,    44,   -51,   -75,   -75,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    37,    27,    21,    57,
      40,    41,    58,    59,    14,    60,    61,    62,    63,    64,
      65,    66,    91,    67,    92,    68,    69,    70,   101,   102
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      85,    79,    80,    78,    78,    75,    10,   100,    77,    19,
      35,    10,    95,   104,    28,    17,     1,     2,     3,    29,
      42,    22,    18,     9,   -51,    11,    15,   -54,     9,    94,
      16,    20,    78,    98,   110,    38,    51,    13,    78,   103,
     122,    78,   108,    52,    78,     1,     2,     3,    53,   118,
      54,    55,   121,    23,    56,    81,    24,    78,    78,    82,
      26,    25,    30,   125,   126,    78,    32,   119,    45,    46,
      31,     1,     2,     3,    33,    86,    47,    48,    88,    34,
      86,    49,    87,    88,    50,    51,    36,    34,    84,   -21,
      39,    43,    52,    44,    71,    72,    73,    53,    74,    54,
      55,    45,    46,    56,     1,     2,     3,    76,    83,    47,
      48,    89,    93,    90,    49,    97,    99,    50,    51,    96,
      34,    16,   106,   107,   109,    52,    50,    51,   114,   111,
      53,   112,    54,    55,    52,   113,    56,   115,   120,    53,
     123,    54,    55,   -54,   124,    56,    12,   105,   116,     0,
       0,   117
};

static const yytype_int8 yycheck[] =
{
      60,    52,    53,    52,    53,    48,     0,    81,    51,     1,
      27,     5,    73,    87,    23,    21,     8,     9,    10,    28,
      37,    15,    28,     0,    31,     0,    22,    34,     5,    72,
      26,    23,    81,    76,    95,    29,    22,    40,    87,    82,
     114,    90,    93,    29,    93,     8,     9,    10,    34,   109,
      36,    37,   112,    36,    40,    22,    40,   106,   107,    26,
      21,    23,    40,   123,   124,   114,    26,   110,     5,     6,
      27,     8,     9,    10,    21,    30,    13,    14,    33,    24,
      30,    18,    32,    33,    21,    22,    21,    24,    25,    25,
      36,    40,    29,    27,    25,    22,    22,    34,    22,    36,
      37,     5,     6,    40,     8,     9,    10,    22,    40,    13,
      14,    21,    35,    38,    18,    21,    23,    21,    22,    40,
      24,    26,    31,    34,    23,    29,    21,    22,    28,    23,
      34,    23,    36,    37,    29,    23,    40,    27,    21,    34,
       7,    36,    37,    34,    23,    40,     5,    90,   106,    -1,
      -1,   107
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    43,    44,    45,    46,    47,    54,
      55,     0,    45,    40,    56,    22,    26,    21,    28,     1,
      23,    50,    55,    36,    40,    23,    21,    49,    23,    28,
      40,    27,    26,    21,    24,    51,    21,    48,    55,    36,
      52,    53,    51,    40,    27,     5,     6,    13,    14,    18,
      21,    22,    29,    34,    36,    37,    40,    51,    54,    55,
      57,    58,    59,    60,    61,    62,    63,    65,    67,    68,
      69,    25,    22,    22,    22,    61,    22,    61,    60,    68,
      68,    22,    26,    40,    25,    58,    30,    32,    33,    21,
      38,    64,    66,    35,    61,    59,    40,    21,    61,    23,
      62,    70,    71,    61,    62,    63,    31,    34,    68,    23,
      59,    23,    23,    23,    28,    27,    65,    67,    58,    61,
      21,    58,    62,     7,    23,    58,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    46,    46,
      46,    48,    47,    49,    47,    50,    50,    50,    50,    52,
      51,    53,    51,    54,    55,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    64,    63,    65,    66,    65,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     0,     7,     0,     6,     4,     3,     2,     1,     0,
       4,     0,     3,     3,     1,     1,     1,     3,     6,     1,
       4,     1,     2,     1,     1,     1,     7,     5,     7,     5,
       5,     3,     1,     2,     1,     4,     1,     3,     1,     3,
       1,     0,     4,     1,     0,     4,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
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
#line 193 "1905110_parser.y"
       {
         logout<<"start : program\n";
          (yyval.symInfo) = new SymbolInfo("start","program");
          (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
          (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
          (yyval.symInfo)->set_child((yyvsp[0].symInfo));

          code<<".MODEL SMALL\n.STACK 500H\n.DATA\n\tnumber DB \"00000$\"\n";

          for(auto i:globalVar){

            if(i.get_type()!="ARRAY"){
                code<<'\t'<<(i.get_name())<<" DW 0\n";
            }
            else code<<'\t'<<(i.get_name())<<" DW 0\n";

          }

          code<<".CODE\n";

         (yyval.symInfo)->code +="\nNEWLINE PROC\n\tPUSH AX\n\tPUSH DX\n\tMOV AH,2\n\tMOV DL,0DH\n\tINT 21h\n\tMOV AH,2\n\tMOV DL,0AH\n\tINT 21h\n\tPOP DX\n\tPOP ax\n\tRET\nNEWLINE ENDP\n\n";
        code<<"\nNEWLINE PROC\n\tPUSH AX\n\tPUSH DX\n\tMOV AH,2\n\tMOV DL,0DH\n\tINT 21h\n\tMOV AH,2\n\tMOV DL,0AH\n\tINT 21h\n\tPOP DX\n\tPOP ax\n\tRET\nNEWLINE ENDP\n\n"; 
         (yyval.symInfo)->code +="printnumber proc  ;print what is in ax\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tpush si\n\tlea si,number\n\tmov bx,10\n\tadd si,4\n\tcmp ax,0\n\tjnge negate\n";
        code<<"printnumber proc  ;print what is in ax\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tpush si\n";
        code<<"\tmov CX,0\n\tmov DX,0\n\tlabel1:\n\tcmp ax,0\n\tje print1\n";
         (yyval.symInfo)->code +="print:\n\txor dx,dx\n\tdiv bx\n\tmov [si],dl\n\tadd [si],0\n\tdec si\n\tcmp ax,0\n\tjne print\n\tinc si\n\tlea dx,si\n\tmov ah,9\n\tint 21h\n";
        code<<"\n\t;initialize bx to 10\n\tmov bx,10\n\t;extract last digit\n\tdiv bx\n\t;push it in the stack\n\tpush dx\n\t;inc the count\n\tinc cx\n\t;set dx to 0\n\txor dx,dx\n\tjmp label1\n";
        code<<"\n\tprint1:\n\t;check if count is greater than zero\n\tcmp cx,0\n\tje exit\n\t;pop the top of stack\n\tpop dx\n\t;add 48 to represent the ascii\n\tadd dx,48\n\t;print a char";
        code<<"\n\tmov ah,02h\n\tint 21h\n\tdec cx\n\tjmp print1";
        code<<"\n\texit:\n\tpop si\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\nprintnumber ENDP\n\n";
        

        (yyval.symInfo)->code += (yyvsp[0].symInfo)->code;
      //  code<<$$->code;
        (yyval.symInfo)->printChild(0,parsetree);

          
          
        destroyChild((yyval.symInfo));

       }
#line 1569 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 236 "1905110_parser.y"
        {
            logout<<"program : program unit\n";
            (yyval.symInfo) = new SymbolInfo("program","program unit");
            
            (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
            (yyval.symInfo)->set_child((yyvsp[0].symInfo));

            (yyval.symInfo)->set_start((yyvsp[-1].symInfo)->get_start());
            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

            (yyval.symInfo)->code += (yyvsp[-1].symInfo)->code + (yyvsp[0].symInfo)->code ;
        }
#line 1586 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 249 "1905110_parser.y"
        {
            logout<<"program : unit\n";
            (yyval.symInfo) = new SymbolInfo("program","unit");
            (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
            (yyval.symInfo)->set_child((yyvsp[0].symInfo));

            (yyval.symInfo)->code += (yyvsp[0].symInfo)->code;

        }
#line 1601 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 261 "1905110_parser.y"
        {
            logout<<"unit : var_declaration\n";
            (yyval.symInfo) = new SymbolInfo("unit","var_declaration");
            (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
            (yyval.symInfo)->set_child((yyvsp[0].symInfo));


            (yyval.symInfo)->code += (yyvsp[0].symInfo)->code;
        }
#line 1616 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 272 "1905110_parser.y"
        {
            logout<<"unit : func_declaration\n";
            (yyval.symInfo) = new SymbolInfo("unit","func_declaration");
            (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
            (yyval.symInfo)->set_child((yyvsp[0].symInfo));

            (yyval.symInfo)->code += (yyvsp[0].symInfo)->code;
        }
#line 1630 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 282 "1905110_parser.y"
        {
            logout<<"unit : func_definition\n";
            (yyval.symInfo) = new SymbolInfo("unit","func_definition");
            (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
            (yyval.symInfo)->set_child((yyvsp[0].symInfo));

            (yyval.symInfo)->code += (yyvsp[0].symInfo)->code;

            
        }
#line 1646 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 298 "1905110_parser.y"
                {
                    logout<<"func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n";

                    functionInsert((yyvsp[-4].symInfo)->get_type(), (yyvsp[-5].symInfo)->get_returnType());
                    
                    SymbolInfo *s = symTable->LookUp(((yyvsp[-4].symInfo)->get_type()));
                    
                     if(s!=NULL){
                        s->set_param(parameter);
                        parameter.clear();
                     }

                    (yyval.symInfo) = new SymbolInfo("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");

                    (yyval.symInfo)->set_child((yyvsp[-5].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_start((yyvsp[-5].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                }
#line 1676 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 324 "1905110_parser.y"
                {
                    functionInsert((yyvsp[-3].symInfo)->get_type(), (yyvsp[-4].symInfo)->get_returnType());

                    logout<<"func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n";
                   
                    (yyval.symInfo) = new SymbolInfo("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON");
                    

                    (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_start((yyvsp[-4].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                }
#line 1699 "y.tab.c"
    break;

  case 10: /* func_declaration: type_specifier ID LPAREN error RPAREN SEMICOLON  */
#line 342 "1905110_parser.y"
                                                                 {

                    errout<<"Line# "<<errorline<<": Syntax error at parameter list of function definition\n";

                    (yyval.symInfo) = new SymbolInfo("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                    
                    (yyval.symInfo)->set_child((yyvsp[-5].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child(new SymbolInfo("parameter_list","error",errorline));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_start((yyvsp[-5].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());  
                }
#line 1720 "y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 359 "1905110_parser.y"
                                                                 { functionInsert( (yyvsp[-3].symInfo)->get_type(), (yyvsp[-4].symInfo)->get_returnType());functionDefinitionFly((yyvsp[-3].symInfo)->get_type());}
#line 1726 "y.tab.c"
    break;

  case 12: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 360 "1905110_parser.y"
                  {
                     SymbolInfo *s = symTable->LookUp(((yyvsp[-5].symInfo)->get_type()));
                    
                     if(s!=NULL){
                        s->set_param(parameter);
                        parameter.clear();
                     }
                     logout<<"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";

                     (yyval.symInfo) = new SymbolInfo("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                     (yyval.symInfo)->set_child((yyvsp[-6].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[-5].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                     (yyval.symInfo)->set_start((yyvsp[-6].symInfo)->get_start());
                     (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

//.......................................ICG....................................//
                    //  $$->code+=($2->get_type())+"PROC\n";
                    //  string onTheFly = ($2->get_type())+"PROC\n";
                    // // code<<onTheFly;

                    //  if(($2->get_type()=="main")){
                    //     $$->code+="\tMOV AX,@DATA\n\tMOV DS,AX\n";
                    //  }

                    //  $$->code+="\tPUSH BP\n\tMOV BP,SP\n";

                     (yyval.symInfo)->code+=(yyvsp[0].symInfo)->code;
                     
                     string onTheFly;
                     if(((yyvsp[-5].symInfo)->get_type()=="main")){
                        (yyval.symInfo)->code+="\tMOV AH, 4CH\n\tINT 21H\n";
                        onTheFly = "\tMOV AH, 4CH\n\tINT 21H\n";
                     }
                     else{
                        (yyval.symInfo)->code+="\tRET\n";
                        onTheFly = "\tRET\n";
                     }
                     (yyval.symInfo)->code +='\t'+((yyvsp[-5].symInfo)->get_type())+" ENDP\nEND "+((yyvsp[-5].symInfo)->get_type())+'\n';
                     onTheFly+= '\t'+((yyvsp[-5].symInfo)->get_type())+" ENDP\nEND "+((yyvsp[-5].symInfo)->get_type())+'\n';
                     code<<onTheFly;
//.............................................................................................//
                     
                  }
#line 1779 "y.tab.c"
    break;

  case 13: /* $@2: %empty  */
#line 408 "1905110_parser.y"
                                                  { functionInsert( (yyvsp[-2].symInfo)->get_type(), (yyvsp[-3].symInfo)->get_returnType());functionDefinitionFly((yyvsp[-2].symInfo)->get_type());}
#line 1785 "y.tab.c"
    break;

  case 14: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 409 "1905110_parser.y"
                  {  

                    
                    
                     SymbolInfo *s = symTable->LookUp(((yyvsp[-4].symInfo)->get_type()));

                     logout<<"func_definition : type_specifier ID LPAREN RPAREN compound_statement\n";     

                     (yyval.symInfo) = new SymbolInfo("func_definition","type_specifier ID LPAREN RPAREN compound_statement");
                    
                     
                  
                     (yyval.symInfo)->set_child((yyvsp[-5].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                     (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                     (yyval.symInfo)->set_start((yyvsp[-5].symInfo)->get_start());
                     (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());  

//....................................ICG.......................//
                    
                    //  $$->code+=($2->get_type())+" PROC\n";
                    //  if(($2->get_type()=="main")){
                    //     $$->code+="\tMOV AX,@DATA\n\tMOV DS,AX\n";
                    //  }

                    //  $$->code+="\tPUSH BP\n\tMOV BP,SP\n";

                     (yyval.symInfo)->code+=(yyvsp[0].symInfo)->code;
                     
                     string onTheFly ;
                     if(((yyvsp[-4].symInfo)->get_type()=="main")){
                        (yyval.symInfo)->code+="\tMOV AH, 4CH\n\tINT 21H\n";
                        onTheFly = "\tMOV AH, 4CH\n\tINT 21H\n";
                     }
                     else{
                        (yyval.symInfo)->code+="\tRET\n";
                        onTheFly = "\tRET\n";
                     }
                     (yyval.symInfo)->code +=((yyvsp[-4].symInfo)->get_type())+" ENDP\nEND "+((yyvsp[-4].symInfo)->get_type())+'\n';
                     onTheFly+= ((yyvsp[-4].symInfo)->get_type())+" ENDP\nEND "+((yyvsp[-4].symInfo)->get_type())+'\n';
                     code<<onTheFly;

//...................................................................//                                                       
                  }
#line 1837 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 461 "1905110_parser.y"
                    {
                        parameter.push_back({SymbolInfo(((yyvsp[0].symInfo)->get_type()),"ID",(yyvsp[-1].symInfo)->get_returnType()),line_count});
                        logout<<"parameter_list : parameter_list COMMA type_specifier ID\n";

                        (yyval.symInfo) = new SymbolInfo("parameter_list","parameter_list COMMA type_specifier ID");
                        (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                        (yyval.symInfo)->set_start((yyvsp[-3].symInfo)->get_start());
                        (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                    }
#line 1855 "y.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA type_specifier  */
#line 475 "1905110_parser.y"
                    {
                        parameter.push_back({SymbolInfo("","ID",(yyvsp[0].symInfo)->get_returnType()),line_count});
                        logout<<"parameter_list : parameter_list COMMA type_specifier\n";

                        (yyval.symInfo) = new SymbolInfo("parameter_list","parameter_list COMMA type_specifier");
                        (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                        (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                        (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                    }
#line 1872 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier ID  */
#line 488 "1905110_parser.y"
                    {
                        parameter.push_back({SymbolInfo(((yyvsp[0].symInfo)->get_type()),"ID",(yyvsp[-1].symInfo)->get_returnType()),line_count});
                        logout << "parameter_list : type_specifier ID\n" ;

                        (yyval.symInfo) = new SymbolInfo("parameter_list","type_specifier ID");
                        (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                        (yyval.symInfo)->set_start((yyvsp[-1].symInfo)->get_start());
                        (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                        
                    }
#line 1889 "y.tab.c"
    break;

  case 18: /* parameter_list: type_specifier  */
#line 501 "1905110_parser.y"
                    {   
                        parameter.push_back({SymbolInfo("","ID",(yyvsp[0].symInfo)->get_name()),line_count});
                        logout<<"parameter_list : type_specifier\n";

                        (yyval.symInfo) = new SymbolInfo("parameter_list","type_specifier");
                        (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                        (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                        (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                    }
#line 1904 "y.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 515 "1905110_parser.y"
                           {enterScope();}
#line 1910 "y.tab.c"
    break;

  case 20: /* compound_statement: LCURL $@3 statements RCURL  */
#line 518 "1905110_parser.y"
                     {  
                        logout<<"compound_statement : LCURL statements RCURL\n"; 

                        (yyval.symInfo) = new SymbolInfo("compound_statement","LCURL statements RCURL");
                        
                        (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                        (yyval.symInfo)->set_start((yyvsp[-3].symInfo)->get_start());
                        (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.......ICG.............//
                        (yyval.symInfo)->code = (yyvsp[-1].symInfo)->code;
                        (yyval.symInfo)->code +="\tADD SP,";(yyval.symInfo)->code+=to_string(symTable->getCurrentScope()->stackOffset)+'\n';
                        string onTheFly = "\tADD SP,"+to_string(symTable->getCurrentScope()->stackOffset)+'\n';
                        code<<onTheFly;
                        
                    //.......................//

                        symTable->PrintAll(logout);
                        symTable->ExitScope();
                                                       
                     }
#line 1939 "y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 543 "1905110_parser.y"
                            {enterScope();}
#line 1945 "y.tab.c"
    break;

  case 22: /* compound_statement: LCURL $@4 RCURL  */
#line 545 "1905110_parser.y"
                     {
                        
                        logout<<"compound_statement : LCURL RCURL\n";
                        
                        (yyval.symInfo) = new SymbolInfo("compound_statement","LCURL RCURL");

                        (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                        (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                        (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.......ICG.............//

                        (yyval.symInfo)->code +='\t'+"ADD SP,"+to_string(symTable->getCurrentScope()->stackOffset)+'\n';
                        string onTheFly = '\t'+"ADD SP,"+to_string(symTable->getCurrentScope()->stackOffset)+'\n';
                        code<<onTheFly;
                    //.......................//

                        symTable->PrintAll(logout);
                        symTable->ExitScope();
                       
                       
                     }
#line 1974 "y.tab.c"
    break;

  case 23: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 572 "1905110_parser.y"
                {
                    logout<<"var_declaration : type_specifier declaration_list SEMICOLON\n";
                    (yyval.symInfo) = new SymbolInfo("var_declaration","type_specifier declaration_list SEMICOLON");

                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                   
                    for(SymbolInfo info : declaredVar ){
                        
                        if((yyvsp[-2].symInfo)->get_type()=="VOID"){
                            errout<<"Line# "<<line_count<<": Variable or field '"<<info.get_name()<<"' declared void\n";
                            error_no++;
                        }
                        info.set_returnType((yyvsp[-2].symInfo)->get_returnType());
                        int x = symTable->Insert(info.get_name(), info.get_type(),info.get_returnType(),logout);
                        SymbolInfo *s = symTable->LookUpCurrent(info.get_name());

                        if(s->get_type()=="ARRAY"){
                            s->set_arraySize(info.get_arraySize());
                        }
                        //.................ICG............................//
                        if(symTable->getCurrentScope()->get_id() == 1){
                            s->stackOffset = 0;
                            globalVar.push_back(info);
                        }
                        else{
                            string onTheFly;
                            if(s->get_type()=="ARRAY"){
                                (yyval.symInfo)->code +="\tSUB SP,"+to_string(s->get_arraySize())+"\n";
                                onTheFly = "\tSUB SP,"+to_string(s->get_arraySize())+"\n";
                                code<<onTheFly;
                            }
                            else{
                                (yyval.symInfo)->code +="\tSUB SP,2\n";
                                code<<"\tSUB SP,2\n";
                            }
                        }
                       //..............................................................//
                        if(!x){

                            if(info.get_type() != s->get_type() && info.get_returnType() != s->get_returnType() ){
                                errout<<"Line# "<<line_count <<": '"<<s->get_name()<<"' redeclared as different kind of symbol "<<"\n";
                                error_no++;
                            }
                            else if(info.get_returnType() != s->get_returnType()){
                                errout<<"Line# "<<line_count<<": Conflicting types for'"<<s->get_name()<<"'\n";
                                error_no++;
                            }
                            else{
                                errout<<"Line# "<<line_count<<": Redefinition of variable '"<<(info.get_name())<<"'\n";
                                error_no++;
                            }
                        }
                    }

                    declaredVar.clear();
                }
#line 2040 "y.tab.c"
    break;

  case 24: /* type_specifier: INT  */
#line 635 "1905110_parser.y"
                {
                    logout<<"type_specifier : INT\n";

                    (yyval.symInfo)  = new SymbolInfo("type_specifier","INT");
                    (yyval.symInfo)->set_returnType("INT");
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                }
#line 2055 "y.tab.c"
    break;

  case 25: /* type_specifier: FLOAT  */
#line 646 "1905110_parser.y"
                {
                    logout<<"type_specifier    : FLOAT\n";
                    (yyval.symInfo)  = new SymbolInfo("type_specifier","FLOAT");
                    (yyval.symInfo)->set_returnType("FLOAT");
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                }
#line 2069 "y.tab.c"
    break;

  case 26: /* type_specifier: VOID  */
#line 656 "1905110_parser.y"
                {
                    logout<<"type_specifier     : VOID\n";
                    (yyval.symInfo)  = new SymbolInfo("type_specifier","VOID");
                    (yyval.symInfo)->set_returnType("VOID");
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                }
#line 2083 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID  */
#line 668 "1905110_parser.y"
                        {
                            logout<<"declaration_list : declaration_list COMMA ID\n";
                          
                            declaredVar.push_back(SymbolInfo((yyvsp[0].symInfo)->get_type(),(yyvsp[0].symInfo)->get_name()));
                            
                            (yyval.symInfo)  = new SymbolInfo("declaration_list","declaration_list COMMA ID");

                            (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                            (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                //.................................................//

                            

                            
                        }
#line 2107 "y.tab.c"
    break;

  case 28: /* declaration_list: declaration_list COMMA ID LSQUARE CONST_INT RSQUARE  */
#line 687 "1905110_parser.y"
                                                                      {
                            logout<<"declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE\n";
                            
                            SymbolInfo symInfo = SymbolInfo((yyvsp[-3].symInfo)->get_type(),"ARRAY");

                            symInfo.set_arraySize(stoi((yyvsp[-1].symInfo)->get_type()));
                            declaredVar.push_back(symInfo);



                            (yyval.symInfo)  = new SymbolInfo("declaration_list","declaration_list COMMA ID LSQUARE CONST_INT RSQUARE");

                            (yyval.symInfo)->set_child((yyvsp[-5].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                            (yyval.symInfo)->set_start((yyvsp[-5].symInfo)->get_start());
                            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                           
                            
                        }
#line 2136 "y.tab.c"
    break;

  case 29: /* declaration_list: ID  */
#line 712 "1905110_parser.y"
                    {
                            logout<<"declaration_list : ID "<<'\n';

                            
                            declaredVar.push_back(SymbolInfo((yyvsp[0].symInfo)->get_type(),(yyvsp[0].symInfo)->get_name()));
                            
                            (yyval.symInfo)  = new SymbolInfo("declaration_list","ID");

                            (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                            
                            
                            (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                            
                          
                    }
#line 2158 "y.tab.c"
    break;

  case 30: /* declaration_list: ID LSQUARE CONST_INT RSQUARE  */
#line 729 "1905110_parser.y"
                                                {
                            logout<<"declaration_list : ID LSQUARE CONST_INT RSQUARE\n";

                            
                            SymbolInfo symInfo = SymbolInfo((yyvsp[-3].symInfo)->get_type(),"ARRAY");
                            symInfo.set_arraySize(stoi((yyvsp[-1].symInfo)->get_type()));
                            declaredVar.push_back(symInfo);
                           

                            (yyval.symInfo)  = new SymbolInfo("declaration_list","ID LSQUARE CONST_INT RSQUARE");

                            (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                            (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                           
                            (yyval.symInfo)->set_start((yyvsp[-3].symInfo)->get_start());
                            (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                            
                            
                    }
#line 2185 "y.tab.c"
    break;

  case 31: /* statements: statement  */
#line 759 "1905110_parser.y"
                  {
                      logout<<"statements : statement\n";
                      (yyval.symInfo) = new SymbolInfo("statements","statement");
                      (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                      (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                      (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                      (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                      //..ICG ....

                      (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;
                  }
#line 2203 "y.tab.c"
    break;

  case 32: /* statements: statements statement  */
#line 773 "1905110_parser.y"
                 {
                      logout<<"statements : statements statement\n";
                      (yyval.symInfo) = new SymbolInfo("statements","statements statement");
                      
                      (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                      (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                      
                      (yyval.symInfo)->set_value((yyvsp[-1].symInfo)->get_value()+(yyvsp[0].symInfo)->get_value());
                      (yyval.symInfo)->set_start((yyvsp[-1].symInfo)->get_start());
                      (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                      //...iCG....

                      (yyval.symInfo)->code += (yyvsp[-1].symInfo)->code + (yyvsp[0].symInfo)->code;
                  }
#line 2223 "y.tab.c"
    break;

  case 33: /* statement: var_declaration  */
#line 792 "1905110_parser.y"
                  {
                    logout<<"statement : var_declaration\n";

                    (yyval.symInfo) = new SymbolInfo("statement","var_declaration");
                      
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                      
                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.....iCG...//
                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;
                  }
#line 2242 "y.tab.c"
    break;

  case 34: /* statement: expression_statement  */
#line 807 "1905110_parser.y"
                  {
                    logout<<"statement : expression_statement\n";
                    (yyval.symInfo) = new SymbolInfo("statement","expression_statement");
                      
                      (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                      
                      (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                      (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                      (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                      //.......ICG
                     (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;
                  }
#line 2260 "y.tab.c"
    break;

  case 35: /* statement: compound_statement  */
#line 821 "1905110_parser.y"
                  {
                    logout<<"statement : compound_statement\n";

                    (yyval.symInfo) = new SymbolInfo("statement","compound_statement");
                      
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                      
                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.......ICG
                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;
                    
                  }
#line 2280 "y.tab.c"
    break;

  case 36: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 837 "1905110_parser.y"
                  {
                    logout<<"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement \n";
                    
                    (yyval.symInfo) = new SymbolInfo("statement","FOR LPAREN expression_statement expression_statement expression RPAREN statement");
                    
                    (yyval.symInfo)->set_child((yyvsp[-6].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-5].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-6].symInfo)->get_type()+(yyvsp[-5].symInfo)->get_type()+(yyvsp[-4].symInfo)->get_value()+(yyvsp[-3].symInfo)->get_value()+(yyvsp[-2].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                      
                    (yyval.symInfo)->set_start((yyvsp[-6].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end()); 
                  }
#line 2303 "y.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression RPAREN statement  */
#line 856 "1905110_parser.y"
                  {
                    logout<<"IF LPAREN expression RPAREN statement %prec THEN\n";
                    (yyval.symInfo) = new SymbolInfo("statement","IF LPAREN expression RPAREN statement");
                      
                    (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                      
                    (yyval.symInfo)->set_value((yyvsp[-4].symInfo)->get_type()+(yyvsp[-3].symInfo)->get_type()+(yyvsp[-2].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-4].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                  }
#line 2322 "y.tab.c"
    break;

  case 38: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 871 "1905110_parser.y"
                  { 
                    logout<<"statement : IF LPAREN expression RPAREN statement ELSE statement\n";
                    (yyval.symInfo) = new SymbolInfo("statement","IF LPAREN expression RPAREN statement ELSE statement");

                    (yyval.symInfo)->set_child((yyvsp[-6].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-5].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));  
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                      
                    (yyval.symInfo)->set_value((yyvsp[-6].symInfo)->get_type()+(yyvsp[-5].symInfo)->get_type()+(yyvsp[-4].symInfo)->get_value()+(yyvsp[-3].symInfo)->get_type()+(yyvsp[-2].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-6].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                  }
#line 2343 "y.tab.c"
    break;

  case 39: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 888 "1905110_parser.y"
                  { 
                    logout<<"statement : WHILE LPAREN expression RPAREN statement\n";
                    (yyval.symInfo) = new SymbolInfo("statement","WHILE LPAREN expression RPAREN statement");
                      
                    (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                      
                    (yyval.symInfo)->set_value((yyvsp[-4].symInfo)->get_type()+(yyvsp[-3].symInfo)->get_type()+(yyvsp[-2].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-4].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                  }
#line 2362 "y.tab.c"
    break;

  case 40: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 903 "1905110_parser.y"
                  { 
                    logout<<"statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n";
                    (yyval.symInfo) = new SymbolInfo("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");
                      
                    (yyval.symInfo)->set_child((yyvsp[-4].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                    
                    (yyval.symInfo)->set_value((yyvsp[-4].symInfo)->get_type()+(yyvsp[-3].symInfo)->get_type()+(yyvsp[-2].symInfo)->get_type()+(yyvsp[-1].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[-4].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //............ICG
                    SymbolInfo *s = symTable->LookUp((yyvsp[-2].symInfo)->get_type());
                    
                    (yyval.symInfo)->code +=";"+((yyval.symInfo)->get_value())+'\n';
                    (yyval.symInfo)->code += "\tPUSH AX"+'\n';
                    code<<"\tPUSH AX\n";
                    string onTheFly;
                    if((s->stackOffset)==0){
                        
                        (yyval.symInfo)->code += "\tMOV AX,"+(s->get_name())+'\n';
                        onTheFly = "\tMOV AX,"+(s->get_name())+'\n';
                    }
                    else{
                        (yyval.symInfo)->code += "\tMOV AX,[BP-"+to_string(s->stackOffset)+"]\n";
                        onTheFly = "\tMOV AX,[BP-"+to_string(s->stackOffset)+"]\n";
                    }
                    code<<onTheFly;
                    (yyval.symInfo)->code += "\n\tCALL printnumber\n\tCALL NEWLINE\n";
                    onTheFly = "\n\tCALL printnumber\n\tCALL NEWLINE\n";
                    code<<onTheFly;
                    (yyval.symInfo)->code += "\tPOP AX"+'\n';
                    code<<"\tPOP AX\n";
                  }
#line 2404 "y.tab.c"
    break;

  case 41: /* statement: RETURN expression SEMICOLON  */
#line 941 "1905110_parser.y"
                 {
                    logout<<"statement : RETURN expression SEMICOLON\n";
                    
                    (yyval.symInfo) = new SymbolInfo("statement","RETURN expression SEMICOLON");
                      
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));


                    (yyval.symInfo)->set_value((yyvsp[-2].symInfo)->get_type()+(yyvsp[-1].symInfo)->get_value()+(yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                 }
#line 2423 "y.tab.c"
    break;

  case 42: /* expression_statement: SEMICOLON  */
#line 958 "1905110_parser.y"
                    {
                        logout<<"expression_statement : SEMICOLON\n";
                         (yyval.symInfo) = new SymbolInfo("expression_statement","SEMICOLON");
                      
                        (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                        
                        (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_type());
                        (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                        (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                    }
#line 2438 "y.tab.c"
    break;

  case 43: /* expression_statement: expression SEMICOLON  */
#line 969 "1905110_parser.y"
                    {
                        logout<<"expression_statement : expression SEMICOLON\n";
                        (yyval.symInfo) = new SymbolInfo("expression_statement","expression SEMICOLON");
                      
                        (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                        (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                        (yyval.symInfo)->set_value((yyvsp[-1].symInfo)->get_value()+(yyvsp[0].symInfo)->get_type());
                        (yyval.symInfo)->set_start((yyvsp[-1].symInfo)->get_start());
                        (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());


                        //.....ICG
                        (yyval.symInfo)->code = (yyvsp[-1].symInfo)->code;
                    }
#line 2458 "y.tab.c"
    break;

  case 44: /* variable: ID  */
#line 989 "1905110_parser.y"
                {
                    logout<<"variable : ID "<<'\n';

                    SymbolInfo *s = NULL;
                    s = symTable->LookUp((yyvsp[0].symInfo)->get_type());  
                    if(s==NULL){
                        errout<<"Line# "<<line_count<<": "<<"Undeclared variable '"<<((yyvsp[0].symInfo)->get_type())<< "'\n";
                        error_no++;
                        (yyval.symInfo) = new SymbolInfo("variable","ID", "");
                    } 
                    else{
                        (yyval.symInfo) = new SymbolInfo("variable","ID", s->get_returnType());
                    }
                    
                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //............ICG.............//

                  //  SymbolInfo *s = symTable->LookUp($1->get_type());
                    
                    (yyval.symInfo)->code +=";"+((yyval.symInfo)->get_value())+'\n';
                    
                    if((s->stackOffset)==0){
                        
                        (yyval.symInfo)->code += "\tMOV AX,"+(s->get_name())+'\n';
                        string onTheFly = "\tMOV AX,"+(s->get_name())+'\n';
                        code<<onTheFly;
                    }
                    else{
                        (yyval.symInfo)->code += "\tMOV AX,[BP-"+to_string(s->stackOffset)+"]\n";
                        string onTheFly = "\tMOV AX,[BP-"+to_string(s->stackOffset)+"]\n";
                        code<<onTheFly;
                    }
                                                
                }
#line 2503 "y.tab.c"
    break;

  case 45: /* variable: ID LSQUARE expression RSQUARE  */
#line 1031 "1905110_parser.y"
                {
                    SymbolInfo *s = NULL;

                    s = symTable->LookUp((yyvsp[-3].symInfo)->get_type()); 
                    
                    if(s->get_type()!="ARRAY"){
                        errout<<"Line# "<<line_count<<": '"<<((yyvsp[-3].symInfo)->get_type())<<"' is not an array\n";
                        error_no++;
                    }
                    else if((yyvsp[-1].symInfo)->get_returnType()!="INT"){
                        errout<<"Line# "<<line_count<<": Array subscript is not an integer\n";
                        error_no++;
                    }
                    
                    logout<<"variable : ID LSQUARE expression RSQUARE\n";
                    (yyval.symInfo) = new SymbolInfo("variable","ID LSQUARE expression RSQUARE",s->get_returnType());
                    
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-3].symInfo)->get_type()+(yyvsp[-2].symInfo)->get_type()+(yyvsp[-1].symInfo)->get_value()+(yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[-3].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //............ICG.............//

                  //  SymbolInfo *s = symTable->LookUp($1->get_type());
                    string onTheFly;
                    (yyval.symInfo)->code +=";"+((yyval.symInfo)->get_value())+'\n';
                    if((s->stackOffset)==0){
                        
                        (yyval.symInfo)->code += "\tMOV AX,"+(s->get_name())+'\n';
                        onTheFly = "\tMOV AX,"+(s->get_name())+'\n';
                        code<<onTheFly;
                    }
                    else{
                       // $$->code += "\tPUSH AX\n\tMOV AX ";
                      //  string idx = 
                      //  $$->code += "\tMOV AX,[BP-"+to_string(s->stackOffset)+"-"+to_string(idx)+"]\n";
                    }
                }
#line 2551 "y.tab.c"
    break;

  case 46: /* expression: logic_expression  */
#line 1077 "1905110_parser.y"
                 {
                    logout<<"expression : logic_expression\n";
                    (yyval.symInfo) = new SymbolInfo("expression","logic_expression",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.........ICG

                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;

                  }
#line 2571 "y.tab.c"
    break;

  case 47: /* expression: variable ASSIGNOP logic_expression  */
#line 1093 "1905110_parser.y"
                 {
                    logout<<"expression : variable ASSIGNOP logic_expression\n";

                    string c = assignTypeCast((yyvsp[-2].symInfo),(yyvsp[0].symInfo));

                    (yyval.symInfo) = new SymbolInfo("expression","variable ASSIGNOP logic_expression",c);
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-2].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //........ICG..............//

                    (yyval.symInfo)->code += ";"+((yyval.symInfo)->get_value())+'\n';
                    (yyval.symInfo)->code += (yyvsp[0].symInfo)->code;

                    vector<SymbolInfo*>* child = (yyvsp[-2].symInfo)->get_child();

                    SymbolInfo* id = NULL;

                    for(SymbolInfo* i:*child){
                        id = i;
                    }
                    
                    SymbolInfo *var = symTable->LookUp(id->get_type());  // Find the identifier in scope

                    string onTheFly ;
                    if(var->stackOffset==0){
                        (yyval.symInfo)->code+="\tMOV "+(var->get_name())+", AX\n";
                        onTheFly = "\tMOV "+(var->get_name())+", AX\n";
                    }
                    else{
                        (yyval.symInfo)->code+="\tMOV [BP-"+to_string(var->stackOffset)+"],AX\n";
                        onTheFly = "\tMOV [BP-"+to_string(var->stackOffset)+"],AX\n";
                    }
                    code<<onTheFly;

                 }
#line 2618 "y.tab.c"
    break;

  case 48: /* logic_expression: rel_expression  */
#line 1138 "1905110_parser.y"
                 {
                    logout<<"logic_expression : rel_expression\n";
                    (yyval.symInfo) = new SymbolInfo("logic_expression","rel_expression",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.....ICG
                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;
                 }
#line 2636 "y.tab.c"
    break;

  case 49: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 1152 "1905110_parser.y"
                 {
                    logout<<"logic_expression : rel_expression LOGICOP rel_expression\n";
                    
                    (yyval.symInfo) = new SymbolInfo("logic_expression" ,"rel_expression LOGICOP rel_expression","INT");
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-2].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                 }
#line 2654 "y.tab.c"
    break;

  case 50: /* rel_expression: simple_expression  */
#line 1168 "1905110_parser.y"
                {
                    logout<<"rel_expression : simple_expression\n";
                    (yyval.symInfo) = new SymbolInfo("rel_expression","simple_expression",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //........ICG

                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;

                }
#line 2674 "y.tab.c"
    break;

  case 51: /* $@5: %empty  */
#line 1183 "1905110_parser.y"
                                    {code<<"\tPUSH AX\n";}
#line 2680 "y.tab.c"
    break;

  case 52: /* rel_expression: simple_expression $@5 RELOP simple_expression  */
#line 1184 "1905110_parser.y"
                {
                    logout<<"rel_expression : simple_expression RELOP simple_expression\n";

                    (yyval.symInfo) = new SymbolInfo("rel_expression","simple_expression RELOP simple_expression","INT");
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-3].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-3].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //......ICG........

                    (yyval.symInfo)->code += ";"+(yyval.symInfo)->get_value()+'\n';

                    (yyval.symInfo)->code += (yyvsp[-3].symInfo)->code; 
                    (yyval.symInfo)->code += "\tPUSH AX\n";        // keep $1 value from AX to Dx, then push it to stack. It can be manipulted by $3;

                    (yyval.symInfo)->code += (yyvsp[-1].symInfo)->code; // value in AX;
                    (yyval.symInfo)->code += "\tMOV DX, AX\n";
                    string onTheFly = "\tMOV DX, AX\n";
                    code<<"\tMOV DX, AX\n";
                    (yyval.symInfo)->code += "\tPOP AX\n" ; // $1 = AX, $2 = DX;
                    code<<"\tPOP AX\n"; 

                    string trueLable = generateLabel(), falseLabel = generateLabel(), generalLabel = generateLabel();
                    (yyval.symInfo)->code += "\tCMP AX,DX\n";  
                    code<<"\tCMP AX,DX\n";
                    (yyval.symInfo)->code += "\t"+getAsmRelop((yyvsp[-1].symInfo)->get_type())+" "+trueLable+'\n';
                    onTheFly = "\t"+getAsmRelop((yyvsp[-1].symInfo)->get_type())+" "+trueLable+'\n';
                    code<<onTheFly;
                    (yyval.symInfo)->code += "\tJMP "+falseLabel+'\n';
                    onTheFly = "\tJMP "+falseLabel+'\n';
                    code<<onTheFly;

                    (yyval.symInfo)->code += trueLable+":\n\tMOV AX , 1\n\tJMP "+generalLabel+"\n";
                    onTheFly = trueLable+":\n\tMOV AX , 1\n\tJMP "+generalLabel+"\n";
                    code<<onTheFly;
                    (yyval.symInfo)->code += falseLabel+":\n\tMOV AX , 0\n"+generalLabel+":\n";
                    onTheFly = falseLabel+":\n\tMOV AX , 0\n"+generalLabel+":\n";
                    code<<onTheFly;
                }
#line 2729 "y.tab.c"
    break;

  case 53: /* simple_expression: term  */
#line 1231 "1905110_parser.y"
                {
                    logout<<"simple_expression : term\n";
                    (yyval.symInfo) = new SymbolInfo("simple_expression","term",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.......ICG
                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;
                }
#line 2747 "y.tab.c"
    break;

  case 54: /* $@6: %empty  */
#line 1244 "1905110_parser.y"
                                    {code<<"\tMOV DX,AX\n";}
#line 2753 "y.tab.c"
    break;

  case 55: /* simple_expression: simple_expression $@6 ADDOP term  */
#line 1245 "1905110_parser.y"
                {
                    logout<<"simple_expression : simple_expression ADDOP term\n";

                    string c = operationalTypeCast((yyvsp[-3].symInfo),(yyvsp[0].symInfo));
                    
                    (yyval.symInfo) = new SymbolInfo("simple_expression","simple_expression ADDOP term",c);
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-3].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-3].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.......ICG
                    (yyval.symInfo)->code += (yyvsp[-3].symInfo)->code;
                    (yyval.symInfo)->code += "\tMOV DX,AX\n";
                    (yyval.symInfo)->code += (yyvsp[0].symInfo)->code;

                    if(((yyvsp[-1].symInfo)->get_type())=="+"){
                        (yyval.symInfo)->code+="\tADD ";
                        code<<"\tADD ";
                    }
                    else{
                         (yyval.symInfo)->code += "\tSUB ";
                         code<<"\tSUB ";
                    }
                    (yyval.symInfo)->code += "DX,AX\n";
                    code<<"DX,AX\n";
                    
                    (yyval.symInfo)->code += "\tPUSH DX\n\tPOP AX ;always keep first part of expression in AX then move it to DX\n";
                    code<<"\tPUSH DX\n\tPOP AX ;always keep first part of expression in AX then move it to DX\n";
                }
#line 2792 "y.tab.c"
    break;

  case 56: /* term: unary_expression  */
#line 1284 "1905110_parser.y"
                {
                    logout<<"term : unary_expression\n";
                    (yyval.symInfo) = new SymbolInfo("term","unary_expression",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //..........ICG
                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;
                }
#line 2810 "y.tab.c"
    break;

  case 57: /* term: term MULOP unary_expression  */
#line 1298 "1905110_parser.y"
                {
                    logout<<"term : term MULOP unary_expression\n";

                    string c = operationalTypeCast((yyvsp[-2].symInfo),(yyvsp[0].symInfo));

                    if((yyvsp[-1].symInfo)->get_type()=="%"){

                       (yyval.symInfo) = new SymbolInfo("term","term MULOP unary_expression",(yyvsp[-2].symInfo)->get_returnType());

                       if((yyvsp[0].symInfo)->get_returnType()!="INT" || (yyvsp[-2].symInfo)->get_returnType()!="INT") {
                        errout<<"Line# "<<line_count<<": Operands of modulus must be integers \n";
                        error_no++;
                       }
                    }  

                    if((yyvsp[-1].symInfo)->get_type()=="%" || (yyvsp[-1].symInfo)->get_type()=="/"){

                        (yyval.symInfo) = new SymbolInfo("term","term MULOP unary_expression",(yyvsp[-2].symInfo)->get_returnType());

                        if((yyvsp[0].symInfo)->get_value()=="0"){
                            errout<<"Line# "<<line_count<<": Warning: division by zero i=0f=1Const=0\n";
                        }
                    } 

                    else (yyval.symInfo) = new SymbolInfo("term","term MULOP unary_expression",c);
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-2].symInfo)->get_value()+(yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                }
#line 2849 "y.tab.c"
    break;

  case 58: /* unary_expression: ADDOP unary_expression  */
#line 1335 "1905110_parser.y"
                {
                    logout<<"unary_expression : ADDOP unary_expression\n";
                    (yyval.symInfo) = new SymbolInfo("unary_expression","ADDOP unary_expression",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-1].symInfo)->get_type()+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-1].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                }
#line 2865 "y.tab.c"
    break;

  case 59: /* unary_expression: NOT unary_expression  */
#line 1347 "1905110_parser.y"
                { 
                    logout<<"unary_expression : NOT unary_expression\n";
                    (yyval.symInfo) = new SymbolInfo("unary_expression","LOGICOP unary_expression",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value("!"+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-1].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.....IGC
                    (yyval.symInfo)->code +="MOV CX,AX\n";
                    code<<"MOV CX,AX\n";
                    string trueLable = generateLabel(),endLabel = generateLabel();
                    (yyval.symInfo)->code +="JCXZ "+trueLable+'\n';
                    string onTheFly = "JCXZ "+trueLable+'\n';
                    code<<onTheFly;
                    (yyval.symInfo)->code +="MOV AX,0\nJMP "+endLabel+"\n";
                    onTheFly = "MOV AX,0\nJMP "+endLabel+"\n";
                    code<<onTheFly;
                    (yyval.symInfo)->code +=trueLable+":\n";
                    onTheFly = trueLable+":\n";
                    code<<onTheFly;
                    (yyval.symInfo)->code +="MOV AX,1\n";
                    onTheFly ="MOV AX,1\n";
                    code<<onTheFly;
                    (yyval.symInfo)->code +=endLabel+":\n";
                    onTheFly = endLabel+":\n";
                    code<<onTheFly;
                }
#line 2901 "y.tab.c"
    break;

  case 60: /* unary_expression: factor  */
#line 1379 "1905110_parser.y"
                { 
                    logout<<"unary_expression : factor\n";
                    (yyval.symInfo) = new SymbolInfo("unary_expression","factor",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //............ICG
                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code ;
                }
#line 2918 "y.tab.c"
    break;

  case 61: /* factor: variable  */
#line 1394 "1905110_parser.y"
                {
                   logout<<"factor : variable\n";     
                   (yyval.symInfo) = new SymbolInfo("factor" ,"variable",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());

                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());      

                    //....ICG
                    (yyval.symInfo)->code = (yyvsp[0].symInfo)->code;     
                }
#line 2937 "y.tab.c"
    break;

  case 62: /* factor: ID LPAREN argument_list RPAREN  */
#line 1410 "1905110_parser.y"
                {
                    logout<<"factor : ID LPAREN argument_list RPAREN \n";
                    SymbolInfo *s = symTable->LookUp((yyvsp[-3].symInfo)->get_type());  

                    string c = "";
                                                    
                    if(s==NULL){
                        errout<<"Line# "<<line_count<<": "<<"Undeclared function '"<<((yyvsp[-3].symInfo)->get_type())<< "'\n";
                        error_no++;
                    } 
                    
                    else if(parameterNum!=s->get_param().size()){

                        c = s->get_returnType();
                        if(parameterNum < s->get_param().size()){
                            errout<<"Line# "<<line_count<<": "<<"Too few arguments to function '"<<((yyvsp[-3].symInfo)->get_type())<< "'\n";
                            error_no++;
                        }
                        else if(parameterNum > s->get_param().size()){
                            errout<<"Line# "<<line_count<<": "<<"Too many arguments to function '"<<((yyvsp[-3].symInfo)->get_type())<< "'\n";
                            error_no++;
                        }

                    }
                    else{

                        vector<pair<SymbolInfo,int>> temp = s->get_param();
                        c = s->get_returnType();

                        for(int i=0;i<argument.size();i++){

                            if(argument[i] != temp[i].first.get_returnType()){
                                errout<<"Line# "<<line_count<<": "<<"Type mismatch for argument "<< (i+1)<<" of '"<<((yyvsp[-3].symInfo)->get_type())<< "'\n";
                                error_no++;
                            }
                        }
                        argument.clear();
                    }
                    parameterNum = 0;
                  
                    (yyval.symInfo) = new SymbolInfo("factor","ID LPAREN argument_list RPAREN",c);

                    (yyval.symInfo)->set_child((yyvsp[-3].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-3].symInfo)->get_type()+(yyvsp[-2].symInfo)->get_type()+(yyvsp[-1].symInfo)->get_value()+(yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[-3].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());


                }
#line 2995 "y.tab.c"
    break;

  case 63: /* factor: LPAREN expression RPAREN  */
#line 1465 "1905110_parser.y"
                {
                    logout<<"factor : LPAREN expression RPAREN\n";
                    (yyval.symInfo) = new SymbolInfo("factor","LPAREN expression RPAREN",(yyvsp[-1].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                    
                    (yyval.symInfo)->set_value((yyvsp[-2].symInfo)->get_type()+(yyvsp[-1].symInfo)->get_value()+(yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.......ICG....//
                    (yyval.symInfo)->code += (yyvsp[-1].symInfo)->code;
                }
#line 3015 "y.tab.c"
    break;

  case 64: /* factor: CONST_INT  */
#line 1481 "1905110_parser.y"
                {
                    logout<<"factor : CONST_INT \n";
                    (yyval.symInfo) = new SymbolInfo("factor","CONST_INT","INT");
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.........ICG.......//
                    (yyval.symInfo)->code += "\tMOV AX,"+((yyvsp[0].symInfo)->get_type())+'\n';
                    string onTheFly = "\tMOV AX,"+((yyvsp[0].symInfo)->get_type())+'\n';
                    code<<onTheFly;
                }
#line 3035 "y.tab.c"
    break;

  case 65: /* factor: CONST_FLOAT  */
#line 1497 "1905110_parser.y"
                {
                    logout<<"factor : CONST_FLOAT \n";
                    (yyval.symInfo) = new SymbolInfo("factor","CONST_FLOAT","FLOAT");
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    //.........ICG.......//
                    (yyval.symInfo)->code += "\tMOV AX,"+((yyvsp[0].symInfo)->get_type())+'\n';
                    string onTheFly = "\tMOV AX,"+((yyvsp[0].symInfo)->get_type())+'\n';
                    code<<onTheFly;
                }
#line 3055 "y.tab.c"
    break;

  case 66: /* factor: variable INCOP  */
#line 1513 "1905110_parser.y"
                {
                    logout<<"factor : variable INCOP\n";
                    (yyval.symInfo) = new SymbolInfo("factor","variable INCOP",(yyvsp[-1].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));
                    
                    (yyval.symInfo)->set_value((yyvsp[-1].symInfo)->get_value()+(yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[-1].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    // ... ICG..........//
                    (yyval.symInfo)->code +=(yyvsp[-1].symInfo)->code;
                    (yyval.symInfo)->code +="\tPUSH AX\n\tINC AX\n";
                    string onTheFly = "\tPUSH AX\n\tINC AX\n";
                    code<<onTheFly;
                    //$$->code += "\tADD AX,1\n"    dont do this.because its infix increment. m = n++ here m's value will be previous n value.
                                            //      so we reserve this in stack.

                    SymbolInfo *var = symTable->LookUp((yyvsp[-1].symInfo)->get_value());  // Find the identifier in scope


                    if(var->stackOffset==0){
                        (yyval.symInfo)->code+="\tMOV "+(var->get_name())+",AX\n";
                        onTheFly = "\tMOV "+(var->get_name())+",AX\n";
                    }
                    else{
                        (yyval.symInfo)->code+="\tMOV [BP-"+to_string(var->stackOffset)+"],AX\n";
                        onTheFly = "\tMOV [BP-"+to_string(var->stackOffset)+"],AX\n";
                    }
                    code<<onTheFly;
	                (yyval.symInfo)->code +="\tPOP AX\n";
                    code<<"\tPOP AX\n";
                }
#line 3094 "y.tab.c"
    break;

  case 67: /* factor: variable DECOP  */
#line 1548 "1905110_parser.y"
                {
                    logout<<"factor : variable DECOP\n";
                    (yyval.symInfo) = new SymbolInfo("factor","variable DECOP",(yyvsp[-1].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-1].symInfo)->get_value()+(yyvsp[0].symInfo)->get_type());
                    (yyval.symInfo)->set_start((yyvsp[-1].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                    // ... ICG..........//
                    (yyval.symInfo)->code +=(yyvsp[-1].symInfo)->code;
                    (yyval.symInfo)->code +="\tPUSH AX\n\tDEC AX\n";
                    string onTheFly = "\tPUSH AX\n\tDEC AX\n";
                    code<<onTheFly;
                    //$$->code += "\tMOV AX,1\n"    dont do this.because its infix increment. m = n++ here m's value will be previous n value.
                                            //      so we reserve this in stack.

                    SymbolInfo *var = symTable->LookUp((yyvsp[-1].symInfo)->get_value());  // Find the identifier in scope

                    
                    if(var->stackOffset==0){
                        (yyval.symInfo)->code+="\tMOV "+(var->get_name())+",AX\n";
                        onTheFly = "\tMOV "+(var->get_name())+",AX\n";
                    }
                    else{
                        (yyval.symInfo)->code+="\tMOV [BP-"+to_string(var->stackOffset)+"],AX\n";
                        onTheFly = "\tMOV [BP-"+to_string(var->stackOffset)+"],AX\n";
                    }
                    code<<onTheFly;
	                (yyval.symInfo)->code +="\tPOP AX\n";
                    code<<"\tPOP AX\n";
                }
#line 3133 "y.tab.c"
    break;

  case 68: /* argument_list: arguments  */
#line 1585 "1905110_parser.y"
                {
                    logout<<"argument_list : arguments\n";
                    (yyval.symInfo) = new SymbolInfo("argument_list","arguments");
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());

                }
#line 3149 "y.tab.c"
    break;

  case 69: /* argument_list: %empty  */
#line 1597 "1905110_parser.y"
                { 
                    (yyval.symInfo) = new SymbolInfo("argument_list ","",line_count);
                }
#line 3157 "y.tab.c"
    break;

  case 70: /* arguments: arguments COMMA logic_expression  */
#line 1603 "1905110_parser.y"
                  {

                    logout<<"arguments : arguments COMMA logic_expression\n";
                    parameterNum++;

                    argument.push_back((yyvsp[0].symInfo)->get_returnType());

                    (yyval.symInfo) = new SymbolInfo("arguments","arguments COMMA logic_expression");
                                                    
                    (yyval.symInfo)->set_child((yyvsp[-2].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[-1].symInfo));
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[-2].symInfo)->get_value()+","+(yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[-2].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                  }
#line 3179 "y.tab.c"
    break;

  case 71: /* arguments: logic_expression  */
#line 1621 "1905110_parser.y"
                  { 
                    parameterNum++; logout<<"arguments : logic_expression\n";

                    argument.clear();
                    argument.push_back((yyvsp[0].symInfo)->get_returnType());

                    (yyval.symInfo) = new SymbolInfo("arguments","logic_expression",(yyvsp[0].symInfo)->get_returnType());
                                                    
                    (yyval.symInfo)->set_child((yyvsp[0].symInfo));

                    (yyval.symInfo)->set_value((yyvsp[0].symInfo)->get_value());
                    (yyval.symInfo)->set_start((yyvsp[0].symInfo)->get_start());
                    (yyval.symInfo)->set_end((yyvsp[0].symInfo)->get_end());
                  }
#line 3198 "y.tab.c"
    break;


#line 3202 "y.tab.c"

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

#line 1636 "1905110_parser.y"


int main(int argc,char *argv[]){
	FILE *fp;

	if((fp=fopen(argv[1],"r"))==NULL){
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logout.open("log.txt");
	errout.open("error.txt");
    parsetree.open("parse.txt");
    code.open("code.asm");

	yyin=fp;
	yyparse();


	logout<<"Total Lines: "<<line_count+1<<endl;
    logout<<"Total Errors: "<<error_no<<endl;

	fclose(yyin);

 	logout.close();
	errout.close();
    parsetree.close();
    code.close();

	return 0;
}
