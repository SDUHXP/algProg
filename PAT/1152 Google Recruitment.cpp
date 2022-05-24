#include <bits/stdc++.h>
using namespace std;
bool isPrime(int val){
    if(val<2||(val>2&&val%2==0)) return false;
    for(int i=3;i*i<=val;i+=2)
        if(val%i==0) return false;
    return true;
}
int main(){
    int L,K; scanf("%d%d",&L,&K);
    string str; cin>>str;
    for(int i=0;i<=L-K;i++){
        int val = stoi(str.substr(i,K));
        if(isPrime(val)==true){
            printf("%s",str.substr(i,K).c_str());
            return 0;
        }
    }
    printf("404");
    return 0;
}