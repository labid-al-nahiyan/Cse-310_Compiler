#include<bits/stdc++.h>

using namespace std;
typedef long long ll ;


class SymbolInfo
{
private:
    string name,type;
    SymbolInfo  *next ;
public:
    SymbolInfo();
    SymbolInfo(string, string );

    void set_name(string name){
        this->name = name;
    }
    void set_type(string type){
        this->type = type;
    }
    string get_name(){
        return this->name;
    }
    string get_type(){
        return this->type;
    }
    void set_next(SymbolInfo *next){
        this->next = next;
    }
    SymbolInfo* get_next(){
        return this->next;
    }
};
SymbolInfo::SymbolInfo(){
}
SymbolInfo::SymbolInfo(string name,string type){
    this->name = name;
    this->type = type;
    this->next = NULL ;
}

