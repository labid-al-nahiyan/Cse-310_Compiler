flex -o lex.yy.c 1905110.l
g++ lex.yy.c -lfl -o a.out
./a.out sample_input.txt
