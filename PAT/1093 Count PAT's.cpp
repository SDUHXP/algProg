#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
char str[maxN];
int leftP[maxN],rightT[maxN];   //start from 1
const int mod = 1000000007;
int main(){
    scanf("%s",str);   //str start from 0
    int len = strlen(str);
    for(int i=1;i<=len;i++){
        if(str[i-1]=='P') leftP[i] = leftP[i-1]+1;
        else leftP[i] = leftP[i-1];
    }
    for(int i=len;i>=1;i--)
        if(str[i-1]=='T') rightT[i] = rightT[i+1] +1;
        else rightT[i] = rightT[i+1];

    long long sum = 0;
    for(int i=1;i<=len;i++)
        if(str[i-1]=='A'){
            sum += (leftP[i]*rightT[i])%mod;
            sum %= mod;
        }
    printf("%lld\n",sum);
}
