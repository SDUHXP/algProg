#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>decLst;
vector<int>weight,path;
vector<vector<int>>pathRec;
void dfs(int cur,int sumLeft){
    path.push_back(cur);
    if(decLst[cur].size()==0 && sumLeft==weight[cur]){
        cout<<"hello world"<<endl;
        pathRec.push_back(path);
        return;
    }
    if(sumLeft<=weight[cur]) return;
    for(int i=0;i<decLst[cur].size();i++){
        dfs(decLst[cur][i],sumLeft-weight[decLst[cur][i]]);
    }
    path.pop_back();
    return;
}
void prtPath(vector<int>& path){
    for(auto it=path.begin();it!=path.end();it++)
        printf("%d%s",weight[*it],it==path.end()-1?"\n":" ");
    return;
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
    cout<<"pathRec.size() == "<<pathRec.size()<<endl;
    for(int i=0;i<pathRec.size();i++)  prtPath(pathRec[i]);
}
