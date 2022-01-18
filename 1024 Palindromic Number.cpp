#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxL = 110;
void addRev(char num[maxL],char res[maxL]){
    int len = strlen(num);
    int dig,resDig = 0;
    for(int i=0;i<len;i++){
        dig = resDig + (num[i]-'0') + (num[len-1-i]-'0');
        res[i] = dig%10 + '0';
        resDig = dig/10;
    }
    if(resDig){
        res[len] = resDig + '0';
        res[len+1] = '\0';
    }
    else res[len] = '\0';
}
bool isPalin(char str[maxL]){
    int len = strlen(str);
    for(int i=0;i<=len/2;i++)
        if(str[i]!=str[len-i-1]) return false;
    return true;
}
int main(){
    char str[maxL],res[maxL];
    int K;
    scanf("%s%d",str,&K);
    for(int i=0;i<K;i++){
        if(isPalin(str)){
            printf("%s\n%d",str,i);
            return 0;
        }
        addRev(str,res);
        strcpy(str,res);
        memset(res,0,sizeof(res));
    }
    reverse(str,str+strlen(str));
    printf("%s\n%d",str,K);
    return 0;
}
