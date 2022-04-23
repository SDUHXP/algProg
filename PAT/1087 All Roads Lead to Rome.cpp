#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
map<string,int>idMap;
map<int,string>nameMap;
const int maxN = 210;
const int inf  = 0x3fffffff;
int happy[maxN],graph[maxN][maxN];
int cost[maxN],gain[maxN];
int deep[maxN],level[maxN];   //deep[i] stands for deepth from root, level stands for level for path
int pre[maxN];
int minCnt[maxN];
bool visit[maxN];
vector<int>path;
//function to calculate deepth for every node from root
void dfs(int st,int dest,int N){

}

void dijkstraDfs(int st,int dest,int N){
    fill(cost,cost+maxN,inf);
    memset(visit,0,sizeof(visit));
    memset(gain,0,sizeof(gain));
    memset(level,0,sizeof(gain));
    cost[st] = 0;
    int trans = 0;
    //memcpy(level,deep,sizeof(level));   //level and deepth be same
    level[st] = 0;
    for(int i=1;i<=N;i++){
        //get the minimum cost city
        for(int j=1;j<=N;j++){
            if(!visit[i] && cost[i]<cost[trans]) trans = i;
        }
        visit[trans] = true;
        for(int j=1;j<=N;j++){
            int tempCost = cost[trans]+graph[trans][j];
            int tempGain = gain[j]>gain[trans]+happy[j];
            if(tempCost<cost[j]){
                minCnt[j] = 0;
                cost[j] = cost[trans] + graph[trans][j];
                pre[j] = trans;
                gain[j] = gain[tran] + happy[j];
                level[j] = level[trans] + 1;
            }
            else if (cost[j]==tempCost ){
                minCnt[j] ++;
                if(gain[j]>tempGain){
                    pre[j] = trans;
                    gain[j] = gain[tran] + happy[j];
                    level[j] = level[trans] + 1;
                }
                else if (gain[j]==tempGain && level[j]>level[tran]+1){
                pre[j] = trans;
                level[j] = level[trans] + 1;
                }
            }
        }
    }
}
int main(){
    int N,K; string city;
    cin>>N>>K>>city;
    int id = 1;
    idMap[city] = id++;
    for(int i=1;i<N;i++){
        cin>>city;
        cin>>happy[idMap[city]];
    }
    for(int i=0;i<K;i++){
        string desCity; int dis;
        cin>>city>>desCity>>dis;
        graph[idMap[city]][idMap[desCity]] = dis;
        graph[idMap[desCity]][idMap[city]] = dis;
    }
    dijkstraDfs(1,idMap["ROM"],N);
    for(auto it=idMap.begin();it!=idMap.end();it++)
        nameMap[it->second] = it->first;

    int cur = idMap["ROM"];
    while(pre[cur]!=1){
        path.push_back(cur);
        cur = pre[cur];
    }
    cout<<city;
    for(auto it=path.rbegin();it!=path.rend();it++)
        cout<<"->"<<nameMap[*it];
}
