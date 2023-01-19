#include "1905110_SymbolInfo.h"

SymbolInfo::SymbolInfo(){
    
}
SymbolInfo::SymbolInfo(string name,string type){
    SymbolInfo::name = name;
    SymbolInfo::type = type;
    SymbolInfo::returnType = "";
    SymbolInfo::arraySize = 0;
    SymbolInfo::next = NULL ;
    SymbolInfo::childList = new vector<SymbolInfo*>();
}
SymbolInfo::SymbolInfo(string name,string type,string returnType){
    SymbolInfo::name = name;
    SymbolInfo::type = type;
    SymbolInfo::arraySize = 0;
    SymbolInfo::returnType = returnType;
    SymbolInfo::next = NULL ;
    SymbolInfo::childList = new vector<SymbolInfo*>();
}
SymbolInfo::SymbolInfo(string name,string type,int line){
    SymbolInfo::name = name;
    SymbolInfo::type = type;
    SymbolInfo::arraySize = 0;
    SymbolInfo::returnType = "";
    SymbolInfo::next = NULL ;
    SymbolInfo::startline = line;
    SymbolInfo::endline = line;
    SymbolInfo::childList = new vector<SymbolInfo*>();

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
void SymbolInfo::set_type(string type){
        SymbolInfo::type = type;
    }
string SymbolInfo::get_name(){
        return SymbolInfo::name;
    }
string SymbolInfo::get_returnType(){
        return SymbolInfo::returnType;
    }
vector<SymbolInfo> SymbolInfo::get_param(){
        return SymbolInfo::parameters;
    }
void SymbolInfo::set_param(SymbolInfo param){
        SymbolInfo::parameters.push_back(param);
    }
void SymbolInfo::set_param(vector<SymbolInfo> param){
        SymbolInfo::parameters = param;
    }
void SymbolInfo::set_name(string name){
        SymbolInfo::name = name;
    }
void SymbolInfo::set_returnType(string returnType){
        SymbolInfo::returnType = returnType;
    }
void SymbolInfo::set_child(SymbolInfo *child){
    SymbolInfo::childList->push_back(child);
}
vector<SymbolInfo*>* SymbolInfo::get_child(){
    return SymbolInfo::childList;
}
int SymbolInfo::get_arraySize(){
    return SymbolInfo::arraySize;
}
void SymbolInfo::set_arraySize(int size){
    SymbolInfo::arraySize = size;
}
void SymbolInfo::set_start(int start){
    SymbolInfo::startline = start;
}
void SymbolInfo::set_end(int end){
    SymbolInfo::endline = end;
}
int SymbolInfo::get_start(){
    return SymbolInfo::startline;
}
int SymbolInfo::get_end(){
    return SymbolInfo::endline;
}

void SymbolInfo::printChild(int depth,ofstream &parsetree){
    for(int i=1;i<=depth;i++){
        parsetree<<" ";
    }
    if(childList->size()==0){
        parsetree<<get_name()<<" : "<<get_type()<<"\t"<<"<Line: "<<startline<<">\n";
    }
    else{

        parsetree<<get_name()<<" : "<<get_type()<<"\t"<<" <Line: "<<startline<<"-"<<endline<<">\n";
        
        for(SymbolInfo *info : *childList){
            
                info->printChild(depth+1,parsetree);
            
        }
    }
}