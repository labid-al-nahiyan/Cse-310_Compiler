#include<bits/stdc++.h>
#include "1905110_SymbolInfo.cpp"
#include "1905110_ScopeTable.cpp"
#include "1905110_SymbolTable.cpp"

using namespace std;
typedef long long ll ;


int main()
{

    freopen("sample_input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll num_buckets;
    string num;
    getline(cin,num);

    num_buckets = stoi(num);
    SymbolTable *syt = new SymbolTable(num_buckets);
    ScopeTable *st = syt->EnterScope();

    string str;

    ll cmd = 1;

    while(1){
        cout<<"Cmd "<<cmd<<": ";
        getline(cin,str);
        cout<<str<<'\n';
        cmd++;

        string sbstr[10];

        for(int i=0;i<10;i++){
            sbstr[i] = " ";
        }

        int i=0,j=0;
        string temp="";
        while(str[i]!='\0'){
            if(str[i]!=' '){
                temp+=str[i];
            }
            else{
                sbstr[j] = temp;
                temp="";
                j++;
            }
            i++;
        }
        sbstr[j] = temp;




        string ch = sbstr[0];


            if( ch=="I"){

                if(sbstr[3]!=" " || sbstr[2]==" " ){
                    cout<<"\tNumber of parameters mismatch for the command I\n";
                    continue;
                }

                string name = sbstr[1], type = sbstr[2];
                syt->Insert(name,type);

            }
            else if(ch == "L"){
                if(sbstr[2]!=" " || sbstr[1]==" " ){
                    cout<<"\tNumber of parameters mismatch for the command L\n";
                    continue;
                }

                string name = sbstr[1];
                syt->LookUp(name);
            }

            else if(ch=="P"){
                if(sbstr[2]!=" " || sbstr[1]==" " ){
                    cout<<"\tNumber of parameters mismatch for the  command D\n";
                }
                else if(sbstr[1]=="C"){
                    syt->PrintCurrent();
                }
                else if(sbstr[1]=="A"){
                    syt->PrintAll();
                }
            }

            else if(ch =="D"){
                if(sbstr[2]!=" " || sbstr[1]==" " )
                {
                    cout<<"\tNumber of parameters mismatch for the  command D\n";
                    continue;
                }
                string name = sbstr[1];
                syt->Remove(name);


            }
            else if(ch=="S"){
                if(sbstr[1]!=" ")
                {
                    cout<<"\tNumber of parameters mismatch for the command S\n";
                    continue;
                }
                st =  syt->EnterScope();
            }

            else if(ch=="E")
                st = syt->ExitScope();

            else if(ch=="Q"){
                syt->ExitAllScope();
                break;
            }
        }



}





