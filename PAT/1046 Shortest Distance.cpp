#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
int dis[maxN];
int main(){
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&dis[i]);
    int totDis = accumulate(dis+1,dis+N+1,0);
    int M; scanf("%d",&M);
    for(int i=0;i<M;i++){
        int st,des; scanf("%d%d",&st,&des);
        int init = 0;
        int dis1 = accumulate(dis+min(st,des),dis+max(st,des),0);
        cout<<min(dis1,totDis-dis1)<<endl;
    }
    return 0;
}
