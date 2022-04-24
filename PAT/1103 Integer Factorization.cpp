#include <bits/stdc++.h>
using namespace std;
vector<int>path,ans;
int facSumMax = 0;
//violent deep search
void prtPath(vector<int>&vec){
    cout<<"path: ";
    for(auto it=vec.begin();it!=vec.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
void dfs(int ele,int reSum,int reNum,int facSum,int tar,int P){
    if((reSum==0)&&(reNum==0)){
        if(facSum>facSumMax){
            facSumMax = facSum;
            ans = path;
        }
//        prtPath(path);
        return;
    }
    if(reSum<=0 || reNum<=0) return;
    if(ele==0) return;
    int tempVal  = pow(ele,P);
    if(reSum>=tempVal){
        path.push_back(ele);
        dfs(ele,reSum-tempVal,reNum-1,facSum+ele,tar,P);   //take element[ele]
        path.pop_back();
    }
    dfs(ele-1,reSum,reNum,facSum,tar,P);
    return;
}
int main(){
    int N,K,P; scanf("%d%d%d",&N,&K,&P);
    int beg = 21;
    while(pow(beg,P)>N) beg--;
    dfs(beg,N,K,0,N,P);
    if(ans.size()==0){
        printf("Impossible\n");
        return 0;
    }
    printf("%d =",N);
    for(auto it = ans.begin();it!=ans.end();it++)
        printf(" %d^%d%s",*it,P,(it!=ans.end()-1?" +":""));
    return 0;
}
