%{
#include <stdio.h>
#include <stdlib.h>4
#include <bits/stdc++.h>
     /* yyparse() stack type */

using namespace std;

void yyerror(char *s){
	printf("%s\n",s);
}

int yylex(void);

%}



%token NEWLINE SEMICOLON ID PLUS MINUS SLASH ASTERISK LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE COMMA NOT KEYWORD
%token NUMBER

%%
input:
    | input line
    ;
line: NEWLINE
    | expr NEWLINE           { printf("\t%d\n",$1);}
    ;
expr: expr PLUS term         { $$ = $1 + $3;cout<<$$<<" ";}
    | expr MINUS term        { $$ = $1 - $3; cout<<$$<<" ";}
    | term                    {cout<<$$<<" .";}
    ;   
term: term ASTERISK factor   { $$ = $1 * $3; }
    | term SLASH factor      { $$ = $1 / $3; }
    | factor
    ;
factor: LPAREN expr RPAREN  { $$ = $2; }
      | NUMBER
      ;
%%

main()
{
    yyparse();
    exit(0);
}
