#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char N1[15],N2[15];
int main(){
   float a,b,c;
   float ans = 1;
   for(int i=0;i<3;i++){
        scanf("%f%f%f",&a,&b,&c);
        if(a>max(b,c)) printf("W ");
        else if(b>max(a,c)) printf("T ");
        else printf("L ");
        ans *= max(a,max(b,c));
   }
   ans = (ans*0.65-1)*2;
   printf("%.2f",ans);
}
