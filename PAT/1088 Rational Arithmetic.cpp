#include <bits/stdc++.h>
using namespace std;
int calFac(int numerator,int denominator){
    while(numerator%denominator){
        int temp = numerator%denominator;
        numerator = denominator; denominator = temp;
    }
    return abs(denominator);
}
int simplify(int& numerator,int& denominator){
    int maxFac = calFac(numerator,denominator);
    numerator /= maxFac;  denominator /= maxFac;
    int quotient = numerator/denominator;
    return quotient;
}
void prtFac(int numerator,int denominator){
    if(numerator==0) {printf("0"); return;}
    bool negative = false;
    if(numerator<0)  {printf("(-"); negative = true; numerator = -numerator;}
    if(numerator/denominator!=0) printf("%d",numerator/denominator);
    if(numerator%denominator!=0){
      if(numerator/denominator) printf(" ");
      printf("%d/%d",numerator%denominator,denominator);
    }
    if(negative) printf(")");
    return;
}
void facAdd(int& numeratorRes,int& denominatorRes,int numerator,int denominator){
    numeratorRes = numeratorRes*denominator + numerator*denominatorRes;
    denominatorRes = denominatorRes*denominator;
    simplify(numeratorRes,denominatorRes);
    return;
}
void facMultiply(int& numeratorRes,int& denominatorRes,int numerator,int denominator){
    numeratorRes *= numerator;
    denominatorRes *= denominator;
    simplify(numeratorRes,denominatorRes);
    return;
}
int main(){
    int numerator1,denominator1,numerator2,denominator2;
    int numeratorRes,denominatorRes;
    scanf("%d/%d%d/%d",&numerator1,&denominator1,&numerator2,&denominator2);
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
    facMultiply(numeratorRes,denominatorRes,denominator2,numerator2);
    prtFac(numeratorRes,denominatorRes);  printf("\n");

    return 0;
}
