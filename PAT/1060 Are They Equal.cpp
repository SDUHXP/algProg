#include <bits/stdc++.h>
using namespace std;
string cvtSci(string str,int N){
    int pos = str.find('.');
    int len = str.length();
    string res = "0.";
    if(pos!=-1){
        str.erase(pos);

    }
    res += str.substr(0,N);
    res += "*10^";
    res += to_string(pos==-1?len:min(pos,len));
    return res;
}

int main(){
    int N; string str1,str2;
    cin>>N>>str1>>str2;

    string strRes1 = cvtSci(str1,N);
    string strRes2 = cvtSci(str2,N);

    if(strRes1==strRes2){
        cout<<"YES ";
        cout<<strRes1<<endl;
    }
    else {
        cout<<"NO ";
        cout<<strRes1<<" "<<strRes2<<endl;
    }



    return 0;
}
