#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
struct cake{
    double inventory,price;
    double ratio;
    bool operator<(cake&oth){return ratio>oth.ratio;}
}repo[maxN];
int main(){
    int N,D; scanf("%d%d",&N,&D);
    for(int i=0;i<N;i++) scanf("%lf",&repo[i].inventory);
    for(int i=0;i<N;i++){
        scanf("%lf",&repo[i].price);
        repo[i].ratio = repo[i].price/repo[i].inventory;
    }
    sort(repo,repo+N);
    double profit = 0,re = D;
    for(int i=0;i<N&&re>0;i++){
        profit += min(re,repo[i].inventory)*repo[i].ratio;
        re -= repo[i].inventory;
    }
    printf("%.2lf\n",profit);
    return 0;
}
