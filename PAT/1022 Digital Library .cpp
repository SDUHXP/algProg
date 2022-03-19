#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 10010;
struct book{
    int id;
    char title[85];       //1
    char author[85];        //2
    char keyWord[5][15];        //3
    char publisher[85];         //4
    char year[10];                   //5
}lib[maxN];
void searchVal(char* val,int N,int idx){
    bool flag = false;
    int cnt = 0;
    for(int i=0;i<N;i++){
        flag = false;
        if(idx ==1 && strcmp(lib[i].title,val)==0) flag = true;
        else if(idx==2 && strcmp(lib[i].author,val)==0)    flag = true;
        else if(idx==4 && strcmp(lib[i].publisher,val)==0)    flag = true;
        else if(idx==5 && strcmp(lib[i].year,val)==0)    flag = true;
        else if(idx==3)
        {
            for(int j=0;j<5;j++)
                if(strcmp(lib[i].keyWord[j],val)==0) flag = true;
        }
        if(flag){
            printf("%07d\n",lib[i].id);
            cnt ++;
        }
    }
    if(cnt==0) printf("Not Found\n");
    return ;
}
int main(){
    int N;
    scanf("%d",&N);
    char line[85];
    for(int i=0;i<N;i++){
        scanf("%d",&lib[i].id);
        getchar();
        cin.getline(lib[i].title,sizeof(lib[i].title));
        cin.getline(lib[i].author,sizeof(lib[i].author));
        cin.getline(line,sizeof(line));
        char* key = strtok(line," ");
        int kCnt = 0;
        while(key!=NULL){
            strcpy(lib[i].keyWord[kCnt],key);
            kCnt ++;
            key = strtok(NULL," ");
        }
        cin.getline(lib[i].publisher,sizeof(lib[i].publisher));
        scanf("%s",lib[i].year);
    }
    sort(lib,lib+N,[](book &a,book &b){return a.id<b.id;});
    int M; scanf("%d",&M);
    while(M--){
        int idx;
        char str[85];
        scanf("%d: %[^\n]s",&idx,str);
        printf("%d: %s\n",idx,str);
        searchVal(str,N,idx);
    }
    return 0;
}
