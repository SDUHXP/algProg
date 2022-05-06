#include <bits/stdc++.h>
using namespace std;
int calFac(int a,int b){
    while(a%b!=0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}
int rationAdd(int &nuRes,int& deRes,int nu,int de){
    nuRes = nuRes*de + nu*deRes;
    deRes = deRes*de;
    int maxFac = calFac(nuRes,deRes);
    deRes /= maxFac; nuRes /= maxFac;
    int intRes = nuRes/deRes;
    nuRes %= deRes;
    return intRes;
}
int main(){
    int N; scanf("%d",&N);
    int numeratorRes=0,denominatorRes=1,intRes = 0;
    int numerator,denominator;
    for(int i=0;i<N;i++){
        scanf("%d/%d",&numerator,&denominator);
        intRes += rationAdd(numeratorRes,denominatorRes,numerator,denominator);
    }
    if(intRes) printf("%d ",intRes);
    if(numeratorRes) printf("%d/%d\n",numeratorRes,denominatorRes);
    return 0;
}
