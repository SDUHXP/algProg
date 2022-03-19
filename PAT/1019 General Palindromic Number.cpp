#include <cstdio>
using namespace std;
int main(){
    int N,B; scanf("%d%d",&N,&B);
    int num[32];
    int len = 0;
    while(N){
        num[len++] = N%B;
        N /= B;
    }
    int beg = 0;
    while(beg<=len-beg-1){
        if(num[beg]!=num[len-beg-1]) break;
        beg ++;
    }
    if(beg-1!=(len-1)/2) printf("No\n");
    else printf("Yes\n");
    for(int i=len-1;i>=0;i--) printf("%d%s",num[i],i==0?"":" ");
}
