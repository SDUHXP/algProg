#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxN = 10010;
vector<int>edge[maxN];
int cnt = 0;
bool visit[maxN];
void dfs(int cur){
    visit[cur] = true;
    for(int i=0;i<edge[cur].size();i++)
        if(!visit[edge[cur][i]])  dfs(edge[cur][i]);
    return;
}
int getH(int cur){
    memset(visit,0,sizeof(visit));
    queue<pair<int,int>>BFS;
    BFS.push(make_pair(cur,1));
    visit[cur] = true;
    int H =1;
    while(BFS.size()){
        int id = BFS.front().first;
        int deep = BFS.front().second;
        for(int i=0;i<edge[id].size();i++)
            if(!visit[edge[id][i]]){
                H = deep+1;
                BFS.push(make_pair(edge[id][i],H));
                visit[edge[id][i]] = true;
            }
        BFS.pop();
    }
    return H;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=1;i<N;i++){
        int s,t; scanf("%d%d",&s,&t);
        edge[s].push_back(t);
        edge[t].push_back(s);
    }
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=N;i++){
        if(visit[i]) continue;
        else cnt++;
        dfs(i);
    }
    if(cnt>1){
        printf("Error: %d components\n",cnt);
        return 0;
    }
    vector<int>ans;
    int maxH = 0;
    for(int i=1;i<=N;i++){
        int height = getH(i);
        if(height>=maxH){
            if(height>maxH) ans.clear();
            ans.push_back(i);
            maxH = height;
        }
    }
    for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
    return 0;
}
