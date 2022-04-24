#include <bits/stdc++.h>
using namespace std;
vector<int>path,ans;
int facSumMax = 0;
//force deep search
void dfs(int ele,int reSum,int reNum,int facSum,int K){
    if(!(reSum&&reNum) && (reSum||reNum)) return;
    if((reSum||reNum)==0){
        if(facSum>facSumMax){
            facSumMax = facSum;
            ans = path;
        }
        return;
    }
    if(reSum>=pow(ele,K)){
        path.push_back(ele);
        dfs(ele,reSum-pow(ele,K),reNum-1,facSum+ele,K);   //take element[ele]
        path.pop_back();
    }
    dfs(ele+1,reSum,reNum,facSum,K);
    return;
}
int main(){
    int N,K,P; scanf("%d%d%d",&N,&K,&P);
    dfs(1,N,K,0,K);
    if(ans.size()==0){
        printf("Impossible\n");
        return 0;
    }
    printf("%d = ",N);
    for(auto it = ans.rbegin();it!=ans.rend();it++)
        printf("%d^%d + ",*it,P);
    return 0;
}
