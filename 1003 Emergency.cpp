#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 510;
int inf = 0x3fffffff;
int cityMap[maxN][maxN];
int weight[maxN];
int main(){
    int N,M,C1,C2;
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0;i<N;i++) scanf("%d",&weight[i]);
    fill(cityMap[0],cityMap[0]+maxN*maxN,inf);
    for(int i=0;i<M;i++){
        int s,e,dis; scanf("%d%d%d",&s,&e,&dis);
        cityMap[s][e] = cityMap[e][s] = dis;
    }
    int dis[N]= {0}; //record the shortest distance from C1 to i;
    int score[N] = {0};   //the max men can be called from C1 to i;
    fill(dis,dis+N,inf);
    bool visit[N] = {false};
    score[C1] = weight[C1];
    dis[C1] = 0;
    int trans = C1;
    int cnt = 0;
    int repeat[N] = {0};
    repeat[C1] = 1;
    while(cnt != N){
        visit[trans] = true;
        int shortest = inf;
        if(trans==C2) break;
        int next = -1;
        for(int i=0;i<N;i++){
            if(!visit[i]){
                if(dis[trans]+cityMap[trans][i]<dis[i]){
                    dis[i] = dis[trans] + cityMap[trans][i];
                    score[i] = score[trans] + weight[i];
                    repeat[i] = repeat[trans];  //be careful about it
                }
                else if(dis[trans]+cityMap[trans][i]==dis[i]){
                    repeat[i] += repeat[trans];
                    if(score[i] <score[trans] + weight[i])
                            score[i] = score[trans] + weight[i];

                }
                if(dis[i]<shortest){
                    shortest = dis[i];
                    next = i;
                }
            }
        }
        cnt ++;
        trans = next;
    }
    printf("%d %d\n",repeat[C2],score[C2]);
    return 0;
}
