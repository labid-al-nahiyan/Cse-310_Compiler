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
