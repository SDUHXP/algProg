//be careful about the order when calculate product of int and float(double/long double)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    long double sum = 0.0;
    for(int i=0;i<N;i++){
        long double val; scanf("%Lf",&val);
        //correct order is float * int;   not int*float
        sum += val*(i+1)*(N-i);
    }
    printf("%.2Lf\n",sum);

    return 0;
}
