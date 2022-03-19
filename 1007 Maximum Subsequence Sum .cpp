#include <cstdio>
#include <algorithm>
using namespace std;
const int maxM = 10001;
int arr[maxM],dp[maxM];
int beg[maxM];
int main(){
    int M; scanf("%d",&M);
    bool flag = false;
    for(int i=0;i<M;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>=0) flag = true;
    }
    if(!flag) {
        printf("0 %d %d",arr[0],arr[M-1]);
        return 0;
    }
    dp[0] = arr[0]; //means the maximum subsequence sum end with arr[i]
    beg[0] = 0;
    int maxIdx = 0;
    for(int i=1;i<M;i++){
        if(dp[i-1]+arr[i]>=arr[i]){
            dp[i] = dp[i-1] + arr[i];
            beg[i] = beg[i-1];
        }
        else{
            dp[i] = arr[i];
            beg[i] = i;
        }
        if(dp[i]>dp[maxIdx])   maxIdx = i;
    }
    printf("%d %d %d",dp[maxIdx],arr[beg[maxIdx]],arr[maxIdx]);
}
