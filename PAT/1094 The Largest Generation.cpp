#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>decLst;
map<int,int>levCnt;
void bfs(int beg){
    queue<pair<int,int>>perQue;
    perQue.push(make_pair(beg,1));
    while(perQue.size()){
        int ft = perQue.front().first;
        int lev = perQue.front().second;
        levCnt[lev] ++;
        perQue.pop();
        for(int i=0;i<decLst[ft].size();i++)
            perQue.push(make_pair(decLst[ft][i],lev+1));
    }
    return;
}
int main(){
    int N,M; scanf("%d%d",&N,&M);
    decLst.resize(N+1);
    for(int i=0;i<M;i++){
        int id,decNum,val; scanf("%d%d",&id,&decNum);
        for(int j=0;j<decNum;j++){
            scanf("%d",&val);
            decLst[id].push_back(val);
        }
    }
    bfs(1);
    int maxNum = 0,maxCorIdx = 0;
    for(auto it=levCnt.begin();it!=levCnt.end();it++)
        if(it->second > maxNum) {maxNum = it->second; maxCorIdx = it->first;}
    printf("%d %d\n",maxNum,maxCorIdx);
}
