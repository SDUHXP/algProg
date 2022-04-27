#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>decLst,pathRec;
vector<int>weight,path;
void dfs(int cur,int sumLeft){
    if(decLst[cur].size()==0 && sumLeft==weight[cur]){
        path.push_back(weight[cur]);    pathRec.push_back(path);
        path.pop_back();    return;
    }
    if(sumLeft<=weight[cur]) return;
    path.push_back(weight[cur]);
    for(int i=0;i<decLst[cur].size();i++){
        dfs(decLst[cur][i],sumLeft-weight[cur]);
    }
    path.pop_back();
    return;
}
void prtPath(vector<int>& path){
    for(auto it=path.begin();it!=path.end();it++)
        printf("%d%s",*it,it==path.end()-1?"\n":" ");
    return;
}
bool pathCmp(const vector<int>& pathA ,const vector<int>&pathB){
    bool flag  = lexicographical_compare(pathA.begin(),pathA.end(),pathB.begin(),pathB.end());
    return !flag;
}

int main(){
    int N,M,S,val; scanf("%d%d%d",&N,&M,&S);
    weight.resize(N);   decLst.resize(N);
    for(int i=0;i<N;i++) scanf("%d",&weight[i]);
    for(int i=0;i<M;i++){
        int id,K; scanf("%d%d",&id,&K);
        for(int j=0;j<K;j++){
            scanf("%d",&val);
            decLst[id].push_back(val);
        }
    }
    dfs(0,S);
    sort(pathRec.begin(),pathRec.end(),pathCmp);
    for(int i=0;i<pathRec.size();i++)  prtPath(pathRec[i]);
}
