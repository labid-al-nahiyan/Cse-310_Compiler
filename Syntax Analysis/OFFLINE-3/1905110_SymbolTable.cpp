#include "1905110_SymbolTable.h"
using namespace std;

SymbolTable::SymbolTable(long long num_buckets){
    SymbolTable::num_buckets = num_buckets;
}
ScopeTable* SymbolTable::EnterScope(){
    SymbolTable::id++;
    //cout<<"\tScopeTable# "<<this->id<<" created\n";
    ScopeTable *temp = new ScopeTable(SymbolTable::num_buckets,SymbolTable::id,SymbolTable::currentScope);
    
    currentScope = temp;
    return currentScope;
}
ScopeTable* SymbolTable::ExitScope(){
    if(currentScope->getParentScope() == NULL ){
        //cout<<"\tScopeTable# 1 cannot be removed\n";
        return NULL ;
    }
  //  cout<<"\tScopeTable# "<<this->currentScope->get_id()<<" removed\n";
    currentScope = currentScope->getParentScope();
    return currentScope;
}
void SymbolTable::ExitAllScope(){

    while(currentScope!=NULL ){
        //cout<<"\tScopeTable# "<<this->currentScope->get_id()<<" removed\n";
        currentScope = currentScope->getParentScope();
    }
    return ;
}
ScopeTable* SymbolTable::getCurrentScope(){
    return this->currentScope;
}
bool SymbolTable::Insert(string name, string type, string returnType, ofstream& logout){
    if(currentScope == NULL ){
      //  cout<<"\tCreate ScopeTable First\n";
        return 0;
    }
    cout<<name<<'\n';
    ScopeTable *temp = currentScope;
    int x =  currentScope->Insert(name,type,returnType, logout);
    cout<<x<<'\n';
    return x;
}
bool SymbolTable::Remove(string name){
    if(currentScope == NULL ){
        //cout<<"\tNo Scope in SymbolTable\n";
        return 0;
    }

    ScopeTable *temp = currentScope;
    return currentScope->Delete(name);
}
SymbolInfo* SymbolTable::LookUp(string name){
    if(currentScope == NULL ){
        //cout<<"\t'"<<name<<"' not found in any of the ScopeTables\n";
        return NULL ;
    }

    ScopeTable *temp = currentScope;

    while(temp!=NULL ){

        SymbolInfo *temp1 = temp->LookUp(name);

        if(temp1 != NULL )return temp1;

        temp = temp->getParentScope();
    }

    //cout<<"\t'"<<name<<"' not found in any of the ScopeTables\n";
    return NULL ;
}
SymbolInfo* SymbolTable::LookUpCurrent(string name){
    if(currentScope == NULL ){
        //cout<<"\t'"<<name<<"' not found in any of the ScopeTables\n";
        return NULL ;
    }
    cout<<name<<'\n';
    ScopeTable *temp = currentScope;

 //   while(temp!=NULL ){

        SymbolInfo *temp1 = temp->LookUp(name);

        if(temp1 != NULL )return temp1;

    //    temp = temp->getParentScope();
   // }

    //cout<<"\t'"<<name<<"' not found in any of the ScopeTables\n";
    return NULL ;
}
void SymbolTable::PrintCurrent(ofstream &logout){
    if(currentScope == NULL ){
       // cout<<"\tNothing for Print long\n";
        return;
    }

    currentScope->Print(logout);
}
void SymbolTable::PrintAll (ofstream &logout){
    if(currentScope == NULL ){
       // cout<<"\tNothing for Print long\n";
        return;
    }

    ScopeTable *temp = currentScope;

    while(temp!=NULL ){
        temp->Print(logout);
        temp = temp->getParentScope();
    }
}
SymbolTable::~SymbolTable(){
   
    // delete currentScope;

    ScopeTable *temp = currentScope;
    
    while (temp != NULL)
    {
        currentScope = currentScope->getParentScope();
        delete temp;
        temp = currentScope;
    }
}
