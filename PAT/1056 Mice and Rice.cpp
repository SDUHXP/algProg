#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
struct mouse{
    int rank;
    int wt;
}mice[maxN];
queue<int>plyQue;   //playing order of each round
int main(){
    int P,G; scanf("%d%d",&P,&G);
    for(int i=0;i<P;i++) scanf("%d",&mice[i].wt);
    for(int i=0;i<P;i++){
        int idx; scanf("%d",&idx);
        plyQue.push(idx);
    }
    while(plyQue.size()!=1){
        int group = plyQue.size()/G + (plyQue.size()%G>0);
        int plyNum = plyQue.size();
        for(int g=0;g<group;g++){
            int maxId = plyQue.front();
            for(int i=0;i<G && g*G+i<plyNum;i++){
                int id = plyQue.front();
                if(mice[id].wt>mice[maxId].wt) maxId = id;
                mice[id].rank = group + 1;
                plyQue.pop();
            }
            plyQue.push(maxId);
        }
    }
    mice[plyQue.front()].rank = 1;
    for(int i=0;i<P;i++) printf("%s%d",i==0?"":" ",mice[i].rank);

}
