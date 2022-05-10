#include <bits/stdc++.h>
using namespace std;
string patten = "1l0O";
unordered_map<string,string>user;
bool modify(string& str){
    int pos = str.find_first_of(patten);   //mean didn't been modified
    if(pos==-1) return false;
    while(pos!=-1){
        if(str[pos]=='1') str[pos] = '@';
        else if(str[pos]=='0')  str[pos] = '%';
        else if(str[pos]=='l')  str[pos] = 'L';
        else str[pos] = 'o';
        pos = str.find_first_of(patten,pos);
    }
    return true;  //means has been modified;
}
int main(){
    int N; scanf("%d",&N);
    string account,password;
    for(int i=0;i<N;i++){
        cin>>account>>password;
        if(modify(password)==true){
            user[account] = password;
        }
    }
    if(user.size()==0){
        if(N==1) printf("There is 1 account and no account is modified\n");
        else printf("There are %d accounts and no account is modified\n",N);
    }
    else{
        cout<<user.size()<<endl;
        for(auto it=user.begin();it!=user.end();it++)
            cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
