%option noyywrap


%x CONST_CHAR
%x S_STRING
%x M_STRING
%x S_COMMENT
%x M_COMMENT

%{
#include<bits/stdc++.h>
#include "1905110_SymbolInfo.cpp"
#include "1905110_ScopeTable.cpp"
#include "1905110_SymbolTable.cpp"

using namespace std;
typedef long long ll;

int line_count=1;

ofstream logout;
ofstream tokenout;

ll buckets = 10;
int error = 0;
int checkMulti = 0;

SymbolTable *st = new SymbolTable(buckets);
ScopeTable *sc = st->EnterScope();

string str1,ch;
string makeUpper(string str){
	
	str1 = str;
	for (int x=0; x<str.size(); x++){
        str1[x] = toupper(str[x]);

	}
	return str1;
}


%}

KEYWORD if|for|do|int|float|void|switch|default|else|while|break|char|double|return|case|continue
WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
RELOP "<"|"<="|">"|">="|"=="|"!="   
BITOP "&"|"|"|"^"|"<<"|">>"	 
MULOP "*"|"%"|"/"	
INCOP "++"|"--"	
ADDOP "+"|"-"	
LOGICOP "&&"|"||"	
DIGIT [0-9]
DIGITS {DIGIT}+
FLOAT {DIGITS}?(\.{DIGITS})?(E[+-]?{DIGITS})?
IDENTIFIER [_A-Za-z][A-Za-z0-9_]*
NEWLINE \n

%%

{WHITESPACE} {}
{NEWLINE} {line_count++;}

{KEYWORD} {
			
			tokenout<<"<"<<makeUpper(yytext)<<", "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <"<<makeUpper(yytext)<<"> Lexeme "<<yytext<<" found\n";
			
		}

{ADDOP}	{
			tokenout<<"<ADDOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <ADDOP> Lexeme "<<yytext<<" found\n";
		}

{MULOP} {
			tokenout<<"<MULOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <MULOP> Lexeme "<<yytext<<" found\n";
		}

{INCOP} {
			tokenout<<"<INCOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <INCOP> Lexeme "<<yytext<<" found\n";
		}
{RELOP} {
			tokenout<<"<RELOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <RELOP> Lexeme "<<yytext<<" found\n";
		}

"="		{
			tokenout<<"<ASSIGNOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <ASSIGNOP> Lexeme "<<yytext<<" found\n";
		}

{LOGICOP}	{
			tokenout<<"<LOGICOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <LOGICOP> Lexeme "<<yytext<<" found\n";
		}

{BITOP} {
			tokenout<<"<BITOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <BITOP> Lexeme "<<yytext<<" found\n";
		}

"!"		{
			tokenout<<"<NOT, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <NOT> Lexeme "<<yytext<<" found\n";
		}

"("		{
			tokenout<<"<LPAREN, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <LPAREN> Lexeme "<<yytext<<" found\n";
		}

")"		{
			tokenout<<"<RPAREN, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <RPAREN> Lexeme "<<yytext<<" found\n";
		}

"{"		{
			st->EnterScope();
			tokenout<<"<LCURL, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <LCURL> Lexeme "<<yytext<<" found\n";
		}

"}"		{
			st->ExitScope();
			tokenout<<"<RCURL, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <RCURL> Lexeme "<<yytext<<" found\n";
		}


"["		{
			tokenout<<"<LSQUARE, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <LSQUARE> Lexeme "<<yytext<<" found\n";
		}

"]"		{
			tokenout<<"<RSQUARE, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <RSQUARE> Lexeme "<<yytext<<" found\n";
		}
","		{
			tokenout<<"<COMMA, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <COMMA> Lexeme "<<yytext<<" found\n";
		}

";"		{
			tokenout<<"<SEMICOLON, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <SEMICOLON> Lexeme "<<yytext<<" found\n";
		}
		
{DIGITS} {
				
				
				tokenout<<"<CONST_INT, "<<yytext<<">\n";
				logout<<"Line# "<<line_count<<": Token <CONST_INT> Lexeme "<<yytext<<" found\n";
				
			}
{DIGITS}{LETTER}+ {
				ch.clear();
				ch+=yytext;
				error++;
				logout<<"Error at line# "<<line_count<<": INVALID_ID_SUFFIX_NUM_PREFIX "<<ch<<'\n';
		}

{FLOAT} {
				tokenout<<"<CONST_FLOAT, "<<yytext<<">\n";
				logout<<"Line# "<<line_count<<": Token <CONST_FLOAT> Lexeme "<<yytext<<" found\n";
		}
{DIGITS}?(\.{DIGITS})*?(E[+-]?{DIGITS})?  {
				ch.clear();
				ch+=yytext;
				error++;
				logout<<"Error at line# "<<line_count<<": TOO_MANY_DECIMAL_POINTS "<<ch<<"\n";
		
	}
{DIGITS}?(\.{DIGITS})?(E[+-]?(\.*{DIGITS})*) {
				ch.clear();
				ch+=yytext;
				error++;
				logout<<"Error at line# "<<line_count<<": ILLFORMED_NUMBER "<<ch<<"\n";
		
	}

{IDENTIFIER} {
				tokenout<<"<ID, "<<yytext<<">\n";
				logout<<"Line# "<<line_count<<": Token <ID> Lexeme "<<yytext<<" found\n";
				int x = st->Insert(yytext,"ID",logout);
				if(x)st->PrintAll(logout);
		}

\'  	{
			ch.clear();
			
			BEGIN(CONST_CHAR);			
	    }
