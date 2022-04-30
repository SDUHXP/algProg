//variable res matters the correctness of this problem ,but reason not specificed
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    long long A,B,C;
    for(int i=1;i<=T;i++){
        bool flag = false;
        scanf("%lld%lld%lld",&A,&B,&C);
        printf("Case #%d: ",i);
        long long res = A+B;        //very important,matter the correctness of this problem;
        if(A>0 && B>0 && (A+B<=0)) flag = true;
        else if (A<0 && B<0 &&(A+B>=0)) flag = false;
        else  flag = (A+B>C);
        if(flag) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
