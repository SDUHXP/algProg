//using bfs instead of dfs, since dfs may cause stack overflow
#include <bits/stdc++.h>
using namespace std;
int lDir[6] = {-1,1,0,0,0,0};
int mDir[6] = {0,0,-1,1,0,0};
int nDir[6] = {0,0,0,0,-1,1};
const int maxM = 1290;
const int maxN = 130;
const int maxL = 61;
bool img[maxL][maxM][maxN];
bool visit[maxL][maxM][maxN];
int totalVol,blockCnt;
struct pos{
    pos(int l,int m,int n):lPos(l),mPos(m),nPos(n){}
    int lPos,mPos,nPos;
};
queue<pos>posCache;
void bfs(int l,int m,int n){
    posCache.push(pos(l,m,n));
    visit[l][m][n] = true;
    while(posCache.size()){
        auto it = posCache.front();
        blockCnt ++;        for(int idx=0;idx<6;idx++){
            int newL = it.lPos + lDir[idx];
            int newM = it.mPos + mDir[idx];
            int newN = it.nPos + nDir[idx];
            if(newL<0||newM<0||newN<0) continue;
            if(visit[newL][newM][newN] || !img[newL][newM][newN]) continue;
            posCache.push(pos(newL,newM,newN));
            visit[newL][newM][newN] = true;
        }
        posCache.pop();
    }
    return;
}
int main(){
    int M,N,L,T;
    scanf("%d%d%d%d",&M,&N,&L,&T);
    for(int l=0;l<L;l++)
        for(int m=0;m<M;m++)
            for(int n=0;n<N;n++) scanf("%d",&img[l][m][n]);
    for(int l=0;l<L;l++)
        for(int m=0;m<M;m++)
            for(int n=0;n<N;n++){
                if(!visit[l][m][n] && img[l][m][n]){
                    blockCnt = 0;
                    bfs(l,m,n);
                    if(blockCnt>=T) totalVol += blockCnt;
                }
            }
    printf("%d\n",totalVol);
}
