#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
bool primeTab[maxN];
vector<int>primes;
int init(){
    for(int i=2;i<maxN;i++) primeTab[i] = true;
    for(int i=2;i*i<maxN;i++)
        if(primeTab[i]==true){
            for(int j=2;i*j<maxN;j++) primeTab[j*i] = false;
        }
    for(int i=2;i<maxN;i++)
        if(primeTab[i]==true) primes.push_back(i);

//    for(auto it:primes) printf("%d\n",it);
    return 0;
}
int main(){
    init();
    int N; scanf("%d",&N);
    printf("%d=",N);
    int idx = 0;
    while(N!=1 && idx<primes.size()){
        int cnt = 0;
        while(N%primes[idx]==0){
            cnt ++; N /= primes[idx];
        }
        if(cnt!=0){
            printf("%d",primes[idx]);
            if(cnt>1) printf("^%d",cnt);
            if(N!=1) printf("*");
        }
        idx++;
    }
}
