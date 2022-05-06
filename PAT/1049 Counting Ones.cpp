#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    int  pos = 1;
    int sum = 0;
    int orgN = N;
    while(N){
        int cur = N%10;
        int lVal = N/10;
        int wt = pow(10,pos-1);
        int rVal = orgN%wt;
        if(cur==0) sum += lVal*wt;
        else if(cur==1)  sum += lVal*wt + rVal+1;
        else sum += (lVal+1)*wt;
        pos ++;
        N /= 10;
    }
    printf("%d\n",sum);
    return 0;
}
