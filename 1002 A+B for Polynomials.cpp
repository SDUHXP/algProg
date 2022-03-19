#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int K,exp;
    float coe;
    float res[1010];
    int cnt = 0;
    memset(res,0,sizeof(res));
    for(int i=0;i<2;i++){
        scanf("%d",&K);
        while(K--){
            scanf("%d%f",&exp,&coe);
            if(!res[exp]) cnt ++;
            res[exp] += coe;
            //be careful about some dig may be zero ,after summation
            if(!res[exp]) cnt --;

        }
    }
    printf("%d",cnt);
    for(int i=1000;i>=0;i--)
        if(res[i]) printf(" %d %.1f",i,res[i]);
    return 0;
}
