#include <bits/stdc++.h>
using namespace std;
map<string,int>idMap;
map<int,string>nameMap;
const int maxN = 210;
const int inf  = 0x3fffffff;
int happy[maxN],graph[maxN][maxN];
int cost[maxN],gain[maxN],level[maxN];   //deep[i] stands for deepth from root, level stands for level for path
int pre[maxN], minCnt[maxN];
bool visit[maxN];
vector<int>path;
void dijkstraDfs(int st,int dest,int N){
    fill(cost,cost+maxN,inf);
    cost[st] = 0;   int trans = 0;   level[st] = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!visit[j] && cost[j]<cost[trans]) trans = j;
        }
        visit[trans] = true;
        for(int j=1;j<=N;j++){
            int tempCost = cost[trans]+graph[trans][j];
            int tempGain = gain[trans]+happy[j];
            if(tempCost<cost[j]){
                minCnt[j] = 1;
                cost[j] = tempCost;
                pre[j] = trans;
                gain[j] = tempGain;
                level[j] = level[trans] + 1;
            }
            else if (cost[j]==tempCost ){
                minCnt[j] ++;
                if(tempGain>gain[j]){
                    pre[j] = trans;
                    gain[j] = tempGain;
                    level[j] = level[trans] + 1;
                }
                else if (gain[j]==tempGain && level[j]>level[trans]+1){
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
    int id = 0; idMap[city] = ++id;
    for(int i=1;i<N;i++){
        cin>>city; idMap[city] = ++id;
        cin>>happy[id];
    }
    for(int i=0;i<K;i++){
        string desCity; int dis;
        cin>>city>>desCity>>dis;
        graph[idMap[city]][idMap[desCity]] = dis;
        graph[idMap[desCity]][idMap[city]] = dis;
    }
    int dest = idMap["ROM"];
    dijkstraDfs(1,dest,N);
    for(auto it=idMap.begin();it!=idMap.end();it++)
        nameMap[it->second] = it->first;

    int cur = dest;
    while(pre[cur]!=1){
        path.push_back(cur);
        cur = pre[cur];
    }
    cout<<minCnt[dest]<<" "<<cost[dest]<<" "<<gain[dest]<<" "<<gain[dest]/level[dest]<<endl;
    cout<<nameMap[1];
    for(auto it=path.rbegin();it!=path.rend();it++)
        cout<<"->"<<nameMap[*it];
}
