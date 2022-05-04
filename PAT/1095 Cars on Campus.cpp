#include <bits/stdc++.h>
using namespace std;
const int maxN = 10001;
struct record{
    char plate[10]; int ts;
    bool status,valid;
}rcds[maxN];
map<string,int>parkTim,pairStus;    //record the latest potential valid record index
map<int,int>parkCnt;
int carCnt = 0;
int main(){
    int N,K; scanf("%d%d",&N,&K);
    int h,m,s; char st[5];
    for(int i=0;i<N;i++){
        scanf("%s%d:%d:%d%s",rcds[i].plate,&h,&m,&s,st);
        rcds[i].ts = 3600*h+60*m+s;
        rcds[i].status = (st[0]=='i'?true:false);
    }
    sort(rcds,rcds+N,[](record&a,record&b){return a.ts<b.ts;});
    for(int i=0;i<N;i++){
        int idx = pairStus.find(rcds[i].plate)!=pairStus.end()?pairStus[rcds[i].plate]:-1;  //the latest record require to be paired of same plate
        bool flag = rcds[i].status;
        if(flag==true){
            if(idx!=-1) rcds[idx].valid = false;
            rcds[i].valid = true;
            pairStus[rcds[i].plate] = i;
        }
        else if(idx>=0){
            parkTim[rcds[i].plate] += rcds[i].ts - rcds[idx].ts;
            pairStus[rcds[i].plate] = -1;
            rcds[i].valid = true;
        }
        else rcds[i].valid = false;
    }
    sort(rcds,rcds+N,[](record&a,record&b){if(a.valid!=b.valid) return a.valid>b.valid; else return a.ts<b.ts;});
    for(int i=0;i<N&&rcds[i].valid;i++){
        if(rcds[i].status) parkCnt[rcds[i].ts] = ++carCnt;
        else parkCnt[rcds[i].ts] = --carCnt;
    }
    while(K--){
        scanf("%d:%d:%d",&h,&m,&s);
        int ts = h*3600+m*60+s;
        auto it = parkCnt.upper_bound(ts);
        it--;
        printf("%d\n",it->second);
    }
    vector<string>pltRes; int maxTim = 0;
    for(auto it=parkTim.begin();it!=parkTim.end();it++)
        if(it->second>maxTim){
            pltRes.clear(); pltRes.push_back(it->first);
            maxTim = it->second;
        }
        else if(it->second==maxTim) pltRes.push_back(it->first);

    for(int i=0;i<pltRes.size();i++) cout<<pltRes[i]<<" ";
    printf("%02d:%02d:%02d\n",maxTim/3600,maxTim%3600/60,maxTim%60);

    return 0;
}
