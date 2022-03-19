#include <cstdio>
#include <algorithm>
using namespace std;
const int maxT = 110*300;
struct testee{
    long long id;
    int localId;
    int score;
    int localR;
}tst[maxT];
int main(){
    int N; scanf("%d",&N);
    int cnt = 0;
    for(int i=1;i<=N;i++){
        int n; scanf("%d",&n);
        for(int j=0;j<n;j++) scanf("%lld%d",&tst[cnt+j].id,&tst[cnt+j].score);
        sort(tst+cnt,tst+cnt+n,[](testee &a,testee &b){return a.score==b.score?a.id<b.id:a.score>b.score;});
        int preS = -1;
        for(int j=0;j<n;j++){
            if(tst[cnt+j].score==preS)    tst[cnt+j].localR = tst[cnt+j-1].localR;
            else{
              tst[cnt+j].localR = j+1;
              preS = tst[cnt+j].score;
            }
            tst[cnt+j].localId = i;
        }
        cnt += n;
    }
    sort(tst,tst+cnt,[](testee &a,testee &b){return a.score==b.score?a.id<b.id:a.score>b.score;});
    int preS = -1;
    int preR = -1;
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        if(tst[i].score==preS) printf("%013lld %d %d %d\n",tst[i].id,preR,tst[i].localId,tst[i].localR);
        else{
            printf("%013lld %d %d %d\n",tst[i].id,i+1,tst[i].localId,tst[i].localR);
            preS = tst[i].score;
            preR = i+1;
        }
    }
    return 0;
}
