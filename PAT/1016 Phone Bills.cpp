#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxN = 1010;
int rate[24];
int calCost(int beg,int end){
    int d1 = beg/1440 +1;
    int h1 = beg%1440/60;
    int m1 = beg%60;
    int d2 = end/1440 +1;
    int h2 = end%1440/60;
    int m2 = end%60;
    int cost = 0;  //use cents as unit
    while(d1<d2||h1<h2||m1<m2){
        cost += rate[h1];
        m1++;
        if(m1==60){
            m1 = 0;
            h1++;
        }
        if(h1==24){
            h1 = 0;
            d1++;
        }
    }
    return cost;
}
struct rec{
    char name[25];
    int time;
    bool state; //1 for on-line; 0 for off-line
    bool operator<(const rec& next){
        if(strcmp(name,next.name)){
            return strcmp(name,next.name) <0;
        }
        else return time<next.time;
    }
}recds[maxN];
struct phoneCall{
    char name[25];
    int start,end;
    int dur;
    float cost;
}calls[maxN];

int main(){
    for(int h=0;h<24;h++) scanf("%d",&rate[h]);
    int N; scanf("%d",&N);
    char name[25],state[10];
    int mon,d,h,m;
    for(int i=0;i<N;i++){
        scanf("%s%d:%d:%d:%d%s",recds[i].name,&mon,&d,&h,&m,state);
        if(state[1]=='n') recds[i].state = 1;
        else recds[i].state = 0;
        recds[i].time = (d-1)*24*60+h*60+m;
    }
    sort(recds,recds+N);
    int cnt = 0;
    //filter useless records
    for(int i=1;i<N;i++){
         if(!strcmp(recds[i-1].name,recds[i].name) && recds[i-1].state==1 && recds[i].state==0){
             strcpy(calls[cnt].name,recds[i].name);
             calls[cnt].start = recds[i-1].time;
             calls[cnt].end = recds[i].time;
             calls[cnt].dur = calls[cnt].end - calls[cnt].start;
             calls[cnt].cost = calCost(calls[cnt].start,calls[cnt].end);
             cnt ++;
         }
    }
    int acc = 0;
    for(int i=0;i<cnt;i++){
        if(i && strcmp(calls[i].name,calls[i-1].name)) {
                printf("Total amount: $%.2f\n",acc/100.0);
                acc = 0;
        }
        if(acc==0)  printf("%s %02d\n",calls[i].name,mon);  //beginning of record
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",calls[i].start/1440+1,calls[i].start%1440/60,calls[i].start%60,
                                                          calls[i].end/1440+1,calls[i].end%1440/60,calls[i].end%60,
                                                          calls[i].dur,calls[i].cost/100.0);
        acc += calls[i].cost;
    }
     printf("Total amount: $%.2f\n",acc/100.0);

}
