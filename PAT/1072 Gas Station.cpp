//gcc using round half to even;
//VC++ round half away from zero
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN = 1015;
int graph[maxN][maxN];
vector<vector<int>>adjList;
bool visit[maxN];
int dis[maxN];          //dis[i] distance from begin to i
const int inf = 0x3fffffff;
void dijkstra(int source,int N,int M,int D,int& minDis,int& totalDis){
    int num = N+M;
    fill(dis,dis+maxN,inf);
    dis[source] = 0; int trans;
    for(int i=1;i<=num;i++){
        trans = 0;
        for(int j=1;j<=num;j++)
            if(!visit[j] && dis[j]<dis[trans]) trans = j;
        if(trans<=N && dis[trans]>D) return;
        visit[trans] = true;
        for(int j=0;j<adjList[trans].size();j++){
            int tar = adjList[trans][j];
            if(!visit[tar] &&  dis[tar]>dis[trans]+graph[trans][tar])
                dis[tar] = dis[trans] + graph[trans][tar];
        }
    }
    for(int i=1;i<=N;i++){
          totalDis += dis[i];
          if(dis[i]<minDis) minDis = dis[i];
    }
    return;
}

int main(){
    int N,M,K,D; scanf("%d%d%d%d",&N,&M,&K,&D);
    adjList.resize(N+M+1);
    for(int i=0;i<K;i++){
        char P1[5],P2[5];
        int st,des,dis; cin>>P1>>P2>>dis;
        if(P1[0]=='G') st = N + atoi(P1+1);
        else st = atoi(P1);
        if(P2[0]=='G') des = N + atoi(P2+1);
        else des = atoi(P2);
        graph[st][des] = graph[des][st] = dis;
        adjList[st].push_back(des);
        adjList[des].push_back(st);

    }
    int minAns=0, totalAns; int ans = -1;
    for(int i=1;i<=M;i++){
        memset(visit,0,sizeof(visit));
        int minDis = inf; int totalDis = 0;
        dijkstra(N+i,N,M,D,minDis,totalDis);
        if(minDis>D) continue;
        if(minDis>minAns || (minDis==minAns && totalDis<totalAns)){
            ans = i; minAns = minDis; totalAns = totalDis;
        }
    }
    if(ans<0) printf("No Solution\n");
    else printf("G%d\n%.1f %.1f\n",ans,minAns*1.0,(1.0*totalAns/N));
    return 0;

}
