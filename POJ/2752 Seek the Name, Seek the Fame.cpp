#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxN = 400010;
char str[maxN];
int nextArr[maxN];    //nextArr array used for KMP algorithm
void buildnextArr(char str[]){
    nextArr[0] = -1;
    int j=-1;
    int len = strlen(str);
    for(int i=1;i<len;i++){
        while(j>-1&&str[i]!=str[j+1]) j = nextArr[j];
        if(str[i]==str[j+1]) j++;
        nextArr[i] = j;
    }
    return;
}
int prtPreLen(int len){
    if(nextArr[len]==-1){
        printf("%d",len+1);
        return 0;
    }
    prtPreLen(nextArr[len]);
    printf(" %d",len+1);
    return 0;
}
int main(){
    while(scanf("%s",str)!=EOF){
        int len = strlen(str);
        buildnextArr(str);
        prtPreLen(len-1);
        printf("\n");
    }
}
