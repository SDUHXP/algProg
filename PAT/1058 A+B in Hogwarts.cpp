#include <bits/stdc++.h>
using namespace std;
int main(){
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d%d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    int g3,s3,k3;
    k3 = (k1+k2)%29;
    s3 = ((k1+k2)/29 +s1+s2)%17;
    g3 = ((k1+k2)/29 +s1+s2)/17+g1+g2;
    printf("%d.%d.%d",g3,s3,k3);
    return 0;
}
