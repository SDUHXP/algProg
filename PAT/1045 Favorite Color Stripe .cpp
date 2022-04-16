#if 0
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int,int>pri;
vector<int>stripe;
int main(){
    int N; scanf("%d",&N);
    int M; scanf("%d",&M);
    for(int i=1;i<=M;i++){
        int val; scanf("%d",&val);
        pri[val] = i;
    }
    int L; scanf("%d",&L);
    int cnt[L] = {0};
    for(int j=0;j<L;j++){
        int val;       scanf("%d",&val);
        //if(pri[val])   stripe.push_back(pri[val]);
        if(pri[val])   stripe.push_back(val);       //this will cause time limited , reason not specific
    }
    int dp[stripe.size()] = {0};
    for(int i=0;i<stripe.size();i++) dp[i] = 1;
    vector<int>temp;
    temp.push_back(stripe[0]);
    for(int i=1;i<stripe.size();i++){
        if(stripe[i]==*(temp.end()-1)) dp[temp.size()-1]++;
        else temp.push_back(stripe[i]);
    }
    for(int i=1;i<temp.size();i++){
        int tempL = 0;
        for(int j=0;j<i;j++)
//            if(temp[j]<=temp[i]) tempL = max(tempL,dp[j]);
            if(pri[temp[j]]<=pri[temp[i]]) tempL = max(tempL,dp[j]);   //this cause time limited, reason not specific
        dp[i] += tempL;
    }
    int maxL = 0;
    for(int i=0;i<temp.size();i++)  maxL = max(dp[i],maxL);
    printf("%d\n",maxL);
}
#else

#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    int M; scanf("%d",&M);
    int favor[M+1];
    for(int i=1;i<=M;i++)   scanf("%d",&favor[i]);
    int L; scanf("%d",&L);
    int stripe[L+1];
    for(int j=1;j<=L;j++){
        scanf("%d",&stripe[j]);
    }
    int dp[M+1][L+1] = {0};
    memset(dp,0,sizeof(dp));
    //dynamic programing permits extending contents
    for(int i=1;i<=M;i++)
        for(int j=1;j<=L;j++){
            int maxDp = max(dp[i][j-1],dp[i-1][j]);
            if(favor[i]==stripe[j]) dp[i][j] = maxDp + 1;   //
            else dp[i][j] = maxDp;
        }
    printf("%d\n",dp[M][L]);
}
#endif
