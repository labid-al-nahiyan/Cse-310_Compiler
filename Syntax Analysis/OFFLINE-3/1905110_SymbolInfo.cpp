#include "1905110_SymbolInfo.h"

SymbolInfo::SymbolInfo(){
    
}
SymbolInfo::SymbolInfo(string name,string type){
    SymbolInfo::name = name;
    SymbolInfo::type = type;
    SymbolInfo::returnType = "";
    SymbolInfo::next = NULL ;
}
SymbolInfo::SymbolInfo(string name,string type,string returnType){
    SymbolInfo::name = name;
    SymbolInfo::type = type;
    SymbolInfo::returnType = returnType;
    SymbolInfo::next = NULL ;
}
SymbolInfo* SymbolInfo::get_next(){
        return next;
}
void SymbolInfo::set_next(SymbolInfo *next){
        SymbolInfo::next = next;
    }
string SymbolInfo::get_type(){
        return SymbolInfo::type;
    }
string SymbolInfo::get_name(){
        return SymbolInfo::name;
    }
string SymbolInfo::get_returnType(){
        return SymbolInfo::returnType;
    }
void SymbolInfo::set_type(string type){
        SymbolInfo::type = type;
    }
void SymbolInfo::set_name(string name){
        SymbolInfo::name = name;
    }
void SymbolInfo::set_returnType(string returnType){
        SymbolInfo::returnType = returnType;
    }