#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int bfs(vector<vector<int>>&graph,int beg,int N,int L){
    queue<pair<int,int>>que;
    bool visit[N] ={0};
    memset(visit,0,sizeof(visit));
    que.push(make_pair(beg,0));
    visit[beg] = true;  int ans = -1;
    while(que.size() && que.front().second<=L){
        int front = que.front().first;
        for(int i=0;i<graph[front].size();i++)
            if(!visit[graph[front][i]]) {
                que.push(make_pair(graph[front][i],que.front().second+1));
                visit[graph[front][i]] = true;
            }
        que.pop(); ans ++;
    }
    return ans;
}
int main(){
    int N,L; scanf("%d%d",&N,&L);
    vector<vector<int>>graph(N);
    for(int i=0;i<N;i++){
        int num; scanf("%d",&num);
        int source;
        for(int j=0;j<num;j++){
           scanf("%d",&source);
           graph[source-1].push_back(i);
        }
    }
    int K; scanf("%d",&K);
    while(K--){
        int beg; scanf("%d",&beg);
        int cnt = bfs(graph,beg-1,N,L);
        printf("%d\n",cnt);
    }
    return 0;
}
