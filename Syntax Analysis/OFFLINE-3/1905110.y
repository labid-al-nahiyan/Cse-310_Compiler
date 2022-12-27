%{
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

%}



%token DO CHAR BREAK DOUBLE SWITCH CASE DEFAULT CONTINUE NEWLINE SEMICOLON ID PLUS MINUS SLASH ASTERISK LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE COMMA NOT KEYWORD
%token CONST_INT CONST_FLOAT IF FOR ELSE INT FLOAT VOID LTHIRD RTHIRD WHILE PRINTLN RETURN ADDOP LOGICOP DECOP RELOP ASSIGNOP MULOP INCOP

%%
start: program
     ;
program: program unit
    | unit
    ;
unit : var_declaration
    | func_declaration
    | func_definition
    ;
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
                | type_specifier ID LPAREN RPAREN SEMICOLON
                ;

func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
                | type_specifier ID LPAREN RPAREN compound_statement
                ;

parameter_list  : parameter_list COMMA type_specifier ID
                | parameter_list COMMA type_specifier
                | type_specifier ID
                | type_specifier
                ;

compound_statement : LCURL statements RCURL
                | LCURL RCURL
                ;

var_declaration : type_specifier declaration_list SEMICOLON
                ;
type_specifier  : INT
                | FLOAT
                | VOID
                ;

declaration_list: declaration_list COMMA ID
                | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
                | ID
                | ID LTHIRD CONST_INT RTHIRD
                ;

statements      : statement
                | statements statement
                ;

statement       : var_declaration
                | expression_statement
                | compound_statement
                | FOR LPAREN expression statement expression_statement expression RPAREN statement
                | IF LPAREN expression RPAREN statement
                | IF LPAREN expression RPAREN statement ELSE statement
                | WHILE LPAREN expression RPAREN statement
                | PRINTLN LPAREN ID RPAREN SEMICOLON
                | RETURN expression SEMICOLON
                ;

expression_statement: SEMICOLON
                | expression SEMICOLON
                ;
variable        : ID
                | ID LTHIRD expression RTHIRD
                ;

expression      : logic_expression
                | variable ASSIGNOP logic_expression
                ;

logic_expression: rel_expression
                | rel_expression LOGICOP rel_expression
                ;

rel_expression  : simple_expression
                | simple_expression RELOP simple_expression
                ;
simple_expression: term
                | simple_expression ADDOP term
                ;
term            : unary_expression
                | term MULOP unary_expression
                ;

unary_expression: ADDOP unary_expression
                | NOT unary_expression
                | factor
                ;

factor          : variable
                | ID LPAREN argument_list RPAREN
                | LPAREN expression RPAREN
                | CONST_INT
                | CONST_FLOAT
                | variable INCOP
                | variable DECOP
                ;

argument_list   : arguments
                |
                ;

arguments       : arguments COMMA logic_expression
                | logic_expression
                ;
%%

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
	
	symTable->PrintAll(logout);

	logout<<"Total lines: "<<line_count<<endl;
    logout<<"Total errors: "<<error<<endl;

	fclose(yyin);
 	logout.close();
	errout.close();
	return 0;
}
