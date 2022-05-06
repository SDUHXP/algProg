#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    double sum = 0;
    for(int i=0;i<N;i++){
        double val; scanf("%lf",&val);
        sum += (N-i)*(i+1)*val;
    }
    printf("%.2lf\n",sum);
    return 0;
}
