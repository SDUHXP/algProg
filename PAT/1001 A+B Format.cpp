#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int res = a+b;
    if(res<0){
        printf("-");
        res = -res;
    }
    char str[10];
    sprintf(str,"%d",res);
    int len = strlen(str);
    for(int i=0;i<len;i++){
        int index = len -1 -i;
        printf("%c",str[i]);
        if(index && index%3==0) printf(",");
    }
    return 0;
}
