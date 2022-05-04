#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
int coupon[maxN],product[maxN];
int main(){
    int NC; scanf("%d",&NC);
    for(int i=0;i<NC;i++) scanf("%d",&coupon[i]);
    int NP; scanf("%d",&NP);
    for(int i=0;i<NP;i++) scanf("%d",&product[i]);
    sort(coupon,coupon+NC); sort(product,product+NP);
    int i=0,j=0; int sum = 0;
    while(i<NC&&j<NP&&coupon[i]<0&&product[j]<0){
        sum += coupon[i]*product[j];
        i++; j++;
    }
    i = NC-1; j= NP-1;
    while(i>=0&&j>=0&&coupon[i]>0&&product[j]>0){
        sum += coupon[i]*product[j];
        i--; j--;
    }
    printf("%d\n",sum);
}
