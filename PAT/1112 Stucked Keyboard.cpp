#include <bits/stdc++.h>
using namespace std;
int main(){
    int K; scanf("%d",&K);
    char str[1005];
    scanf("%s[^\n]",str);
    int len = strlen(str);
    set<char> chSet,chDel;
    int i = 0;
    while(i<len){
        char ch = str[i];
        int j = i;
        while(j<len&&str[j]==ch) j++;
        if((j-i)%K==0) chSet.insert(ch);
        else  chDel.insert(ch);
        i = j;
    }
    for(auto ch:chDel) chSet.erase(ch);
    vector<char>chCand;         //this vector to make sure char is stored in detected order;
    for(int i=0;i<len && chSet.size();i++){
        char ch = str[i];
        if(chSet.find(ch)!=chSet.end()) chCand.push_back(ch);
        chSet.erase(ch);
    }
    for(auto ch:chCand){
        printf("%c",ch);
        char pattern[20];
        sprintf(pattern,"(%c)\\1{%d}",ch,K-1);
        string res = regex_replace(str,regex(pattern),"$1");
        strcpy(str,res.c_str());

    }
    printf("\n%s",str);
    return 0;
}