#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    int  posWt = 1,sum = 0;
    while(N/posWt){
        int cur = N/posWt%10;
        int lVal = N/posWt/10;
        int rVal = N%posWt;
        if(cur==0) sum += lVal*posWt;
        else if(cur==1)  sum += lVal*posWt + rVal+1;
        else sum += (lVal+1)*posWt;
        posWt *= 10;
    }
    printf("%d\n",sum);
    return 0;
}
