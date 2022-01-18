#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxN = 1001;
vector<vector<int>>roads(maxN);
bool visit[maxN];
int lost;
int cnt;
void dfs(int beg){
    if(visit[beg]) return;
    visit[beg] = true;
    for(int i=0;i<roads[beg].size();i++)
        dfs(roads[beg][i]);
    return;
}
int main(){
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;i++){
        int c1,c2; scanf("%d%d",&c1,&c2);
        roads[c1].push_back(c2);
        roads[c2].push_back(c1);
    }
    for(int i=0;i<K;i++){
        memset(visit,0,sizeof(visit));
        cnt = 0;
        scanf("%d",&lost);
        visit[lost] = true;
        for(int i=1;i<=N;i++){
        	if(visit[i]==false)	cnt ++;
        	dfs(i);
		} 
        printf("%d\n",cnt-1);
    }


}
