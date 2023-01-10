%{

#include<bits/stdc++.h>
#include"1905110_SymbolTable.h"
#include"1905110_SymbolInfo.h"
#include"1905110_ScopeTable.h"

using namespace std;
typedef long long ll;

ofstream logout;
ofstream errout;

extern int line_count,interal_line,error;
extern FILE *yyin;



SymbolTable *symTable = new SymbolTable(28);
ScopeTable *sc = symTable->EnterScope();
vector<SymbolInfo> para; 

int yylex(void);

void yyerror( string s){
	//printf("%s\n",s);
}
void freeSymbolInfoVector(vector<SymbolInfo*>* list){
                                for(SymbolInfo* info: *list){
                                    delete info;
                                }
                                delete list;
}



%}

%union{
    SymbolInfo *symInfo;
    string *str;
    vector<SymbolInfo*>* str_vector;
}

%token DO CHAR IF FOR ELSE INT FLOAT VOID BREAK DOUBLE PRINTLN RETURN SWITCH CASE DEFAULT WHILE CONTINUE NEWLINE SEMICOLON LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE COMMA NOT DECOP RELOP ASSIGNOP INCOP
%token<symInfo> ADDOP MULOP CONST_INT CONST_FLOAT LOGICOP BITOP ID
%type argument_list 
%type<symInfo>  factor unary_expression term rel_expression logic_expression arguments start program unit func_declaration func_definition parameter_list compound_statement var_declaration statement statements variable
%type<str> type_specifier
%type<str_vector> declaration_list

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


func_in : type_specifier ID {symTable->Insert(($2->get_name()),*$1,"FUNCTION",logout);} LPAREN
        ;
func_declaration: func_in parameter_list RPAREN SEMICOLON {
                                                                                logout<<"func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n";
                                                          }
                | func_in RPAREN SEMICOLON                {
                                                              logout<<"func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON\n";
                                                          }
                ;
func_definition : func_in  parameter_list RPAREN compound_statement {
                                                                        logout<<"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
                                                                    }
                | func_in  RPAREN compound_statement                {   
                                                                        logout<<"func_definition : type_specifier ID LPAREN RPAREN compound_statement \n";                                          
                                                                    }
                ;

                ;
parameter_list  : parameter_list COMMA type_specifier ID 
                    {
                        para.push_back(SymbolInfo(($4->get_name()),*$3));
                        logout<<"parameter_list  : parameter_list COMMA type_specifier ID\n";
                    }
                | parameter_list COMMA type_specifier     
                    {
                        logout<<"parameter_list  : parameter_list COMMA type_specifier\n";
                    }
                | type_specifier ID                       
                    {
                        para.push_back(SymbolInfo(($2->get_name()),*$1));
                        logout << "parameter_list  : type_specifier ID\n" ;
                    }
                | type_specifier                          
                    {   
                        logout<<"parameter_list  : type_specifier\n";
                    }
                ;

LCURL_          : LCURL 
                     {
                        symTable->EnterScope();
                     } 
compound_statement : LCURL_
                     statements 
                     RCURL       
                     {
                        for(auto i: para){

                            symTable->Insert(i.get_name(),i.get_type(),i.get_returnType(),logout);
                        }
                        para.clear();

                        logout<<"compound_statement : LCURL statements RCURL\n";  
                        symTable->PrintAll(logout);
                        symTable->ExitScope();
                                                       
                     }

                    | LCURL_ RCURL                   
                     {
                        for(auto i: para){

                            symTable->Insert(i.get_name(),i.get_type(),i.get_returnType(),logout);
                        }
                        para.clear();

                        logout<<"compound_statement : LCURL RCURL\n";
                        symTable->PrintAll(logout);
                        symTable->ExitScope();
                     }
                ;

var_declaration : type_specifier declaration_list SEMICOLON 
                            {
                                logout<<"var_declaration : type_specifier declaration_list SEMICOLON\n";

                            
                                for(SymbolInfo* info : *$2 ){
                                    info->set_type(*$1);
                                    symTable->Insert(info->get_name(), info->get_type(),info->get_returnType(),logout);
                                    logout<<(info->get_name())<<" inserted\n";
                                }

                               
                            }
                ;
type_specifier  : INT       {logout<<"type_specifier : INT\n";$$=new string("INT");}
                | FLOAT     {logout<<"type_specifier : FLOAT\n";$$=new string("FLOAT");}
                | VOID      {logout<<"type_specifier : VOID\n";$$=new string("VOID");}
                ;

declaration_list: declaration_list COMMA ID 
                        {
                            logout<<"declaration_list: declaration_list COMMA ID\n";
                           
                            $1->push_back($3);
                            $$ = $1;

                           // freeSymbolInfoVector($1);
                             
                        }
                | declaration_list COMMA ID LSQUARE CONST_INT RSQUARE {
                            logout<<"declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
                            
                            $3->set_returnType("ARRAY");
                            $1->push_back($3);
                            $$ = $1;
                        }

                | ID{
                            logout<<"declaration_list : ID "<<'\n';

                            $$ = new vector<SymbolInfo*>();
                            $$->push_back($1);
                    }
                | ID LSQUARE  CONST_INT RSQUARE {
                            logout<<"declaration_list : ID LTHIRD CONST_INT RTHIRD\n";
                            $$ = new vector<SymbolInfo*>();
                            $1->set_returnType("Array");
                            $$->push_back($1);
                            
                    }
                ;

statements      : statement             {
                                            logout<<"statements : statement\n";

                                        }
                | statements statement  {logout<<"statements : statements statement\n";}
                ;

statement_if    : IF LPAREN expression RPAREN statement
                |
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
variable        : ID                            {
                                                    logout<<"variable : ID "<<'\n';
                                                   
                                                }
                | ID LSQUARE expression RSQUARE {logout<<"variable : ID LTHIRD expression RTHIRD\n";}
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
                | simple_expression ADDOP term  {
                                                    logout<<"simple_expression: simple_expression ADDOP term\n";
                                                }
                ;
term            : unary_expression              {logout<<"term : unary_expression\n";}
                | term MULOP unary_expression   {logout<<"term : term MULOP unary_expression\n";}
                ;

unary_expression: ADDOP unary_expression        {logout<<"unary_expression: ADDOP unary_expressionn\n";}
                | NOT unary_expression          {logout<<"unary_expression: NOT unary_expression\n";}
                | factor                        {logout<<"unary_expression: factor\n";}
                ;

factor          : variable                       {logout<<"factor : variable \n";}
                | ID LPAREN argument_list RPAREN {
                                                    logout<<"factor : ID LPAREN argument_list RPAREN \n";
                                                    SymbolInfo *s = NULL;
                                                    s = symTable->LookUp($1->get_name());  
                                                    
                                                    if(s==NULL){
                                                        errout<<"Line# "<<line_count<<" : "<<"Undeclared function "<<($1->get_name())<< "\n";
                                                    } 
                                                 }
                                                 
                | LPAREN expression RPAREN       {logout<<"factor : LPAREN expression RPAREN \n";}
                | CONST_INT                      {logout<<"factor : CONST_INT \n";}
                | CONST_FLOAT                    {logout<<"factor : CONST_FLOAT \n";}
                | variable INCOP                 {logout<<"factor : variable INCOP\n";}
                | variable DECOP                 {logout<<"factor : variable DECOP\n";}
                ;

argument_list   : arguments {logout<<"argument_list : arguments\n";}
                |
                ;

arguments       : arguments COMMA logic_expression 
                | logic_expression {logout<<"arguments  : logic_expression\n";}
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
