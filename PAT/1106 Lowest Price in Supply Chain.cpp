#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>decLst;
int bfs(int root,int& minNum){
    int level = -1;
    queue<pair<int,int>>eleQue;
    eleQue.push(make_pair(root,0));
    while(eleQue.size()){
        int ft = eleQue.front().first;
        int lev = eleQue.front().second;
        if(level!=-1 && lev>level) return level;
        if(decLst[ft].size()==0){level = lev;    minNum++;}
        eleQue.pop();
        for(int i=0;i<decLst[ft].size();i++)
            eleQue.push(make_pair(decLst[ft][i],lev+1));
    }
    return level;
}
int main(){
    int N,M,val; double P,R;
    scanf("%d%lf%lf",&N,&P,&R);
    decLst.resize(N);
    for(int i=0;i<N;i++){
        int K; scanf("%d",&K);
        for(int j=0;j<K;j++){
            scanf("%d",&val);
            decLst[i].push_back(val);
        }
    }
    int minNum = 0;
    int minLev = bfs(0,minNum);
    double price = pow(1+R/100,minLev)*P;
    printf("%.4lf %d\n",price,minLev);
    return 0;
}
