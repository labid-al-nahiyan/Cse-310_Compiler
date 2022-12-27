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
start: program          {logout<<"start : program\n";}
     ;
program: program unit   {logout<<"program : program unit\n";}
    | unit              {logout<<"program : unit\n";}
    ; 
unit : var_declaration  {logout<<"unit : var_declaration\n";}
    | func_declaration  {logout<<"unit : func_declaration\n";}
    | func_definition   {logout<<"unit : func_definition \n";}
    ;
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {logout<<"func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n";}
                | type_specifier ID LPAREN RPAREN SEMICOLON                {logout<<"func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON\n";}
                ;

func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement {
                                                                                        logout<<"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
                                                                                        logout<<$1<<" "<<$2<<'\n';
                                                                                    }
                | type_specifier ID LPAREN RPAREN compound_statement                {
                                                                                        logout<<"func_definition : type_specifier ID LPAREN RPAREN compound_statement \n";
                                                                                        logout<<$1<<" "<<$2<<'\n';
                                                                                    }
                ;

parameter_list  : parameter_list COMMA type_specifier ID  {logout<<"parameter_list  : parameter_list COMMA type_specifier ID\n";}
                | parameter_list COMMA type_specifier     {logout<<"parameter_list  : parameter_list COMMA type_specifier\n";}
                | type_specifier ID                       {logout<<"parameter_list  : type_specifier ID\n";}
                | type_specifier                          {logout<<"parameter_list  : type_specifier\n";}
                ;

compound_statement : LCURL 
                     {
                        symTable->EnterScope(); logout<<"AFER LCURL\n";
                     } 
                     statements 
                     RCURL       
                     {
                        logout<<"compound_statement : LCURL statements RCURL\n";  
                        symTable->PrintAll(logout);
                        symTable->ExitScope();                              
                     }
                | LCURL RCURL                     {logout<<"compound_statement : LCURL RCURL\n";}
                ;

var_declaration : type_specifier declaration_list SEMICOLON {logout<<"var_declaration : type_specifier declaration_list SEMICOLON\n";}
                ;
type_specifier  : INT       {logout<<"type_specifier : INT\n";}
                | FLOAT     {logout<<"type_specifier : FLOAT\n";}
                | VOID      {logout<<"type_specifier : VOID\n";}
                ;

declaration_list: declaration_list COMMA ID {

                        logout<<"declaration_list: declaration_list COMMA ID\n";

                        }
                | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
                        logout<<"declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
                    }
                | ID{
                        logout<<"declaration_list : ID "<<'\n';

                    }
                | ID LTHIRD CONST_INT RTHIRD {
                        logout<<"declaration_list : ID LTHIRD CONST_INT RTHIRD\n";
                    }
                ;

statements      : statement             {logout<<"statements : statement\n";}
                | statements statement  {logout<<"statements : statements statement\n";}
                ;

statement       : var_declaration                                                                    {logout<<"statement : var_declaration\n";}
                | expression_statement                                                               {logout<<"statement : expression_statement\n";}
                | compound_statement                                                                 {logout<<"statement : compound_statement\n";}
                | FOR LPAREN expression_statement expression_statement expression RPAREN statement   {logout<<"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement \n";}
                | IF LPAREN expression RPAREN statement                                              {logout<<"statement : IF LPAREN expression RPAREN statement\n";}
                | IF LPAREN expression RPAREN statement ELSE statement                               {logout<<"statement : IF LPAREN expression RPAREN statement ELSE statement\n";}
                | WHILE LPAREN expression RPAREN statement                                           {logout<<"statement : WHILE LPAREN expression RPAREN statement\n";}
                | PRINTLN LPAREN ID RPAREN SEMICOLON                                                 {logout<<"statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n";}
                | RETURN expression SEMICOLON                                                        {logout<<"statement : RETURN expression SEMICOLON\n";}
                ;

expression_statement: SEMICOLON             {logout<<"expression_statement: SEMICOLON\n";}
                | expression SEMICOLON      {logout<<"expression_statement: expression SEMICOLON\n";}
                ;
variable        : ID                          {logout<<"variable : ID "<<$1<<'\n';}
                | ID LTHIRD expression RTHIRD {logout<<"variable : ID LTHIRD expression RTHIRD\n";}
                ;

expression      : logic_expression                     {logout<<"expression      : logic_expression \n";}
                | variable ASSIGNOP logic_expression   {logout<<"expression      : variable ASSIGNOP logic_expression \n";}
                ;

logic_expression: rel_expression                        {logout<<"logic_expression: rel_expression\n";}
                | rel_expression LOGICOP rel_expression {logout<<"logic_expression: rel_expression LOGICOP rel_expression\n";}
                ;

rel_expression  : simple_expression                          {logout<<"rel_expression  : simple_expression\n";}
                | simple_expression RELOP simple_expression  {logout<<"rel_expression  : simple_expression RELOP simple_expression\n";}
                ;
simple_expression: term                         {logout<<"simple_expression: term\n";}
                | simple_expression ADDOP term  {logout<<"simple_expression: simple_expression ADDOP term\n";}
                ;
term            : unary_expression              {logout<<"term : unary_expression\n";}
                | term MULOP unary_expression   {logout<<"term : term MULOP unary_expression\n";}
                ;

unary_expression: ADDOP unary_expression        {logout<<"unary_expression: ADDOP unary_expressionn\n";}
                | NOT unary_expression          {logout<<"unary_expression: NOT unary_expression\n";}
                | factor                        {logout<<"unary_expression: factor\n";}
                ;

factor          : variable                       {logout<<"factor : variable \n";}
                | ID LPAREN argument_list RPAREN {logout<<"factor : ID LPAREN argument_list RPAREN \n";}
                | LPAREN expression RPAREN       {logout<<"factor : LPAREN expression RPAREN \n";}
                | CONST_INT                      {logout<<"factor : CONST_INT \n";}
                | CONST_FLOAT                    {logout<<"factor : CONST_FLOAT \n";}
                | variable INCOP                 {logout<<"factor : variable INCOP\n";}
                | variable DECOP                 {logout<<"factor : variable DECOP\n";}
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


	logout<<"Total lines: "<<line_count<<endl;
    logout<<"Total errors: "<<error<<endl;

	fclose(yyin);
 	logout.close();
	errout.close();
	return 0;
}
