#include <bits/stdc++.h>
using namespace std;
string getCom(string str1,string str2){
    string str = "";
    int id = 0;
    while(id<str1.size()&&id<str2.size()){
        if(str1[id]!=str2[id]) break;
        id ++;
    }
    return str1.substr(0,id);
}
int main(){
    int N; scanf("%d%*c",&N);     //%*c means ignore one ending character '\n'
    string comStr;
    for(int i=0;i<N;i++){
        string str;  getline(cin,str);
        reverse(str.begin(),str.end());
        if(i==0) comStr = str;
        else comStr = getCom(comStr,str);
    }
    reverse(comStr.begin(),comStr.end());
    if(comStr.size()==0) cout<<"nai"<<endl;
    else cout<<comStr<<endl;
    return 0;
}
