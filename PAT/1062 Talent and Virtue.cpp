#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
struct person{
    int id,section;
    int virtue,talent,tot;
    bool operator<(person&oth){
        if(section!=oth.section) return section<oth.section;
        else if(tot!=oth.tot) return tot>oth.tot;
        else return virtue>oth.virtue;
    }
}rcds[maxN];
int main(){
    int N,L,H,ignore;  scanf("%d%d%d",&N,&L,&H);
    for(int i=0;i<N;i++){
        int vir,tal;  scanf("%d%d%d",&rcds[i].id,&vir,&tal);
        rcds[i].virtue = vir; rcds[i].talent = tal;
        rcds[i].tot = vir+tal;
        if(vir<L||tal<L) {rcds[i].section = 5; ignore++;}        //not counted
        else if(vir>=H && tal>=H) rcds[i].section = 1;         //sage
        else if(vir>=H && tal<H) rcds[i].section = 2;     //noble
        else if(vir<H&&tal<H&&vir>=tal) rcds[i].section = 3;      //fool
        else rcds[i].section = 4;      //small
    }
    sort(rcds,rcds+N);
    printf("%d\n",N-ignore);
    for(int i=0;i<N-ignore;i++)  printf("%06d %d %d\n",rcds[i].id,rcds[i].virtue,rcds[i].talent);
    return 0;
}
