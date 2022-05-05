#include <bits/stdc++.h>
using namespace std;
vector<string>input;
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
        string str; cin>>str;
        input.push_back(str);
    }
    sort(input.begin(),input.end(),[](string&a,string &b){return a+b<b+a;});

    for(int i=0;i<N;i++)
        if(i==0) cout<<stoi(input[i]);
        else cout<<input[i];
    cout<<endl;
}
