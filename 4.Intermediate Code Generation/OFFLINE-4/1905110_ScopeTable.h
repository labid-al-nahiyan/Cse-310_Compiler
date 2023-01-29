#ifndef _1905110_SCOPETABLE_H
#define _1905110_SCOPETABLE_H

#include<bits/stdc++.h>
#include"1905110_SymbolInfo.h"

class ScopeTable
{
private:

    long long  num_buckets ;
    long long   id;
    SymbolInfo **symbolArray ;
    ScopeTable *parent_scope;
    long long  SDBMHash(string str);

public:
    ScopeTable(long long  num_buckets ,long long  id,  ScopeTable *parent_scope);
    bool Insert(string ,string,string, ofstream&);
    SymbolInfo* LookUp(string);
    bool Delete(string);
    void Print(ofstream& logout);
    long long  get_id();
    long long  get_numbucket();
    ScopeTable* getParentScope();

    ~ScopeTable();
};


#endif