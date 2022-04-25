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
void bfs(int l,int m,int n){
    if(l<0||m<0||n<0) return;
    if(visit[l][m][n] || img[l][m][n]==false) return;
    visit[l][m][n] = true;
    blockCnt ++;
    for(int idx=0;idx<6;idx++){
        bfs(l+lDir[idx],m+mDir[idx],n+nDir[idx]);
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
