#include <bits/stdc++.h>
using namespace std;
int calFac(int nu,int de){return (nu%de)?calFac(de,nu%de):de;}
class fraction{
    public:
    int nu,de,itg;   //numerator,denominator,and integer part;
    fraction(int n=0,int d=1):nu(n),de(d),itg(0){};
    void simplify(){
        int fac = calFac(nu,de);
        nu /= fac; de /= fac;
        if(de<0)  { nu *= -1; de *= -1;}
        return;
    }
    void prtFac(){
        bool flag = false;
        if(nu<0) {printf("(-"); flag = true; nu *= -1;}
        if (nu/de!=0 && nu%de!=0) printf("%d %d/%d",nu/de,nu%de,de);
        else if(nu/de != 0) printf("%d",nu/de);
        else if(nu%de != 0) printf("%d/%d",nu%de,de);
        else printf("0");
        if(flag){ printf(")"); nu *= -1;}
        return;
    }
    void facAdd(fraction &oth);
    void facMin(fraction &oth);
    void facMti(fraction &oth);
    void facDiv(fraction &oth);
};

void fraction::facAdd(fraction &oth){
    itg += oth.itg;
    nu = nu*oth.de + oth.nu*de;
    de = de*oth.de; simplify();
    return;
}
void fraction::facMti(fraction &oth){
    itg = itg*oth.itg;
    simplify(); return;
}
int main(){
    fraction fac1,fac2,facRes;
    scanf("%d/%d%d/%d",&fac1.nu,&fac1.de,&fac2.nu,&fac2.de);
    fac1.simplify(); fac2.simplify(); facRes = fac1;

    //illustrate the calculation of addition
    fac1.prtFac(); printf(" + "); fac2.prtFac();
    printf(" = "); facRes.facAdd(fac2); facRes.prtFac();
    facRes = fac1;  printf("\n");

    //illustrate the calculation of reduction
    fraction facTmp = fraction(-fac2.nu,fac2.de);
    fac1.prtFac(); printf(" - "); fac2.prtFac();
    printf(" = "); facRes.facAdd(facTmp); facRes.prtFac();
    facRes = fac1;  printf("\n");


    return 0;
}
