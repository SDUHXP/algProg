#include <cstdio>
using namespace std;
float CofAns[2010];
float cofA[1005],cofB[1005];
int main(){
    int K,exp;
    float cof;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d%f",&exp,&cof);
        cofA[exp] = cof;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d%f",&exp,&cof);
        cofB[exp] = cof;
    }
    int cnt = 0;
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++){
            CofAns[i+j] += cofA[i]*cofB[j];
        }
    for(int i=2000;i>=0;i--)
        if(CofAns[i]!=0) cnt ++;
    printf("%d",cnt);
    for(int i=2000;i>=0;i--)
        if(CofAns[i]!=0) printf(" %d %.1f",i,CofAns[i]);
}

