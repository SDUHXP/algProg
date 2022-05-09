#include <bits/stdc++.h>
using namespace std;
int main(){
    pair<int,int>resInterval;
    long long N; scanf("%ld",&N);
    long long sqrN = sqrt(N) + 1;
    for(int i=2;i<=sqrN;i++){
        int j = i;
        for(;j<=sqrN;j++){ if(N%j!=0) break;}
        if(j-i>resInterval.second-resInterval.first){
            resInterval.first = i;
            resInterval.second = j;
        }
    }
    printf("%d\n",resInterval.second-resInterval.first);
    for(int i=resInterval.first;i!=resInterval.second;i++)
        printf("%s%d",i==resInterval.first?"":"*",i);
    return 0;
}
