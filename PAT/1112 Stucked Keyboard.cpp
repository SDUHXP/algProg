#include <bits/stdc++.h>
using namespace std;
int main(){
    int K; scanf("%d",&K);
    char str[1005],res[1005];
    scanf("%s[^\n]",str);
    int len = strlen(str);
    set<char> chSet;
    for(int i=0;i<len;){
        char ch = str[i];
        int j = i;
        while(j<len&&str[j]==ch) j++;
        if((j-i)%K==0) chSet.insert(ch);
        else if(chSet.find(ch)!=chSet.end()) chSet.erase(ch);
        i = j;
    }

    for(auto ch:chSet){
        printf("%c",ch);
        char pattern[20];
        sprintf(pattern,"(%c)\\1{%d}",ch,K-1);
        string res = regex_replace(str,regex(pattern),"$1");
        strcpy(str,res.c_str());

    }
    printf("\n%s",str);

}