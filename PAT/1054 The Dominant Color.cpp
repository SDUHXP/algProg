#include <bits/stdc++.h>
using namespace std;
map<int,int>colCnt;
int main(){
    int M,N; scanf("%d%d",&M,&N);
    int val,maxCol=-1;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            scanf("%d",&val);
            colCnt[val] ++;
            if(colCnt[val]>M*N/2) maxCol = val;
        }
    printf("%d\n",maxCol);
    return 0;
}
