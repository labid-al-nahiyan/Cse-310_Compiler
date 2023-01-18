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
#line 56 "1905110_parser.y"

    SymbolInfo *symInfo;
    

#line 154 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
