#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include<bits/stdc++.h>

using namespace std;

class SymbolInfo
{
private:
    string name,type,returnType,value="";
    vector<SymbolInfo> parameters;
    vector<SymbolInfo*>* childList;
    int startline ,endline , arraySize;
    SymbolInfo  *next ;
public:
    SymbolInfo();
    SymbolInfo(string, string );
    SymbolInfo(string, string ,string);
    SymbolInfo(string, string, int);
    void set_name(string name);
    void set_type(string type);
    void set_returnType(string returnType);
    string get_name();
    string get_type();
    string get_returnType();
    vector<SymbolInfo> get_param();
    void set_param(SymbolInfo);
    void set_param(vector<SymbolInfo>);
    void set_next(SymbolInfo *next);
    void set_child(SymbolInfo *child);
    vector<SymbolInfo*>* get_child();
    void set_start(int start);
    void set_end(int end);
    int get_start();
    void set_arraySize(int size);
    int get_arraySize();
    int get_end();
    string get_value();
    void set_value(string s);
    SymbolInfo* get_next();

    void printChild(int ,ofstream&);
};

#endif


