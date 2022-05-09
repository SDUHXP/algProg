#include <bits/stdc++.h>
using namespace std;
map<int,set<int>>sets;
set<int>resSet;
int main(){
    int N,val; scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int M; scanf("%d",&M);
        for(int j=0;j<M;j++){
            scanf("%d",&val);
            sets[i].insert(val);
        }
    }
    int K; scanf("%d",&K);
    while(K--){
        int id1,id2; scanf("%d%d",&id1,&id2);
        resSet.clear();
        set_union(sets[id1].begin(),sets[id1].end(),sets[id2].begin(),sets[id2].end(),
                    inserter(resSet,resSet.begin()));
        int cnt1 = sets[id1].size();
        int cnt2 = sets[id2].size();
        int cnt = resSet.size();
        printf("%.1f%\n",(cnt1+cnt2-cnt)*100.0/cnt);
    }
    return 0;
}
