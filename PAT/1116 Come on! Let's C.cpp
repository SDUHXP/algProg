#include <bits/stdc++.h>
using namespace std;
map<int,int>rankList;
bool isPrime(int N){
    if(N<2||(N>2&&N%2==0)) return false;
    int root = sqrt(N);
    for(int i=3;i<=root;i+=2)
        if(N%i==0) return false;
    return true;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int id; scanf("%d",&id);
        rankList[id] = i;
    }
    int K; scanf("%d",&K);
    for(int i=1;i<=K;i++){
        int id; scanf("%d",&id);
        printf("%04d: ",id);
        int rank = rankList[id];
        if(rank==0) {printf("Are you kidding?\n"); continue;}
        else if(rank==-1) printf("Checked\n");
        else if(rank==1) printf("Mystery Award\n");
        else if(isPrime(rank)) printf("Minion\n");
        else printf("Chocolate\n");
        rankList[id] = -1;
    }
    return 0;
}
