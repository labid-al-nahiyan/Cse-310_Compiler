%option noyywrap

%x CONST_CHAR
%x STRING
%x S_COMMENT
%x M_COMMENT

%{


#include "bits/stdc++.h"
#include "1905110_SymbolTable.h"
#include "1905110_SymbolInfo.h"
#include "1905110_ScopeTable.h"
#include "y.tab.h"

using namespace std;
typedef long long ll;

int line_count=1,interal_line = 0;


extern ofstream logout;
//extern SymbolTable *symTable;
//extern ofstream //tokenout;
//ll buckets = 10;
int error = 0;
int checkMulti = 0;
string str1,ch,logStr;

string makeUpper(string str){
	
	str1 = str;
	for (int x=0; x<str.size(); x++){
        str1[x] = toupper(str[x]);

	}
	return str1;
}

void terminalSymbol(string str1,string str2, int line){
	logout<<"Line# "<<line_count<<": Token <"<<str1<<"> Lexeme "<<str2<<" found\n";
    yylval.symInfo = new SymbolInfo(str1,str2,line);
}

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
RELOP "<"|"<="|">"|">="|"=="|"!="   
BITOP "&"|"|"|"^"|"<<"|">>"	
ADDOP "+"|"-" 
MULOP "*"|"%"|"/"	
INCOP "++"
DECOP "--"		
LOGICOP "&&"|"||"	
DIGIT [0-9]
DIGITS {DIGIT}+
FLOAT {DIGITS}?(\.{DIGITS})?(E[+-]?{DIGITS})?
IDENTIFIER [_A-Za-z][_A-Za-z0-9]*
NEWLINE \n

%%

{WHITESPACE} {}
{NEWLINE} {
			line_count++;
				
		}
if       {	
			terminalSymbol("IF","if",line_count);
			return IF;
		 }
else     {
			terminalSymbol("ELSE","else",line_count);
			return ELSE; 
		 }
for      {
			terminalSymbol("FOR","for",line_count);
			return FOR; 
		 }
while    {
			terminalSymbol("WHILE","while",line_count);
			return WHILE; 
		 }
do       {
			terminalSymbol("DO","do",line_count);
			return DO; 
		 }
break    {
			terminalSymbol("BREAK","break",line_count);
			return BREAK; 
		 }
int      {
			terminalSymbol("INT","int",line_count);
			return INT; 
		 }
char     {
			terminalSymbol("CHAR","char",line_count);
			return CHAR; 
		 }
float    {
			terminalSymbol("FLOAT","float",line_count);
			return FLOAT; 
		 }
double   {
			terminalSymbol("Double","double",line_count);
			return DOUBLE; 
		 }
void     {
			terminalSymbol("VOID","void",line_count);
			return VOID; 
		 }
return   {	
	
			terminalSymbol("RETURN","return",line_count);
			return RETURN;}
switch   {	
			terminalSymbol("SWITCH","switch",line_count);
			return SWITCH;}
case     {
			terminalSymbol("CASE","case",line_count);
			return CASE;}
default  {
			terminalSymbol("DEFAULT","default",line_count);
			return DEFAULT;
		 }
continue {
			terminalSymbol("CONTINUE","continue",line_count);
			return CONTINUE;
		 }
printf	 {
			terminalSymbol("PRINTLN","printf",line_count);
			return PRINTLN;
		 }

{ADDOP}		{
			////tokenout<<"<ADDOP, "<<yytext<<">\n";
			
			terminalSymbol("ADDOP",yytext,line_count);
			// yylval = 10;
			return ADDOP;
		}


{MULOP} {
			//tokenout<<"<MULOP, "<<yytext<<">\n";
			terminalSymbol("MULOP",yytext,line_count);
			return MULOP;
		}


{INCOP} {
			//tokenout<<"<INCOP, "<<yytext<<">\n";
			terminalSymbol("INCOP",yytext,line_count);
			return INCOP;
		}
{DECOP} {
			//tokenout<<"<INCOP, "<<yytext<<">\n";
			terminalSymbol("DECOP",yytext,line_count);
			return DECOP;
		}

{RELOP} {
			//tokenout<<"<RELOP, "<<yytext<<">\n";
			terminalSymbol("RELOP",yytext,line_count);
			return RELOP;
		}

"="		{
			//tokenout<<"<ASSIGNOP, "<<yytext<<">\n";
			terminalSymbol("ASSIGNOP","=",line_count);
			return ASSIGNOP;
		}

{LOGICOP}	{
			//tokenout<<"<LOGICOP, "<<yytext<<">\n";
			terminalSymbol("LOGICOP",yytext,line_count);
			return LOGICOP;
		}

{BITOP} {
			//tokenout<<"<BITOP, "<<yytext<<">\n";
			terminalSymbol("BITOP",yytext,line_count);
			return BITOP;
		}

"!"		{
			//tokenout<<"<NOT, "<<yytext<<">\n";
			terminalSymbol("NOT","!",line_count);
			return NOT;
		}

"("		{
			//tokenout<<"<LPAREN, "<<yytext<<">\n";
			terminalSymbol("LPAREN","(",line_count);
			return LPAREN;
		}

")"		{
			//tokenout<<"<RPAREN, "<<yytext<<">\n";
			terminalSymbol("RPAREN",")",line_count);
			return RPAREN;
		}

"{"		{
			//tokenout<<"<LCURL, "<<yytext<<">\n";
			terminalSymbol("LCURL","{",line_count);
			return LCURL;
			
		}

"}"		{
			
			//tokenout<<"<RCURL, "<<yytext<<">\n";
			terminalSymbol("RCURL","}",line_count);
			return RCURL;
		}


"["		{
			//tokenout<<"<LSQUARE, "<<yytext<<">\n";
			terminalSymbol("LSQUARE","[",line_count);
			return LSQUARE;
		}

"]"		{
			//tokenout<<"<RSQUARE, "<<yytext<<">\n";
			terminalSymbol("RSQUARE","]",line_count);
			return RSQUARE;
		}
","		{
			//tokenout<<"<COMMA, "<<yytext<<">\n";
			terminalSymbol("COMMA",",",line_count);
			return COMMA;
		}

";"		{
			//tokenout<<"<SEMICOLON, "<<yytext<<">\n";
			terminalSymbol("SEMICOLON",";",line_count);
			return SEMICOLON;
		}
		
{DIGITS} {
				
				
				//tokenout<<"<CONST_INT, "<<yytext<<">\n";
				
				terminalSymbol("CONST_INT",yytext,line_count);

				return CONST_INT;
			}
{DIGITS}{LETTER}+ {
				ch.clear();
				ch+=yytext;
				error++;
				logout<<"Error at line# "<<line_count<<": INVALID_ID_SUFFIX_NUM_PREFIX "<<ch<<'\n';
		}

{FLOAT} {
				//tokenout<<"<CONST_FLOAT, "<<yytext<<">\n";
				
				terminalSymbol("CONST_FLOAT",yytext,line_count);
				return CONST_FLOAT;
				
		}
{DIGITS}?((\.)+{DIGITS})*?(E[+-]?{DIGITS})?  {
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
				//tokenout<<"<ID, "<<yytext<<">\n";
				logout<<"Line# "<<line_count<<": Token <ID> Lexeme "<<yytext<<" found\n";
				
				yylval.symInfo = new SymbolInfo("ID",yytext,line_count);

				//terminalSymbol("ID",yytext,line_count);
				return ID;
		}


\'  	{
			ch.clear();
			logStr.clear();
			
			BEGIN(CONST_CHAR);			
	    }
