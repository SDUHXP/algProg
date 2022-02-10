#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
map<string>name2Id;
map<int>id2Name;
int cnt = 0;        //num of existing members
const int maxN = 1010;
int relation[maxN][maxN];
vector<vector<int>>Rec(maxN);
bool visit[maxN];
int weight[maxN] = {0};
int dfs(int beg,int &num,int &head){
    int totalW = 0;
    for(int i=0;i<Rec[beg].size();i++){
        if(!visit[Rec[beg][i]){
            visit[rec[beg][i]] = true;
            num ++;
            totalW += relation[beg][rec[beg][i]];
            if(weight[beg]>weight[head])  head = beg;
            totalW  += dfs(Rec[beg][i],num);
        }
    }
    return totalW;
}
int main(){
    int N,K; scanf("%d%d",&N,&K);
    string str1,str2;
    int w;
    for(int i=0;i<N;i++){
        cin>>str1>>str2>>w;
        if(!name2Id[str1]){
            name2Id[str1] = ++cnt;
            id2Name[cnt] = str1;
        }

        if(!name2Id[str2]) {
            name2Id[str2] = ++cnt;
            id2Name[cnt] = str2;
        }
        int id1 = name2Id[str1];
        int id2 = name2Id[str2];
        relation[id1][id2] = relation[id2][id1] = w;
        rec[id1].push_back(id2);
        rec[id2].push_back(id1);
    }
    for(int i=1;i<=N;i++){
        for(int j=0;j<rec[i].size();j++){
            int tgt = rec[i][j];
            weight[i] += relation[i][tgt];
        }
    }
    int grsoup  = 0;
    set<pair<string,int>> res;
    for(int i=1;i<=N;i++)
    if(!visit[i]){
       int num = 1;
       int head = i;
       int relation = dfs(i,&num,&head);        //member id starts from 1;
       if(relation>K && num>2) group ++;
       string hName = id2Name[head];
       res.insert(make_pair(hName,num));
    }
    cout<<group<<endl;
    set<pair<string,id>>::iterator it ;
    for(it = res.begin();it!=res.end();it++)
        cout<<it->first<<" "<<it->second<<endl;sss
}
