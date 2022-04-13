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
        if(pri[val])   stripe.push_back(pri[val]);
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
            if(temp[j]<=temp[i]) tempL = max(tempL,dp[j]);
        dp[i] += tempL;
    }
    int maxL = 0;
    for(int i=0;i<temp.size();i++)  maxL = max(dp[i],maxL);
    printf("%d\n",maxL);
}
