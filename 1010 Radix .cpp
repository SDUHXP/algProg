#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char N1[15],N2[15];
#define cnvVal(ch)   (ch>='a'?ch-'a'+10:ch-'0')
int maxDig(char N[],int len){
    int digMax = 0;
    for(int i=0;i<len;i++){
        if(cnvVal(N[i])>digMax) digMax = cnvVal(N[i]);
    }
    return digMax;
}
int main(){
    int flag,radix1;
    scanf("%s%s%d%d",N1,N2,&flag,&radix1);
    if(flag==2) swap(N1,N2);
    long long decVal1 = 0;
    int len1 = strlen(N1);
    for(int i=0;i<len1;i++)  decVal1 = decVal1*radix1 + cnvVal(N1[i]);

    int len2 = strlen(N2);
    long long radix2,left,right;
    left = maxDig(N2,len2)+1;
    right = max(left,decVal1);
    flag = false;
    //be careful ,if decVal1 is a number big enough, overflow may happen in binary search
    while(right>=left){
        radix2 = (left+right)/2;
        long long decVal2 = 0;
        for(int i=0;i<len2;i++)  decVal2 = decVal2*radix2 + cnvVal(N2[i]);
        if(decVal2==decVal1){
            flag = true;
            break;
        }
        else if(decVal2<0 || decVal2>decVal1)    right = radix2-1;    //overflow may happen
        else  left = radix2+1;
    }
    if(flag) printf("%lld",radix2);
    else printf("Impossible");
}
