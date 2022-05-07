#include <bits/stdc++.h>
using namespace std;
long long calFac(long long numerator,long long denominator){
    while(numerator%denominator){
        long long temp = numerator%denominator;
        numerator = denominator; denominator = temp;
    }
    return abs(denominator);
}
long long simplify(long long& numerator,long long& denominator){
    long long maxFac = calFac(numerator,denominator);
    numerator /= maxFac;  denominator /= maxFac;
    if(denominator<0) {numerator *= -1; denominator *= -1;}
    long long quotient = numerator/denominator;
    return quotient;
}
void prtFac(long long numerator,long long denominator){
    if(numerator==0) {printf("0"); return;}
    bool negative = false;
    if(numerator<0)  {printf("(-"); negative = true; numerator = -numerator;}
    if(numerator/denominator!=0) printf("%d",numerator/denominator);
    if(numerator%denominator!=0){
      if(numerator/denominator) printf(" ");
      printf("%lld/%lld",numerator%denominator,denominator);
    }
    if(negative) printf(")");
    return;
}
void facAdd(long long& numeratorRes,long long& denominatorRes,long long numerator,long long denominator){
    numeratorRes = numeratorRes*denominator + numerator*denominatorRes;
    denominatorRes = denominatorRes*denominator;
    simplify(numeratorRes,denominatorRes);
    return;
}
void facMultiply(long long& numeratorRes,long long& denominatorRes,long long numerator,long long denominator){
    numeratorRes *= numerator;
    denominatorRes *= denominator;
    simplify(numeratorRes,denominatorRes);
    return;
}
int main(){
    long long numerator1,denominator1,numerator2,denominator2;
    long long numeratorRes,denominatorRes;
    scanf("%lld/%lld%lld/%lld",&numerator1,&denominator1,&numerator2,&denominator2);
    simplify(numerator1,denominator1);  simplify(numerator2,denominator2);

    prtFac(numerator1,denominator1);    printf(" + ");
    prtFac(numerator2,denominator2);    printf(" = ");
    numeratorRes = numerator1; denominatorRes = denominator1;
    facAdd(numeratorRes,denominatorRes,numerator2,denominator2);
    prtFac(numeratorRes,denominatorRes); printf("\n");

    prtFac(numerator1,denominator1);    printf(" - ");
    prtFac(numerator2,denominator2);    printf(" = ");
    numeratorRes = numerator1; denominatorRes = denominator1;
    facAdd(numeratorRes,denominatorRes,-numerator2,denominator2);
    prtFac(numeratorRes,denominatorRes); printf("\n");

    prtFac(numerator1,denominator1);    printf(" * ");
    prtFac(numerator2,denominator2);    printf(" = ");
    numeratorRes = numerator1; denominatorRes = denominator1;
    facMultiply(numeratorRes,denominatorRes,numerator2,denominator2);
    prtFac(numeratorRes,denominatorRes); printf("\n");

    prtFac(numerator1,denominator1);    printf(" / ");
    prtFac(numerator2,denominator2);    printf(" = ");
    numeratorRes = numerator1; denominatorRes = denominator1;
    if(numerator2==0){printf("Inf\n");  return 0; }
    facMultiply(numeratorRes,denominatorRes,denominator2,numerator2);
    prtFac(numeratorRes,denominatorRes);  printf("\n");

    return 0;
}
