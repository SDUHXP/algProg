#include <bits/stdc++.h>
using namespace std;
char dig[10][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wt[5][10] = {""," Shi "," Bai "," Qian "};
char seg[3][10] = {""," Wan "," Yi "};
string cvtHan(int val){
    string str = "";
    int exp = 3;
    while(val && exp>=0){
        int weight = pow(10,exp);
        if(val>=weight) {str += dig[val/weight]; str +=  wt[exp]; }
        val %= weight;  exp --;
    }
    return str;
}
int main(){
    int N; scanf("%d",&N);
    string res = "";  int exp = 8;
    if(N<0){ res += "Fu "; N *= -1;}
    while(N!=0){
        int mod = pow(10,exp);
        if(N/mod){
            res += cvtHan(N/mod);
            res += seg[exp/4];
            N %= mod;
        }
        exp -= 4;
    }
    cout<<res<<endl;
    return 0;
}
