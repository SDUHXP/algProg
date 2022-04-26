#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>desLst;
int maxLevel,maxCnt;
void dfs(int cur,int Lev){
    if(desLst[cur].size()==0){
        if(Lev>maxLevel){maxLevel = Lev;maxCnt = 1;}
        else if(Lev==maxLevel) maxCnt++;
        return;
    };
    for(int i=0;i<desLst[cur].size();i++)
        dfs(desLst[cur][i],Lev+1);
    return ;
}
int main(){
    int N,anc,root; double P,R;
    scanf("%d%lf%lf",&N,&P,&R);
    desLst.resize(N);
    for(int i=0;i<N;i++){
        scanf("%d",&anc);
        if(anc==-1) {root = i;continue;}
        desLst[anc].push_back(i);
    }
    dfs(root,0);
    printf("%.2lf %d\n",P*pow(1+R/100,maxLevel),maxCnt);
}
