#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int maxN = 10010;
const int maxK = 110;
struct player{
    int arr,dur;
    int serTime,wait;
    bool vip;
}plys[maxN];
struct table{
    int id,openTime,serCnt;
    bool vip;
    bool operator<(const table &a)const{
        if(openTime!=a.openTime) return openTime<a.openTime;
        else return id<a.id;
    }
    #if 0
    void operator=(const table &a){
		id = a.id;
		openTime = a.openTime;
		serCnt = a.serCnt;
		vip = a.vip;
	}
	#endif
}tables[maxK];
class tabCmp{
    public:
    bool operator()(const table &a,const table &b) const{
        return a.id<b.id;
    }
};
set<table>ordTab;
set<table>vipTab;
void addVirPlayer(int n){
    plys[n].arr = 24*3600;
    plys[n].vip = true;
    plys[n+1].arr = 24*3600;
    plys[n+1].vip = false;
}
bool leftFirst(set<table>::iterator itL,set<table>::iterator itR,int pArr){
    if(itL->openTime<=pArr && itR->openTime<=pArr) return itL->id < itR->id;
    else return itL->openTime < itR->openTime;
}
int allocTable(int N){
    addVirPlayer(N);
    int ordId =0,vipId = 0;  //array index for ordinary player and vip player
    set<table>::iterator itOrd,itVip,it;  //iteror for table
    //allocate the idx th player
    for(int idx=0;idx<N;idx++){
        if(plys[idx].arr>=21*3600||(ordTab.begin()->openTime>=21*3600 && vipTab.begin()->openTime>=21*3600))  return idx;
        for(int i=idx;i<N+2;i++)  if(plys[i].vip) {vipId = i; break;}
        for(int i=idx;i<N+2;i++)  if(plys[i].vip==false) {ordId = i; break;}
        itOrd = ordTab.begin();  itVip = vipTab.begin();
        for(it=ordTab.begin();it!=ordTab.end();it++)
            if(it->openTime<=plys[idx].arr && it->id<itOrd->id )  itOrd = it;
        for(it=vipTab.begin();it!=vipTab.end();it++)
            if(it->openTime<plys[idx].arr && it->id<itVip->id)  itVip = it;

        if(vipId==idx){
            if(plys[vipId].arr<itVip->openTime && itOrd->openTime<itVip->openTime){   //vip player take ord table
                plys[vipId].serTime = max(plys[vipId].arr,itOrd->openTime);
                table temp = *itOrd;
                temp.openTime = plys[vipId].serTime + plys[vipId].dur;
                temp.serCnt ++;
                ordTab.erase(itOrd);
                ordTab.insert(temp);
            }
            else{
                plys[vipId].serTime = max(plys[vipId].arr,itVip->openTime);
                table temp = *itVip;
                temp.openTime = plys[vipId].serTime + plys[vipId].dur;
                temp.serCnt ++;
                vipTab.erase(itVip);
                vipTab.insert(temp);
            }
        }
        else{
            #if 1
             //ordinary player use vip table; if vip table and ord table both available ,take the minimum id;
             if(itVip->openTime<plys[vipId].arr && leftFirst(itVip,itOrd,plys[ordId].arr)){      ///something wrong
                plys[ordId].serTime = max(plys[ordId].arr,itVip->openTime);
                table temp = *itVip;
                temp.openTime = plys[ordId].serTime + plys[ordId].dur;
                temp.serCnt ++;
                vipTab.erase(itVip);
                vipTab.insert(temp);
             }
            #endif // 0
             else {
                plys[ordId].serTime = max(plys[ordId].arr,itOrd->openTime);
                table temp = *itOrd;
                temp.openTime = plys[ordId].serTime + plys[ordId].dur;
                temp.serCnt ++;
                ordTab.erase(itOrd);
                ordTab.insert(temp);
             }
        }
    }
    return N;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
        int h,m,s;
        scanf("%d:%d:%d%d%d",&h,&m,&s,&plys[i].dur,&plys[i].vip);
        plys[i].arr = 3600*h+60*m+s;
        plys[i].dur = plys[i].dur<=120?plys[i].dur*60:120*60;
    }
    int K,M; scanf("%d%d",&K,&M);
    for(int i=1;i<=K;i++){
        tables[i].id = i;
        tables[i].openTime = 8*3600;
        tables[i].vip = false;
    }
    for(int i=0;i<M;i++){
        int id; scanf("%d",&id);
        tables[id].vip = true;
    }
    sort(plys,plys+N,[](player &a,player &b){return a.arr<b.arr;});
    for(int i=1;i<=K;i++)
        if(!tables[i].vip) ordTab.insert(tables[i]);
        else vipTab.insert(tables[i]);
    int cnt = allocTable(N);
    for(int i=0;i<cnt;i++)    plys[i].wait = (plys[i].serTime - plys[i].arr + 30)/60;
    //sort(plys,plys+cnt,[](player &a,player &b){return (a.serTime==b.serTime?a.wait<b.wait:a.serTime<b.serTime);});
    sort(plys,plys+cnt,[](player &a,player &b){return (a.serTime<b.serTime);});
    for(int i=0;i<cnt;i++)
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",plys[i].arr/3600,plys[i].arr%3600/60,plys[i].arr%60,
                                    plys[i].serTime/3600,plys[i].serTime%3600/60,plys[i].serTime%60,plys[i].wait);

    set<table,tabCmp>res(ordTab.begin(),ordTab.end());
    for(set<table>::iterator it = vipTab.begin();it!=vipTab.end();it++)     res.insert(*it);
    for(set<table>::iterator it = res.begin();it!=res.end();it++)
        if(it==res.begin()) printf("%d",    it->serCnt);
        else printf(" %d",it->serCnt);
    return 0;
}
