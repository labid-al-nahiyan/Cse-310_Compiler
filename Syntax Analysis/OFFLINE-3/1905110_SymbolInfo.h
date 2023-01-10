#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include<bits/stdc++.h>

using namespace std;

class SymbolInfo
{
private:
    string name,type,returnType;
    SymbolInfo  *next ;
public:
    SymbolInfo();
    SymbolInfo(string, string );
    SymbolInfo(string, string ,string);
    void set_name(string name);
    void set_type(string type);
    void set_returnType(string returnType);
    string get_name();
    string get_type();
    string get_returnType();
    void set_next(SymbolInfo *next);
    SymbolInfo* get_next();
};

#endif