<CONST_CHAR>\\t {ch+="\t";logStr+="\\t";}
<CONST_CHAR>\\n {ch+="\n";logStr+="\\n";}
<CONST_CHAR>\\\\ {ch+="\\";logStr+="\\\\";}
<CONST_CHAR>\\\" {ch+="\"";logStr+="\\\"";}
<CONST_CHAR>\\\' {ch+="\'";logStr+="\\\'";}
<CONST_CHAR>\\a {ch+="\a";logStr+="\\\a";}
<CONST_CHAR>\\f {ch+="\f";logStr+="\\\f";}
<CONST_CHAR>\\r {ch+="\r";logStr+="\\\r";}
<CONST_CHAR>\\b {ch+="\b";logStr+="\\\b";}
<CONST_CHAR>\\v {ch+="\v";logStr+="\\\v";}
<CONST_CHAR>\\0 {ch+="\0";logStr+="\\\0";}


<CONST_CHAR>{NEWLINE} {
			error++;
			logout<<"Error at line# "<<line_count<<": UNFINISHED_CONST_CHAR '"<<logStr<<'\n';
			line_count++;
			BEGIN(INITIAL);
		}
<CONST_CHAR><<EOF>> {
			error++;
			logout<<"Error at line# "<<line_count<<": UNFINISHED_CONST_CHAR '"<<logStr<<'\n';
			line_count++;
			BEGIN(INITIAL);
        }
<CONST_CHAR>\' {
			
			if(ch.size() == 0){
				if(ch=="\\0"){
					//tokenout<<"<CONST_CHAR, "<<ch<<">\n";
					logout<<"Line# "<<line_count<<": Token <CONST_CHAR> Lexeme \0 found\n";
				}
				else{
					error++;
					logout<<"Error at line# "<<line_count<<": EMPTY_CONST_CHAR '"<<logStr<<"'\n";
				}
			}
			else if(ch.size() == 1){
				
				logStr+=yytext;
				//tokenout<<"<CONST_CHAR, "<<ch<<">\n";
				logout<<"Line# "<<line_count<<": Token <CONST_CHAR> Lexeme "<<ch<<" found\n";	
			}
			else{
				error++;
				logout<<"Error at line# "<<line_count<<": MULTICHAR_CONST_CHAR '"<<ch<<"'\n";
			
			}
			BEGIN(INITIAL);
		}

