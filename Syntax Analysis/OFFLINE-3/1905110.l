%option noyywrap


%x CONST_CHAR
%x STRING
%x S_COMMENT
%x M_COMMENT

%{
#include<bits/stdc++.h>
#include "y.tab.h"

using namespace std;
typedef long long ll;

int line_count=1,interal_line = 0;


extern YYSTYPE yylval;

ofstream logout;
ofstream tokenout;

ll buckets = 10;
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


%}

KEYWORD if|for|do|int|float|void|switch|default|else|while|break|char|double|return|case|continue
WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
RELOP "<"|"<="|">"|">="|"=="|"!="   
BITOP "&"|"|"|"^"|"<<"|">>"	 
MULOP "*"|"%"|"/"	
INCOP "++"|"--"		
LOGICOP "&&"|"||"	
DIGIT [0-9]
DIGITS {DIGIT}+
FLOAT {DIGITS}?(\.{DIGITS})?(E[+-]?{DIGITS})?
IDENTIFIER [_A-Za-z][A-Za-z0-9_]*
NEWLINE \n

%%

{WHITESPACE} {}
{NEWLINE} {
			line_count++;
			return NEWLINE;	
		}

{KEYWORD} {
			
			
			//yylval.str = makeUpper(yytext);
			return KEYWORD;
			
		}

"+"		{
			tokenout<<"<ADDOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <ADDOP> Lexeme "<<yytext<<" found\n";
			return PLUS;
		}
"-"		{
			tokenout<<"<ADDOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <ADDOP> Lexeme "<<yytext<<" found\n";
			return MINUS;
		}

"*" {
			tokenout<<"<MULOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <MULOP> Lexeme "<<yytext<<" found\n";
			return ASTERISK;
		}
"/"     {
			tokenout<<"<MULOP, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <MULOP> Lexeme "<<yytext<<" found\n";
			return SLASH;
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
			return NOT;
		}

"("		{
			tokenout<<"<LPAREN, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <LPAREN> Lexeme "<<yytext<<" found\n";
			return LPAREN;
		}

")"		{
			tokenout<<"<RPAREN, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <RPAREN> Lexeme "<<yytext<<" found\n";
			return RPAREN;
		}

"{"		{
			tokenout<<"<LCURL, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <LCURL> Lexeme "<<yytext<<" found\n";
			return LCURL;
			
		}

"}"		{
			
			tokenout<<"<RCURL, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <RCURL> Lexeme "<<yytext<<" found\n";
			return RCURL;
		}


"["		{
			tokenout<<"<LSQUARE, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <LSQUARE> Lexeme "<<yytext<<" found\n";
			return LSQUARE;
		}

"]"		{
			tokenout<<"<RSQUARE, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <RSQUARE> Lexeme "<<yytext<<" found\n";
			return RSQUARE;
		}
","		{
			tokenout<<"<COMMA, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <COMMA> Lexeme "<<yytext<<" found\n";
			return COMMA;
		}

";"		{
			tokenout<<"<SEMICOLON, "<<yytext<<">\n";
			logout<<"Line# "<<line_count<<": Token <SEMICOLON> Lexeme "<<yytext<<" found\n";
			return SEMICOLON;
		}
		
{DIGITS} {
				
				
				tokenout<<"<CONST_INT, "<<yytext<<">\n";
				logout<<"Line# "<<line_count<<": Token <CONST_INT> Lexeme "<<yytext<<" found\n";


				//sscanf(yytext,"%lf", &yylval);
				yylval = atof(yytext);

				cout<<"\'"<<yylval<<"\'\n";
				return NUMBER;
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
					tokenout<<"<CONST_CHAR, "<<ch<<">\n";
					logout<<"Line# "<<line_count<<": Token <CONST_CHAR> Lexeme \0 found\n";
				}
				else{
					error++;
					logout<<"Error at line# "<<line_count<<": EMPTY_CONST_CHAR '"<<logStr<<"'\n";
				}
			}
			else if(ch.size() == 1){
				
				logStr+=yytext;
				tokenout<<"<CONST_CHAR, "<<ch<<">\n";
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
					tokenout<<"<SINGLE LINE STRING, "<<ch<<">\n";
					logout<<"Line# "<<line_count<<": Token <SINGLE LINE STRING> Lexeme "<<logStr<<" found\n";
				}
				else {
					tokenout<<"<MULTI LINE STRING, "<<ch<<">\n";
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


