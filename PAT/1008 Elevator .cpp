#include <cstdio>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    int ans = 5*N;
    int next,pre = 0;
    while(N--){
        scanf("%d",&next);
        ans += (next-pre)>0?6*(next-pre):4*(pre-next);
        pre = next;
    }
    printf("%d",ans);
}

