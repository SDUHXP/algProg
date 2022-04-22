#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxN = 1015;
int graph[maxN][maxN];
vector<vector<int>>adjList;
bool visit[maxN];
int dis[maxN];          //dis[i] distance from begin to i
const int inf = 0x3fffffff;
void dijkstra(int source,int num,float& minDis,float& avgDis){
    fill(dis,dis+maxN,inf);
    dis[source] = 0;
    int trans;
    //calculate distance from source  (N+M) times
    for(int i=0;i<num;i++){
        trans = 0;
        for(int j=1;j<=num;j++)
            if(!visit[i] && dis[j]<dis[trans]) trans = j;
        visit[trans] = true;
        for(int i=0;i<adjList[trans].size();i++){
            int tar = adjList[trans][i];
            if(dis[tar]>dis[trans]+graph[trans][tar]) dis[tar] = dis[trans] + graph[trans][tar];
        }
    }
    minDis = avgDis = 0;
    float total = 0;
    for(int i=1;i<=num;i++){
        total += dis[i];
        if(minDis<dis[i]) minDis = dis[i];
    }
    avgDis = total/(num-1);
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
    float minAns=0,avgAns; int ans = -1;
    for(int i=1;i<=M;i++){
        memset(visit,0,sizeof(visit));
        memset(dis,0,sizeof(dis));
        float minDis = 0, avgDis = 0;
        dijkstra(N+i,N+M,minDis,avgDis);
        if(minDis>D) continue;
        if(minDis>minAns){
            ans = i;
            minAns = minDis;
            avgAns = avgDis;
        }
    }
    if(ans<0) printf("No Solution\n");
    else printf("G%d\n%.1f %.1f\n",ans,minAns,avgAns);
    return 0;

}
