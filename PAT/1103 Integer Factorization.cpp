#include <bits/stdc++.h>
using namespace std;
vector<int>path,ans;
int facSumMax = 0;
//force deep search
void dfs(int ele,int reSum,int reNum,int facSum,int tar,int P){

    if(!(reSum&&reNum) && (reSum||reNum)) return;
    if((reSum||reNum)==0){
        if(facSum>facSumMax){
            facSumMax = facSum;
            ans = path;
        }
        return;
    }
    int tempVal  = pow(ele,P);
    if(tempVal>tar) return;
    if(reSum>=tempVal){
        path.push_back(ele);
        dfs(ele,reSum-tempVal,reNum-1,facSum+ele,tar,P);   //take element[ele]
        path.pop_back();
    }
    dfs(ele+1,reSum,reNum,facSum,tar,P);
    return;
}
int main(){
    int N,K,P; scanf("%d%d%d",&N,&K,&P);
    dfs(1,N,K,0,N,P);
    if(ans.size()==0){
        printf("Impossible\n");
        return 0;
    }
    printf("%d =",N);
    for(auto it = ans.rbegin();it!=ans.rend();it++)
        printf(" %d^%d%s",*it,P,(it!=ans.rend()-1?" +":""));
    return 0;
}
