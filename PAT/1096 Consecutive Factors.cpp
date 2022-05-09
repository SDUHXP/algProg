#include <bits/stdc++.h>
using namespace std;
int main(){
    pair<int,int>resInterval;
    long long N; scanf("%ld",&N);
    long long sqrN = sqrt(N) + 1;
    for(int i=2;i<=sqrN;i++){
        int j = i; long long tmpN = N;
        for(;j<=sqrN;j++){
            if(tmpN%j!=0) break;
            tmpN /= j;
        }
        if(j-i>resInterval.second-resInterval.first){
            resInterval.first = i;
            resInterval.second = j;
        }
    }
     if(resInterval.second!=resInterval.first){
            printf("%d\n",resInterval.second-resInterval.first);
            for(int i=resInterval.first;i!=resInterval.second;i++)
                printf("%s%d",i==resInterval.first?"":"*",i);
     }
    else printf("1\n%d",N);
    return 0;
}
