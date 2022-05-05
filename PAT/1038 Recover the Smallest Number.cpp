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
    bool flag = true;   //be first
    for(int i=0;i<N;i++)
        if(flag==true){
            int tmp = stoi(input[i]);
            if(tmp){cout<<tmp; flag = false;}
        }
        else cout<<input[i];
    if(flag==true) cout<<"0";
    return 0;
}
