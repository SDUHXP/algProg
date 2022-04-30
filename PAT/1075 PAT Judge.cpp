#include <bits/stdc++.h>
using namespace std;
const int maxN = 10005;
struct user{
    int id;
    int score[6];
    int totScore,passNum;
    bool visible;
    bool operator<(const user&oth){
        if(totScore!=oth.totScore) return totScore>oth.totScore;
        else if(passNum!=oth.passNum) return passNum>oth.passNum;
        else return id<oth.id;
    }
    user(){
        for(int i=0;i<6;i++)  score[i] = -2;
        visible = false;
        totScore = -1;
        passNum = 0;
    }
}rcds[maxN];
int fullScore[6];
int main(){
    int N,K,M;  scanf("%d%d%d",&N,&K,&M);
    for(int i=1;i<=K;i++)  scanf("%d",&fullScore[i]);
    for(int i=0;i<M;i++){
        int uId,pId,pS; scanf("%d%d%d",&uId,&pId,&pS);
        if(fullScore[pId]==pS && rcds[uId].score[pId]!=pS) rcds[uId].passNum ++;
        rcds[uId].score[pId] = max(pS,rcds[uId].score[pId]);
    }
    for(int i=0;i<N;i++)
        for(int k=0;i<K;k++) if(rcds[i].score[k]>=0) rcds[i].totScore =max(rcds[i].totScore,0)+rcds[i].score[k];
    sort(rcds,rcds+N);
    int rank = -1,preScore= -1;
    for(int i=0;i<N;i++){
        if(rcds[i].totScore<0) break;
        if(rcds[i].totScore!=preScore)  rank = i+1;
        printf("%d %05d\n",rank,rcds[i].id);
        for(int k=1;i<=K;k++)
            if(rcds[i].score[k]!=-1) printf(" %d",rcds[i].score[k]);
            else printf(" -");
        preScore = rcds[i].totScore;
    }
    return 0;
}
