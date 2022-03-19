#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char str1[25],str2[25];
    scanf("%s",str1);
    int len = strlen(str1);
    str2[len] = '\0';
    int res = 0;
    for(int i=len-1;i>=0;i--){
        int dig = res + (str1[i] - '0')*2;
        str2[i] = dig%10 + '0';
        res = dig/10;
    }
    if(res) printf("No\n%d%s",res,str2);
    else{
        int cnt[10] = {0};
        bool flag = true;
        for(int i=0;i<len;i++) cnt[str1[i]-'0'] ++;
        for(int i=0;i<len;i++) cnt[str2[i]-'0'] --;
        for(int i=0;i<10;i++)  if(cnt[i]) flag = false;
        if(flag) printf("Yes\n");
        else  printf("No\n");
        printf("%s\n",str2);
    }
    return 0;
}
