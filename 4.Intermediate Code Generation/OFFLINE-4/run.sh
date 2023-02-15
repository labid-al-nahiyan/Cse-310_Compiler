#!/bin/bash

# yacc -d -y 1905110_parser.y
# echo 'Generated the parser C file as well the header file'
# #g++ -w -c -o y.o y.tab.c
# echo 'Generated the parser object file'
# flex 1905110_lex.l
# echo 'Generated the scanner C file'
# #g++ -w -c -o l.o lex.yy.c
# # if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
# echo 'Generated the scanner object file'
# #g++ y.o l.o -lfl -o 1905110
# g++ y.tab.c lex.yy.c -lfl
# echo 'All ready, running'
# #./1905110 input.txt

yacc -d -y -v 1905110_parser.y #-Wcounterexamples
#echo 'Generated the parser C file as well the header file'
g++ -w -c -o y.o y.tab.c
#echo 'Generated the parser object file'
flex 1905110_lex.l
#echo 'Generated the scanner C file'
g++ -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
#echo 'Generated the scanner object file'
g++  1905110_SymbolInfo.cpp 1905110_ScopeTable.cpp 1905110_SymbolTable.cpp -c
#echo 'Generated the symbol table object files'
g++ 1905110_SymbolInfo.o 1905110_ScopeTable.o 1905110_SymbolTable.o y.o l.o -lfl -o 1905110 
echo 'All ready, running'
#./1905110 errorrecover.c
./1905110 input.c