<CONST_CHAR>. {
			logStr+=yytext;
			ch+=yytext;
		}

\" {
		ch.clear();
		logStr.clear();
		logStr+=yytext;
		interal_line=0;
		BEGIN(STRING);
}


<STRING>\\t {ch+="\t";logStr+="\\t";}
<STRING>\\n {ch+="\n";logStr+="\\n";}
<STRING>\\\\ {ch+="\\";logStr+="\\\\";}
<STRING>\\\" {ch+="\"";logStr+="\\\"";}
<STRING>\\\' {ch+="\'";logStr+="\\\'";}
<STRING>\\a {ch+="\a";logStr+="\\\a";}
<STRING>\\f {ch+="\f";logStr+="\\\f";}
<STRING>\\r {ch+="\r";logStr+="\\\r";}
<STRING>\\b {ch+="\b";logStr+="\\\b";}
<STRING>\\v {ch+="\v";logStr+="\\\v";}
<STRING>\\0 {ch+="\0";logStr+="\\\0";}

<STRING>\\{NEWLINE} {
			logStr+=yytext;
			checkMulti = 1;
			interal_line++;
		}
<STRING>{NEWLINE} {
			error++;
			line_count+=interal_line;
			logout<<"Error at line# "<<line_count<<": UNFINISHED_STRING "<<logStr<<"\n";
			line_count++;
			interal_line=0;
			BEGIN(INITIAL);
		}
<STRING><<EOF>> {
			error++;
			line_count+=interal_line;
			logout<<"Error at line# "<<line_count<<": UNFINISHED_STRING "<<logStr<<"\n";
			line_count++;
			interal_line=0;
			BEGIN(INITIAL);
		}

<STRING>["] {
			
			logStr+=yytext;
			if(ch.size() == 0){
					error++;
					logout<<"Error at line# "<<line_count<<": EMPTY STRING ''\n";	
			}
			else{
				if(!checkMulti){
					//tokenout<<"<SINGLE LINE STRING, "<<ch<<">\n";
					logout<<"Line# "<<line_count<<": Token <SINGLE LINE STRING> Lexeme "<<logStr<<" found\n";
				}
				else {
					//tokenout<<"<MULTI LINE STRING, "<<ch<<">\n";
					logout<<"Line# "<<line_count<<": Token <MULTI LINE STRING> Lexeme "<<logStr<<" found\n";
					checkMulti = 0;

				}	
			}
			line_count+=interal_line;
			interal_line=0;
			BEGIN(INITIAL);
		}
<STRING>. {
			
			ch+=yytext;
			logStr+=yytext;
		}

\/\/ {
		ch.clear();
		logStr.clear();
		interal_line = 0;
		ch+=yytext;
		logStr+=yytext;
		BEGIN(S_COMMENT);
	}
<S_COMMENT>. {
		ch+=yytext;
		logStr+=yytext;
	}
<S_COMMENT>\\{NEWLINE} {
		ch+=yytext;
		logStr+=yytext;
		interal_line++;
	}
<S_COMMENT>{NEWLINE} {
		
			logout<<"Line# "<<line_count<<": Token <SINGLE LINE COMMENT> Lexeme "<<logStr<<" found\n";
			line_count+=interal_line;
			interal_line=0;
			line_count++;
			BEGIN(INITIAL);
		
	}
<S_COMMENT><<EOF>> {
		line_count+=interal_line;
		logout<<"Line# "<<line_count<<": Token <SINGLE LINE COMMENT> Lexeme "<<ch<<" found\n";
		interal_line=0;
		
		BEGIN(INITIAL);
	}

\/\* {
		logStr.clear();
		logStr+=yytext;
		interal_line=0;
		BEGIN(M_COMMENT);
	}
<M_COMMENT>. {
		logStr+=yytext;
	}
<M_COMMENT>{NEWLINE} {
		
		logStr+=yytext;
		interal_line++;	
	}
<M_COMMENT>\*\/ {
		logStr+=yytext;
		logout<<"Line# "<<line_count<<": Token <MULTI LINE COMMENT> Lexeme "<<logStr<<" found\n";
		line_count+=interal_line;
		interal_line=0;
		BEGIN(INITIAL);
	}
<M_COMMENT><<EOF>> {
		error++;
		line_count+=interal_line;
		logout<<"Error at line# "<<line_count<<": UNFINISHED_COMMENT "<<logStr<<"\n";
		interal_line=0;
		BEGIN(INITIAL);
}

. {
		ch.clear();
		ch+=yytext;
		error++;
		logout<<"Error at line# "<<line_count<<": UNRECOGNIZED_CHAR "<<ch<<"\n";
		
}


