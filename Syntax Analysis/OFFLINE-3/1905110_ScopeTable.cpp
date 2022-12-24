class ScopeTable
{
private:

    ll  num_buckets ;
    ll  id;
    SymbolInfo **symbolArray ;
    ScopeTable *parent_scope;
    ll SDBMHash(string str);

public:
    ScopeTable(ll num_buckets ,ll id,  ScopeTable *parent_scope);
    bool Insert(string ,string,ofstream&);
    SymbolInfo* LookUp(string);
    bool Delete(string);
    void Print(ofstream& logout);
    ll get_id(){
        return this->id;
    }
    ll get_numbucket(){
        return this->num_buckets;
    }
    ScopeTable* getParentScope();

    ~ScopeTable();
};
 ll ScopeTable::SDBMHash(string str){

         ll hash = 0;
         ll i = 0;
         ll len = str.length();

        for (i = 0; i < len; i++)
        {
            hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
        }

        return hash%(this->num_buckets);
    }
ScopeTable::ScopeTable(ll num_buckets ,ll id, ScopeTable* parent_scope){

    this->num_buckets = num_buckets;
    this->id = id;
    symbolArray = new SymbolInfo*[num_buckets];

    for(ll i=0;i<(this->num_buckets);i++){
        symbolArray[i] = NULL ;
    }
    this->parent_scope = parent_scope;
}
bool ScopeTable::Insert(string name,string type,ofstream& logout){

    ll hash_value = SDBMHash(name);

    SymbolInfo *temp = symbolArray[hash_value];
    SymbolInfo *newSymbol=NULL ;

    if(temp == NULL ){
        newSymbol = NULL ;
    }

    else{
        while(temp!=NULL ){

            if(temp->get_name() == name){
                newSymbol = temp;
                break;
            }
            temp = temp->get_next();
        }
    }



    if(newSymbol != NULL ){
         logout<<"\t"<<name<<" already exisits in the current ScopeTable\n";
         return 0;
    }
    else{

         ll count = 0;
         ll hash_value = SDBMHash(name),check = 0;

         SymbolInfo *temp = new SymbolInfo(name,type);

         if(symbolArray[hash_value]==NULL ){
             symbolArray[hash_value] = temp;
         }
         else{
            SymbolInfo *temp1 = symbolArray[hash_value];

            while(temp1->get_next()!=NULL  ){

                temp1 = temp1->get_next();
                count++;
            }
             temp1->set_next(temp);
             count++;
         }
         //cout<<"\tInserted in ScopeTable# "<<this->get_id()<<" at position "<<hash_value+1<<", "<<count+1<<'\n';
         return 1;
    }
}
SymbolInfo* ScopeTable::LookUp(string name){

    ll count = 0;
    ll hash_value = SDBMHash(name);

    SymbolInfo *temp = this->symbolArray[hash_value];

    if(temp == NULL ){
        return NULL ;
    }

    while(temp!=NULL ){

        // if(temp->get_name() == name){
        //     cout<<"\t'"<<name<<"' found in ScopeTable# "<<this->get_id()<<" at position "<<hash_value+1<<", "<<count+1<<"\n";
        //     return temp;
        // }
        count++;
        temp = temp->get_next();
    }

    return NULL ;

}
bool ScopeTable::Delete(string name){
    SymbolInfo *temp = new SymbolInfo(), *temp1 = new SymbolInfo();
    ll check = 0,count = 0;

    for(ll i=0 ; i< this->num_buckets ; i++){

        temp = symbolArray[i];

        if(temp == NULL )continue;


        temp1 = temp;
        count = 0;

        count = 2;
        if(temp->get_name()==name){

            symbolArray[i] = NULL ;
            cout<<"\tDeleted '"<<name<<"' from ScopeTable# "<<this->get_id()<<" at position "<<i+1<<", 1"<<"\n";
            return 1;
        }

        while(temp!=NULL ){


            if(temp->get_name() == name){


                temp1->set_next(temp->get_next());


                cout<<"\tDeleted '"<<name<<"' from ScopeTable# "<<this-id<<" at position "<<i+1<<", "<<count<<"\n";
                return 1;

            }
            temp1 = temp;
            temp = temp1->get_next();
            count++;
        }
        if(check){
            break;
        }

    }

    cout<<"\tNot found in the current ScopeTable\n";

    return 0;

}
ScopeTable* ScopeTable::getParentScope(){
    return this->parent_scope;
}
void ScopeTable::Print(ofstream & logout){
    SymbolInfo *temp =NULL ;

    

    logout<<"\tScopeTable# "<<this->get_id()<<'\n';

    for(ll i=0; i < this->num_buckets ; i++ ){
        temp = symbolArray[i];
        ll check = 0;
        if(temp!=NULL){
            logout<<"\t"<<i+1<<"--> ";
            check = 1;
        }
        while(temp!=NULL ){

            logout<<"<"<<temp->get_name()<<","<<temp->get_type()<<"> ";

            temp = temp->get_next();
        }
        if(check){
            logout<<'\n';
        }
        
    }
   
}
ScopeTable::~ScopeTable(){
    for(ll i = 0; i<num_buckets;i++){
        delete[] symbolArray[i];
    }
    delete[] symbolArray;
}

