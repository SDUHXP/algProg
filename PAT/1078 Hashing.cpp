#include <bits/stdc++.h>
using namespace std;
//be careful about the max value since input M in [2,10^4],while the last prime is 10007;
const int maxN = 10020;
bool primTable[maxN];
int calPrime(){
    for(int i=2;i<maxN;i++) primTable[i] = true;
    for(int i=2;i*2<maxN;i++){
        if(primTable[i]==true){
            for(int j=2;i*j<maxN;j++)
                 primTable[i*j] = false;
        }
    }
    return 0;
}
bool posSta[maxN];
int insKey(int val,int M){
    int pos = val%M;
    int dis = 0;
    while(dis<M && posSta[pos]){
        dis ++;
        pos = val+ dis*dis;
        pos %= M;
    }
    return pos;
}
int main(){
    calPrime();
    int M,N; scanf("%d%d",&M,&N);
    for(;M<maxN;M++)
        if(primTable[M]) break;
    for(int i=1;i<=N;i++){
        int key; scanf("%d",&key);
        int pos = insKey(key,M);
        if(posSta[pos]==false){printf("%d",pos); posSta[pos]=true;}
        else printf("-");
        if(i!=N) printf(" ");
    }
    return 0;
}
