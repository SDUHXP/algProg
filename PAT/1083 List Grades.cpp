#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
struct stu{
    char name[15];
    char id[15];
    int sc;
    bool operator<(const stu&oth){return sc>oth.sc;}
}rcds[maxN];
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%s%s%d",rcds[i].name,rcds[i].id,&rcds[i].sc);
    int lower,upper;    scanf("%d%d",&lower,&upper);
    sort(rcds,rcds+N);
    if(rcds[0].sc<lower || rcds[N-1].sc>upper) {printf("NONE\n");return 0;}
    for(int i=0;i<N;i++)
        if(rcds[i].sc>=lower && rcds[i].sc<=upper)
            printf("%s %s\n",rcds[i].name,rcds[i].id);
    return 0;
}
