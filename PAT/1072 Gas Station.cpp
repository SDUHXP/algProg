#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN = 1015;
int graph[maxN][maxN];
int minDis,int avgDis;
vector<vector<int>>adjacencyList;
bool visit[maxN];
int dis[maxN];          //dis[i] distance from begin to i
const int inf = 0x3fffffff;
void dijkstra(int source,int num){
    fill(dis,dis+maxN,inf);
    dis[source] = 0;
    int trans;
    //calculate distance from source  (N+M) times
    for(int i=0;i<num;i++){
        trans = 0;
        for(int j=1;j<=num;j++)
            if(!visit[i] && dis[j]<dis[trans]) trans = j;
        for(int i=0;i<adjacencyList[trans].size();i++){
            int tar = adjacencyList[trans][i];
            if(dis[tar]>dis[trans]+graph[trans][tar]) dis[tar] = dis[tran] + graph[trans][tar];
        }
    }
    return;
}
void getDis(float &minDis,float& avgDis){

    return ;
}
int main(){
    int N,M,K,D; scanf("%d%d%d%d",&N,&M,&K,&D);
    adjacencyList.resize(N+M+1);
    for(int i=0;i<K;i++){
        char P1[5],P2[5];
        int st,des,dis; cin>>P1>>P2>>dis;
        if(P1[0]=='G') st = N + atoi(P1+1);
        else beg = atoi(P1);
        if(P2[0]=='G') des = N + atoi(P2+1);
        else des = atoi(P2);
        graph[st][des] = graph[des][st] = dis;
        adjacencyList[st].push_back(des);
        adjacencyList[des].push_back(st);

    }
    float minAns = -1;
    float avgAns = -1;
    int ans = -1;
    for(int i=1;i<=M;i++){
        memset(visit,0,sizeof(visit));
        memset(dis,0,sizeof(dis));
        dijkstra(N+i,N+M);
        float minDis = 0, avgDis = 0;
        getDis(minDis,avgDis);
        if(minDis>D) continue;
        if(minDis<minAns){
            ans = N + i;
            minAns = minDis;
            avgAns = avgDis;
        }
    }
    if(minAns<0) printf("No Solution\n");
    else printf("G%d\n%.1f %.1f\n",ans-N,minAns,avgAns);
    return 0;

}
