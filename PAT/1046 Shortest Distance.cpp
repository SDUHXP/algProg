#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
int gap[maxN],dis[2*maxN];
int main(){
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++) {scanf("%d",&gap[i]); dis[i+1] = dis[i] + gap[i]; }
    int M; scanf("%d",&M);
    for(int i=0;i<M;i++){
        int st,des; scanf("%d%d",&st,&des);
        if(st>des) swap(st,des);
        int dis1 = dis[des]-dis[st];
        cout<<min(dis1,dis[N+1]-dis1)<<endl;
    }
    return 0;
}
