#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int maxN = 510;
const int inf  = 0x3fffffff;
int roads[maxN][maxN];
int station[maxN];
vector<int>preId[maxN];  //store all the possible predecessor of i;
vector<int>path,ans;
int dis[maxN];   //number of bikes carry to PBMC
bool visit[maxN];
int minSend,minTake;
//travels all possible path (has the minimum distance)
void travPath(int &send, int &take,int C){
    for(int i=path.size()-1;i>=0;i--){

         send = send + max(0,C/2-take-station[path[i]]);
         take = max(take+station[path[i]]-C/2,0);
    }
}
void dfs(int curSta,int C){
    if(curSta==0){
        int tempSend = 0;
        int tempTake = 0;
        travPath(tempSend,tempTake,C);
        if(tempSend<minSend||(tempSend==minSend && tempTake<minTake)){
            ans = path;
            minSend = tempSend;
            minTake = tempTake;
        }
        return ;
    }
    path.push_back(curSta);
    for(int i=0;i<preId[curSta].size();i++){
        dfs(preId[curSta][i],C);
    }
    path.pop_back();
}
int main(){
    int C,N,S,M;
    scanf("%d%d%d%d",&C,&N,&S,&M);
    for(int i=1;i<=N;i++)  scanf("%d",&station[i]);
    for(int i=0;i<M;i++){
        int s,t,d;
        scanf("%d%d%d",&s,&t,&d);
        roads[s][t] = roads[t][s] = d;
    }
    fill(dis,dis+maxN,inf);
    int curSta = 0;
    dis[curSta] = 0;
    //dijkstra algorithm to get the shortest path
    while(1){
        visit[curSta] = true;
        for(int i=1;i<=N;i++){
            if(visit[i]||roads[curSta][i]==0) continue;
            if(dis[curSta]+roads[curSta][i]<=dis[i]){
                if(dis[curSta]+roads[curSta][i]<dis[i]) preId[i].clear();
                preId[i].push_back(curSta);
                dis[i] = dis[curSta]+roads[curSta][i];
            }
        }
        //get the next target
        int next = N+1;
        for(int i=1;i<=N;i++)
            if(!visit[i] && dis[i]<dis[next]) next = i;
        if(next==N+1) break;
        curSta = next;
    }
    //dfs to calculate the best path;
    for(int i=1;i<=N;i++)
    minSend = minTake = inf;
    dfs(S,C);
    printf("%d 0",minSend);
    for(int i=ans.size()-1;i>=0;i--){
        printf("->%d",ans[i]);
    }
    printf(" %d",minTake);
}




#if 0
//this method ignore the fact: the path with minimal send and take number doesn't has the quality of best subsequence
//for example,using the following algorithm, programm whill get     5 0->5->4->1 0
// but the answer should be: 3 0->3->9->4->1 0
/*
     3
    *	*
PBMC	 9
    #     *
     5  *  4  * 1
*/
/*
test sample:

10 5 5 6
5 3 9 4 1
0 1 2
0 2 1
1 4 1
2 3 1
3 4 1
4 5 1

wrong answer: 5 0->1->4->5 0
correct answer 3 0->2->3->4->5 0
*/

#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int maxN = 510;
const int inf  = 0x3fffffff;
int roads[maxN][maxN];
int station[maxN],preId[maxN];
int dis[maxN],send[maxN],take[maxN];   //number of bikes carry to PBMC
bool visit[maxN];
int main(){
    int C,N,S,M;
    scanf("%d%d%d%d",&C,&N,&S,&M);
    for(int i=1;i<=N;i++)  scanf("%d",&station[i]);
    for(int i=0;i<M;i++){
        int s,t,d;
        scanf("%d%d%d",&s,&t,&d);
        roads[s][t] = roads[t][s] = d;
    }
    fill(dis,dis+maxN,inf);
    int curSta = 0;
    dis[curSta] = take[curSta] = send[curSta] = 0;
    while(1){
        visit[curSta] = true;
        //update distance from PBMC
        for(int i=1;i<=N;i++){
            if(visit[i]||roads[curSta][i]==0) continue;
            int tempSend = send[curSta] + max(0,C/2-take[curSta]-station[i]); //bike needed if transfer from curSta
            int tempTake = max(take[curSta]+station[i]-C/2,0);
            int tempDis = dis[curSta]+roads[curSta][i];
            if(tempDis<dis[i] || (dis[i]==tempDis&&(tempSend<send[i]||(tempSend==send[i] && tempTake<take[i])))){
                dis[i] = tempDis;
                send[i] = tempSend;
                take[i] = tempTake;
                preId[i] = curSta;
            }
        }
        //get the next target
        int next = N+1;
        for(int i=1;i<=N;i++)
            if(!visit[i] && dis[i]<dis[next]) next = i;
        if(next==N+1) break;
        curSta = next;
    }
    printf("%d 0",send[S]);
    stack<int>path;
    int id = S;
    while(id!=0){
        path.push(id);
        id = preId[id];
    }
    while(path.size()){
        printf("->%d",path.top());
        path.pop();
    }
    printf(" %d",take[S]);
}
#endif
