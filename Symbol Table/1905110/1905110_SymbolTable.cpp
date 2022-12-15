
class SymbolTable
{
private:
    ll id = 0;
    ll num_buckets=0;
    ScopeTable *currentScope = NULL ;
public:
    SymbolTable(long long);
    ~SymbolTable();

    ScopeTable* EnterScope();
    ScopeTable* ExitScope();
    void ExitAllScope();
    ScopeTable* getCurrentScope();
    bool Insert(string , string );
    bool Remove(string);
    SymbolInfo* LookUp(string);
    void PrintCurrent();
    void PrintAll();
};
SymbolTable::SymbolTable(ll num_buckets){
    this->num_buckets = num_buckets;
}
ScopeTable* SymbolTable::EnterScope(){
    this->id++;
    cout<<"\tScopeTable# "<<this->id<<" created\n";
    ScopeTable *temp = new ScopeTable(num_buckets,id,currentScope);
    currentScope = temp;
    return currentScope;
}
ScopeTable* SymbolTable::ExitScope(){
    if(currentScope->getParentScope() == NULL ){
        cout<<"\tScopeTable# 1 cannot be removed\n";
        return NULL ;
    }
    cout<<"\tScopeTable# "<<this->currentScope->get_id()<<" removed\n";
    currentScope = currentScope->getParentScope();
    return currentScope;
}
void SymbolTable::ExitAllScope(){

    while(currentScope!=NULL ){
        cout<<"\tScopeTable# "<<this->currentScope->get_id()<<" removed\n";
        currentScope = currentScope->getParentScope();
    }
    return ;
}
ScopeTable* SymbolTable::getCurrentScope(){
    return this->currentScope;
}
bool SymbolTable::Insert(string name, string type){
    if(currentScope == NULL ){
        cout<<"\tCreate ScopeTable First\n";
        return 0;
    }

    ScopeTable *temp = currentScope;
    return currentScope->Insert(name,type);
}
bool SymbolTable::Remove(string name){
    if(currentScope == NULL ){
        cout<<"\tNo Scope in SymbolTable\n";
        return 0;
    }

    ScopeTable *temp = currentScope;
    return currentScope->Delete(name);
}
SymbolInfo* SymbolTable::LookUp(string name){
    if(currentScope == NULL ){
        cout<<"\t'"<<name<<"' not found in any of the ScopeTables\n";
        return NULL ;
    }

    ScopeTable *temp = currentScope;

    while(temp!=NULL ){

        SymbolInfo *temp1 = temp->LookUp(name);

        if(temp1 != NULL )return temp1;

        temp = temp->getParentScope();
    }

    cout<<"\t'"<<name<<"' not found in any of the ScopeTables\n";
    return NULL ;
}
void SymbolTable::PrintCurrent(){
    if(currentScope == NULL ){
        cout<<"\tNothing for Print long\n";
        return;
    }

    currentScope->Print();
}
void SymbolTable::PrintAll (){
    if(currentScope == NULL ){
        cout<<"\tNothing for Print long\n";
        return;
    }

    ScopeTable *temp = currentScope;

    while(temp!=NULL ){
        temp->Print();
        temp = temp->getParentScope();
    }
}
SymbolTable::~SymbolTable(){
    delete currentScope;
}
