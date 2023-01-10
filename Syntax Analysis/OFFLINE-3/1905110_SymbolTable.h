#ifndef _1905110_SYMBOLTABLE_H
#define _1905110_SYMBOLTABLE_H

#include<bits/stdc++.h>
#include"1905110_ScopeTable.h"

class SymbolTable
{
private:
    long long id = 0;
    long long  num_buckets=0;
    ScopeTable *currentScope = NULL ;

public:

    SymbolTable(long long);
    ~SymbolTable();

    ScopeTable* EnterScope();
    ScopeTable* ExitScope();
    void ExitAllScope();
    ScopeTable* getCurrentScope();
    bool Insert(string , string , string , ofstream& );
    bool Remove(string);
    SymbolInfo* LookUp(string);
    void PrintCurrent(ofstream& logout);
    void PrintAll(ofstream& logout);
};

#endif