/*
make cnt[i][j] stands for i digit number in state j
state 0: i digit number is consist only with 2
state 1: i digit number is consist with 0 and 2
state 2; i digit number is consist with 2 and 3
state 3: i digit number is consist with 0 1 and 2
state 4: i digit number is consist with 0 2 and 3
state 5: i digit number is consist with 0 1 2 and 3
*/
#include <iostream>
using namespace std;
const int maxN = 1010;
#define mod 1000000007
long long cnt[maxN][6];
int main(){
    int N; cin>>N;
    cnt[1][0] = 1;
    for(int i=2;i<=N;i++){
        cnt[i][0] = cnt[i-1][0]%mod;
        cnt[i][1] = (cnt[i-1][0] + cnt[i-1][1]*2)%mod;
        cnt[i][2] = (cnt[i-1][0] + cnt[i-1][2])%mod;
        cnt[i][3] = (cnt[i-1][1] + cnt[i-1][3]*2)%mod;
        cnt[i][4] = (cnt[i-1][1] + cnt[i-1][2] + cnt[i-1][4]*2)%mod;
        cnt[i][5] = (cnt[i-1][3] + cnt[i-1][4] + cnt[i-1][5]*2)%mod;
    }
    cout<<cnt[N][5]<<endl;
}
