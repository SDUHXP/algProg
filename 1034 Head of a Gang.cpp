#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxN = 2010;
int relation[maxN][maxN];
vector<vector<int>>Rec(maxN);
bool visit[maxN] = {0};
int weight[maxN] = {0};
int cnt = 0;        //num of all monitored person
map<string,int>name2Id;
map<int,string>id2Name;
int dfs(int cur,int &num,int &head){
    int totalW = 0;
    for(int i=0;i<Rec[cur].size();i++){
        int tar = Rec[cur][i];
        totalW += relation[cur][tar];
        relation[cur][tar] = relation[tar][cur] = 0;
        if(!visit[tar]){
            visit[tar] = true;
            num ++;
            if(weight[cur]>weight[head])  head = cur;
            else if(weight[cur]==weight[head] && id2Name[cur]<id2Name[head]) head = cur;
            totalW  += dfs(tar,num,head);
        }
    }
    return totalW;
}
int main(){
    int N,K,W; scanf("%d%d",&N,&K);
    string str1,str2;
    for(int i=0;i<N;i++){
        cin>>str1>>str2>>W;
        if(name2Id[str1]==0){
            name2Id[str1] = ++cnt;
            id2Name[cnt] = str1;
        }
        if(name2Id[str2]==0) {
            name2Id[str2] = ++cnt;
            id2Name[cnt] = str2;
        }
        int id1 = name2Id[str1];
        int id2 = name2Id[str2];
        relation[id1][id2] += W;
        relation[id2][id1] += W;
        weight[id1] += W;
        weight[id2] += W;
        if(relation[id1][id2]>W) continue;
        Rec[id2].push_back(id1);
        Rec[id1].push_back(id2);
    }
    map<string,int> res;
    for(int i=1;i<=cnt;i++){
        if(!visit[i]){
           int num = 1;
           int head = i;
           visit[i] = true;
           int relation = dfs(i,num,head);        //member id starts from 1;
           if(relation>K && num>2){
                string hName = id2Name[head];
                res[hName] = num;
            }
        }
    }
    cout<<res.size()<<endl;
    for(auto it = res.begin();it!=res.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
}
