#include <cstdio>
#include <queue>
using namespace std;
const int maxK = 1001;
const int maxN = 22;
int proTime[maxK];
int finTime[maxK];
queue<int>Win[maxN];
int findShort(int N){
    int id = 0;
    for(int i=0;i<N;i++)
        if(Win[i].size()<Win[id].size()) id = i;
    return id;
}
int main(){
    int N,M,K,Q;
    scanf("%d%d%d%d",&N,&M,&K,&Q);
    for(int i=1;i<=K;i++)  scanf("%d",&proTime[i]);
    int t = 0;
    int outId = 1;
    while(t<9*60){
        //iterate all N window
        for(int w=0;w<N;w++)
            if(Win[w].size() && Win[w].front()==t)  Win[w].pop();

        if(outId>K) break;   //all custom has been servered
        while(outId<=K){
            int w = findShort(N);
            if(Win[w].size()==M ) break;
            {
                if(Win[w].size()==0) finTime[outId] = proTime[outId];
                else  finTime[outId] = Win[w].back()+ proTime[outId];
                Win[w].push(finTime[outId]);
            }
            outId ++;
        }
        t++;
    }
    while(Q--){
        int id; scanf("%d",&id);
        if(finTime[id]>0 && finTime[id]-proTime[id]<9*60 )  printf("%02d:%02d\n",finTime[id]/60+8,finTime[id]%60);
        else printf("Sorry\n");
    }
}
