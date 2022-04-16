#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int N,M; scanf("%d%d",&N,&M);
    int weight[N+1];
    for(int i=1;i<=N;i++)  scanf("%d",&weight[i]);
    sort(weight+1,weight+N+1,[](int &a,int &b){return a>b;});
    int dp[N+1][M+1];
    memset(dp,0,sizeof(dp));
    bool choose[N+1][M+1];
    for(int i=1;i<=N;i++){
        for(int v=weight[i];v<=M;v++){
            if(dp[i-1][v-weight[i]]+weight[i]>=dp[i-1][v]){
                dp[i][v] = dp[i-1][v-weight[i]] + weight[i];
                choose[i][v] = true;
            }
            else{
                dp[i][v] = dp[i-1][v];
                choose[i][v] = false;
            }
        }
    }
    if(dp[N][M]==M){
        bool flag[N+1] = {0};
        int V = M,cnt = 0;
        for(int idx = N;idx>0;idx--)
            if(V && choose[idx][V]){
                flag[idx] = true;
                V -= weight[idx];
                cnt ++;
            }

        for(int i=N;i>0;i--)
            if(flag[i]) {
                printf("%d",weight[i]);
                cnt--;
                if(cnt>0) printf(" ");
            }
    }
    else printf("No Solution\n");
    return 0;
}
