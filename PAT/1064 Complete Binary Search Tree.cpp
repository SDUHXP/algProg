#include <bits/stdc++.h>
using namespace std;
const int maxN = 1003;
int key[maxN],tree[maxN];
void buildTree(int cur,int& idx,int N){
    if(cur>=N) return;
    buildTree(2*cur+1,idx,N);
    tree[cur] = key[idx++];
    buildTree(2*cur+2,idx,N);
    return;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&key[i]);
    sort(key,key+N);
    int idx = 0;
    buildTree(0,idx,N);
    for(int i=0;i<N;i++) printf("%s%d",i==0?"":" ",tree[i]);
    return 0;
}
