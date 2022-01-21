#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 505;
const int inf = 0x3fffffff;
vector<vector<int>>road(maxN);
int wt[maxN][maxN],cost[maxN][maxN];
int dis[maxN],spend[maxN],pre[maxN];
bool visit[maxN];
int main ()
{
    int N,M,S,D; scanf("%d%d%d%d",&N,&M,&S,&D);
    for(int i=0;i<M;i++){
        int s,t,d,c; scanf("%d%d%d%d",&s,&t,&d,&c);
        road[s].push_back(t);
        road[t].push_back(s);
        wt[s][t] = wt[t][s] = d;
        cost[s][t] = cost[t][s] = c;
    }
    fill(dis,dis+maxN,inf);
    visit[S] = true;  dis[S] = 0; spend[S] = 0;
    int tran = S;
    while(tran!=D){
        for(int i=0;i<road[tran].size();i++){
            int dst = road[tran][i];
            if(!visit[dst]){
                if(dis[tran]+wt[tran][dst]<dis[dst]){
                    dis[dst] = dis[tran]+wt[tran][dst];
                    spend[dst] = spend[tran] + cost[tran][dst];
                    pre[dst] = tran;
                }
                else if(dis[tran]+wt[tran][dst]==dis[dst]  && spend[tran]+cost[tran][dst]<spend[dst]){
                    spend[dst] = spend[tran] + cost[tran][dst];
                    pre[dst] = tran;
                }
            }
        }
        tran = N;
        for(int i=0;i<N;i++)
            if(!visit[i] && dis[i]<dis[tran]) tran = i;
        visit[tran] = true;
    }
    tran = D; pre[S] = -1;
    int cnt =0;
    int res[N] = {0};
    do{
        res[cnt++] = tran;
        tran = pre[tran];
    }while(tran!=-1);
    for(int i=cnt-1;i>=0;i--) printf("%d ",res[i]);
    printf("%d %d\n",dis[D],spend[D]);
}
