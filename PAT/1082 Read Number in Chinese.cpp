#include <bits/stdc++.h>
using namespace std;
char dig[10][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wt[5][5] = {"","shi","bai","qian"};
char seg[3][5] = {"","Wan","Yi"};
string cvtHan(int val){
    string str = "";
    while(val){
        if(val>=1000) {str += dig[val/1000]; str += " qian ";}
        else if(val>=100) {  str += dig[val/100]; str += " bai ";}
        else if (val>=10) { str += dig[val/10]; str += " shi ";}
        else str += dig[val];
        val /= 10;
    }
    return str;
}
int main(){
    int N; scanf("%d",&N);
    string res = "";  int exp = 8;
    if(N<0){ res += "Fu ";N *= -1;}
    while(N!=0){
        if(N/pow(10,exp)){
            res += cvtHan(N/pow(10,exp));
            res += seg[exp/4];
            N /= pow(10,exp);
        }
        exp -= 4;
    }
    cout<<res<<endl;
    return 0;
}
