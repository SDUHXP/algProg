#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN = 100005;
struct stu{
    int id;
    char name[10];
    int score;
}school[maxN];
bool cmp1(stu &a,stu &b){
    return a.id<b.id;
}
bool cmp2(stu &a,stu &b){
    if(strcmp(a.name,b.name)==0) return a.id<b.id;
    else return strcmp(a.name,b.name)<0;
}
bool cmp3(stu &a,stu &b){
    if(a.score!=b.score) return a.score<b.score;
    else return a.id<b.id;
}
int main ()
{
    int N,C; scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++){
        scanf("%d%s%d",&school[i].id,school[i].name,&school[i].score);

    }
    if(C==1) sort(school,school+N,cmp1);
    else if(C==2) sort(school,school+N,cmp2);
    else sort(school,school+N,cmp3);
    for(int i=0;i<N;i++)
        printf("%06d %s %d\n",school[i].id,school[i].name,school[i].score);


}
