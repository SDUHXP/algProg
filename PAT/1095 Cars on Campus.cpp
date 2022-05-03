#include <bits/stdc++.h>
using namespace std;
const int maxN = 10001;
struct record{
    char plate[10];
    int ts; bool status;    //true for in, and false for out;
}rcds[maxN];
map<string,int>parkTim;
map<string,int>curStatus;    //record the latest potential valid record index
map<int,int>parkCnt;
int carCnt;
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
        int idx = curStatus[rcds[i].plate];
        bool flag = rcds[i].status;
        if(flag==true){
            curStatus[rcds[i].plate] = i;
            if(idx==-1) parkCnt[rcds[i].ts] = parkCnt[rcds[idx].ts];
            else
            {
                parkCnt[rcds[idx].ts] --;;
            }
        }
        else if(idx>=0 && flag==false){
            parkTim[rcds[i].plate] += rcds[i].ts - rcds[idx].ts;
            curStatus[rcds[i].plate] = -1;
            parkCnt[rcds[i].ts] = --carCnt;
        }
        else continue;
    }
    vector<string>pltRes;
    int maxTim = 0;
    for(auto it=parkTim.begin();it!=parkTim.end();it++)
        if(it->second>maxTim){
            pltRes.clear();
            pltRes.push_back(it->first);
            maxTim = it->second;
        }
        else if(it->second==maxTim) pltRes.push_back(it->first);

    cout<<endl<<endl;
    for(auto it=parkCnt.begin();it!=parkCnt.end();it++){
        int t = it->first;
        printf("%d:%d:%d %d\n",t/3600,t%3600/60,t%60,it->second);
    }

    cout<<endl<<endl;
    while(K--){
        scanf("%d:%d:%d",&h,&m,&s);
        int ts = h*3600+m*60+s;


    }

    cout<<endl<<endl;

    for(int i=0;i<pltRes.size();i++) cout<<pltRes[i]<<" ";
    printf("%02d:%02d:%02d\n",maxTim/3600,maxTim%3600/60,maxTim%60);

    cout<<"carCnt = "<<carCnt<<endl;

    return 0;
}
