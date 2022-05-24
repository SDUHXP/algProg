#include <bits/stdc++.h>
using namespace std;
string calNext(string str){
    string strRes;
    for(int i=0;i<str.size();){
        char cur = str[i];
        int j=i; 
        while(j<str.size()&&str[j]==str[i]) j++;
        strRes += cur;
        strRes += to_string(j-i);
        i = j;
    }
    return strRes;
}
int main(){
    string str; int N;
    cin>>str>>N;
    for(int i=1;i<N;i++){
        str = calNext(str);
    }
    cout<<str<<endl;
}