#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char word[100];
    char gap[30];
    scanf("%s",word);
    int len = strlen(word);
    int H = (len+2)/3;
    int W = len - 2*H;
    for(int i=0;i<W;i++) gap[i] = ' ';
    gap[W] = '\0';
    for(int i=0;i<H-1;i++) printf("%c%s%c\n",word[i],gap,word[len-1-i]);
    for(int i=H-1;i<H+W+1;i++) printf("%c",word[i]);
    return 0;
}
