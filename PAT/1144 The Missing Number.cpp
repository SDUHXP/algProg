#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    map<int,int>numCnt;
    for(int i=0;i<N;i++){
        int val; scanf("%d",&val);
        numCnt[val]++;
    }
    for(int i=1;;i++)
        if(numCnt[i]==0){ printf("%d",i); break;}
    return 0;
}