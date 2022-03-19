#include <cstdio>
#include <algorithm>
using namespace std;
struct stu{
    int id;
    int score[4];
}Class[2010];
int stuRank[1000000][5];   //rank of Avg,cProg,math,eng and best;
int bestCou[1000000];  //best course id
char couMap[4] = {'A','C','M','E'};  //0 for Average ,1 for C program...
int couId;   //just a global variable for sort
int main(){
    int N,M; scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d%d%d%d",&Class[i].id,&Class[i].score[1],&Class[i].score[2],&Class[i].score[3]);
        Class[i].score[0] = Class[i].score[1]+Class[i].score[2]+Class[i].score[3];
        stuRank[Class[i].id][4] = N+1;  //initiate best rank
    }
    for(couId=0;couId<4;couId++){
        sort(Class,Class+N,[](stu &a,stu &b){return a.score[couId]>b.score[couId];});
        int pre = 110;
        for(int j=0;j<N;j++){
            if(Class[j].score[couId]!=pre){
                stuRank[Class[j].id][couId] = j+1;
                pre = Class[j].score[couId];
            }
            else  stuRank[Class[j].id][couId] = stuRank[Class[j-1].id][couId];
            if(stuRank[Class[j].id][couId]<stuRank[Class[j].id][4]){
                stuRank[Class[j].id][4] = stuRank[Class[j].id][couId];
                bestCou[Class[j].id] = couId;
            }
        }
    }
    for(int i=0;i<M;i++){
        int id; scanf("%d",&id);
        if(stuRank[id][4]==0) printf("N/A\n");
        else  printf("%d %c\n",stuRank[id][4],couMap[bestCou[id]]);
    }

}