<CONST_CHAR>{LETTER} {ch += yytext;}
<CONST_CHAR>\\t {ch+="\t";}
<CONST_CHAR>\\n {ch+="\n";}
<CONST_CHAR>\\\\ {ch+="\\";}
<CONST_CHAR>\\\" {ch+="\"";}
<CONST_CHAR>\\\' {ch+="\'";}
<CONST_CHAR>\\a {ch+="\a";}
<CONST_CHAR>\\f {ch+="\f";}
<CONST_CHAR>\\r {ch+="\r";}
<CONST_CHAR>\\b {ch+="\b";}
<CONST_CHAR>\\v {ch+="\v";}
<CONST_CHAR>\\0 {ch+="\0";}

<CONST_CHAR>\' {
			
			if(ch.size() == 0){
				if(ch=="\\0"){
					tokenout<<"<CONST_CHAR,"<<ch<<">\n";
					logout<<"Line# "<<line_count<<": Token <CONST_CHAR> Lexeme \0 found\n";
				}
				else{
					error++;
					logout<<"Error at line# "<<line_count<<": EMPTY_CONST_CHAR ''\n";
				}
			}
			else{
				ch+=yytext;
				tokenout<<"<CONST_CHAR,"<<ch<<">\n";
				logout<<"Line# "<<line_count<<": Token <CONST_CHAR> Lexeme '"<<ch<<" found\n";	
			}
			BEGIN(INITIAL);
		}
<CONST_CHAR>{LETTER}{LETTER}+({WHITESPACE}?{LETTER}+)*?\' {
			error++;
			logout<<"Error at line# "<<line_count<<": MULTICHAR_CONST_CHAR '"<<yytext<<"\n";
			BEGIN(INITIAL);
		}
<CONST_CHAR>{NEWLINE} {
			error++;
			logout<<"Error at line# "<<line_count<<": UNFINISHED_CONST_CHAR '"<<ch<<'\n';
			line_count++;
			BEGIN(INITIAL);
		}


\" {
		ch.clear();
		BEGIN(S_STRING);
}
<S_STRING>({WHITESPACE}?{LETTER}+)+? {
			ch+=yytext;
		}
<S_STRING>\" {
			if(ch.size() == 0){
					error++;
					logout<<"Error at line# "<<line_count<<": EMPTY STRING ''\n";	
			}
			else{
				
				if(!checkMulti){
					tokenout<<"<SINGLE LINE STRING,"<<ch<<">\n";
					logout<<"Line# "<<line_count<<": Token <SINGLE LINE STRING> Lexeme \""<<ch<<"\" found\n";
				}
				else {
					tokenout<<"<MULTI LINE STRING,"<<ch<<">\n";
					logout<<"Line# "<<line_count<<": Token <MULTI LINE STRING> Lexeme \""<<ch<<"\" found\n";
				}
			}
			BEGIN(INITIAL);
		}
<S_STRING>\\{NEWLINE} {
			ch+=yytext;
			checkMulti = 1;
			line_count++;
		}
<S_STRING>\\t {ch+="\t";}
<S_STRING>>\\n {ch+="\n";}
<S_STRING>>\\\\ {ch+="\\";}
<S_STRING>>\\\" {ch+="\"";}
<S_STRING>>\\a {ch+="\a";}
<S_STRING>>\\f {ch+="\f";}
<S_STRING>>\\r {ch+="\r";}
<S_STRING>>\\b {ch+="\b";}
<S_STRING>>\\v {ch+="\v";}
<S_STRING>>\\0 {ch+="\0";}

<S_STRING>{NEWLINE} {
			error++;
			logout<<"Error at line# "<<line_count<<": UNFINISHED_STRING \""<<ch<<"\n";
			line_count++;
			BEGIN(INITIAL);
		}


\/\/ {
		ch.clear();
		ch+=yytext;
		BEGIN(S_COMMENT);
	}
<S_COMMENT>. {
		ch+=yytext;
	}
<S_COMMENT>\\{NEWLINE} {
		ch+=yytext;
	}
<S_COMMENT>{NEWLINE} {
		
			logout<<"Line# "<<line_count<<": Token <SINGLE LINE COMMENT> Lexeme "<<ch<<" found\n";
			line_count++;
			BEGIN(INITIAL);
		
	}
<S_COMMENT><<EOF>> {
		logout<<"Line# "<<line_count<<": Token <SINGLE LINE COMMENT> Lexeme "<<ch<<" found\n";
		line_count++;
		BEGIN(INITIAL);
	}

\/\* {
		ch.clear();
		ch+=yytext;
		BEGIN(M_COMMENT);
	}
<M_COMMENT>. {
		ch+=yytext;
	}
<M_COMMENT>{NEWLINE} {
		ch+=yytext;
		line_count++;	
	}
<M_COMMENT>\*\/ {
		ch+=yytext;
		logout<<"Line# "<<line_count<<": Token <MULTI LINE COMMENT> Lexeme "<<ch<<" found\n";
		line_count++;
		BEGIN(INITIAL);
	}
<M_COMMENT><<EOF>> {
		error++;
		logout<<"Error at line# "<<line_count<<": UNFINISHED_COMMENT "<<ch<<"\n";
		line_count++;
		BEGIN(INITIAL);
}
. {
		ch.clear();
		ch+=yytext;
		error++;
		logout<<"Error at line# "<<line_count<<": UNRECOGNIZED_CHAR "<<ch<<"\n";
		
}

%%
int main(int argc, char** argv) {
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout.open("log.txt");
	tokenout.open("token.txt");

	yyin= fin;
	yylex();

	st->PrintAll(logout);
	logout<<"Total lines: "<<line_count<<'\n';
	logout<<"Total errors: "<<error<<'\n';
	
	fclose(yyin);
	logout.close();
	tokenout.close();
	return 0;
}
