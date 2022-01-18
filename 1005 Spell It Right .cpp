#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;
char number[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
    char num[110];
    scanf("%s",num);
    int len = strlen(num);
    int sum = accumulate(num,num+len,0) - '0'*len;
    char ans[10];
    sprintf(ans,"%d",sum);
    for(int i=0;ans[i]!='\0';i++)
        printf("%s%s",i==0?"":" ",number[ans[i]-'0']);
}
