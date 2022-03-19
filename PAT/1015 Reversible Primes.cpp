#include <cstdio>
#include <algorithm>
using namespace std;
bool isPrime(int N){
    if(N==1 ||(N>2 && N%2==0)) return false;
    for(int i=3;i*i<=N;i+=2)
        if(N%i==0) return false;
    return true;
}
int getRevDec(int N,int base){
    int num[20]={0};
    int len = 0;
    while(N){
        num[len++] = N%base ;
        N /= base;
    }
    int ans = 0;
    for(int i=0;i<len;i++)
        ans = ans*base + num[i];
    return ans;
}
int main(){
    int N,D;
    while(scanf("%d%d",&N,&D)==2){
        int revVal = getRevDec(N,D);
        if(!isPrime(N) || !isPrime(revVal)) {
            printf("No\n");
            continue;
        }
        else printf("Yes\n");
    }
}
