#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int dfs(vector<vector<int>> &vec,int cnt[],int node,int level){
    if(vec[node].size()==0){
        cnt[level] ++;
        return level;
    }
    int maxLev = 1;
    for(int i=0;i<vec[node].size();i++){
        int deep = dfs(vec,cnt,vec[node][i],level+1);
        maxLev = max(maxLev,deep);
    }
    return maxLev;
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    vector<vector<int>>vec(N+1);
    for(int i=0;i<M;i++){
        int id,K,C; scanf("%d%d",&id,&K);
        while(K--){
            scanf("%d",&C);
            vec[id].push_back(C);
        }
    }
    int cnt[N+1] = {0};
    int deep = dfs(vec,cnt,1,1);
    for(int i=1;i<=deep;i++)
        printf("%s%d",i==1?"":" ",cnt[i]);
    return 0;
}
