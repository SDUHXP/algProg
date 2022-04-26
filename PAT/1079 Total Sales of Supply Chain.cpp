#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adjLst;
map<int,int>saleMap;
double dfs(int cur,double P,double R){
    if(adjLst[cur].size()==0) return saleMap[cur]*P;
    double total = 0;
    for(int i=0;i<adjLst[cur].size();i++)
        total += dfs(adjLst[cur][i],P*R,R);
    return total;
}
int main(){
    int N; double P,R;
    scanf("%d%lf%lf",&N,&P,&R);
    adjLst.resize(N);
    for(int i=0;i<N;i++){
        int K,val; scanf("%d",&K);
        for(int j=0;j<K;j++){
            scanf("%d",&val);
            adjLst[i].push_back(val);
        }
        if(K==0){
            scanf("%d",&val);
            saleMap[i] = val;
        }
    }
    bool visit[N] = {0};
    double total = dfs(0,P,1+R/100);
    printf("%.1lf\n",total);
}
