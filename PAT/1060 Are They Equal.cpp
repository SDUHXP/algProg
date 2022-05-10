#include <bits/stdc++.h>
using namespace std;
string cvtSci(string str,int N){
    int ptPos = str.find('.');
    string res = "0.";
    if(ptPos!=-1) str.erase(ptPos,1);
    else ptPos = str.length();
    int digPos = str.find_first_not_of('0');
    if(digPos!=-1) res += str.substr(digPos,N);
    else {
        res += str.substr(0,N);
        if(res.length()!=N+2) res.append(N+2-res.length(),'0');
        res += "*10^0";
        return res;
    }
    if(res.length()!=N+2) res.append(N+2-res.length(),'0');
    res += "*10^";
    res += to_string(ptPos-digPos);
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
