#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,D; scanf("%d%d",&N,&D);
    float inventory[N],price[N],ratio[N];
    for(int i=0;i<N;i++) scanf("%f",&inventory[i]);
    map<float,int> ratio2Id;
    for(int i=0;i<N;i++){
        scanf("%f",&price[i]);
        ratio2Id[price[i]/inventory[i]] = i;
    }
    sort(ratio,ratio+N,greater<float>());
    auto it = ratio2Id.rbegin();
    float profit = 0,re = D;
    while(re>0){
        profit += min(re,inventory[it->second])*it->first;
        re -= inventory[it->second];
        it++;
    }
    printf("%.2f\n",profit);
    return 0;
}
