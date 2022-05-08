#include <bits/stdc++.h>
using namespace std;
const int maxN = 10005;
bool primTable[maxN];
int calPrime(){
    for(int i=0;i<maxN;i++) primTable[i] = true;
    for(int i=2;i*i<maxN;i++){
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
    while(pos<M && posSta[pos]){
        pos += dis*dis;
        dis ++;
    }
    if(pos<M) posSta[pos] = true;  //true stands for occupied
    return pos;

}
int main(){
    int M,N; scanf("%d%d",&M,&N);
    calPrime();
    for(;M<maxN;M++) if(primTable[M]) break;
    for(int i=1;i<=N;i++){
        int key; scanf("%d",&key);
        int pos = insKey(key,M);
        if(pos<M) printf("%d ",pos);
        else printf("-");
    }
    return 0;
}
