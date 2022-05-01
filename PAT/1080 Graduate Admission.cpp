#include <bits/stdc++.h>
using namespace std;
const int maxN = 40005,maxM = 101;
int quota[maxM];
struct ap{
    int ge,gi,fin,id;
    int apSch[5];
    bool operator<(const ap&oth){
        if(fin!=oth.fin) return fin>oth.fin;
        else return ge>oth.ge;
        }
    bool operator==(const ap& oth){return (ge==oth.ge && gi==oth.gi);}
}apps[maxN];
vector<vector<ap>>college;
void prtVec(vector<ap>&vec){
    sort(vec.begin(),vec.end(),[](ap&ap1,ap&ap2){return ap1.id<ap2.id;});
    for(int i=0;i<vec.size();i++) printf("%s%d",i==0?"":" ",vec[i].id);
    printf("\n");   return;
}
int main(){
    int N,M,K; scanf("%d%d%d",&N,&M,&K);
    college.resize(M);
    for(int i=0;i<M;i++) scanf("%d",&quota[i]);
    for(int i=0;i<N;i++){
        scanf("%d%d",&apps[i].ge,&apps[i].gi);
        apps[i].fin = apps[i].ge + apps[i].gi;
        apps[i].id = i;
        for(int j=0;j<K;j++) scanf("%d",&apps[i].apSch[j]);
    }
    sort(apps,apps+N);
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            int tar = apps[i].apSch[j];
            int num = college[tar].size();
            if(num<quota[tar]||(num>=quota[tar]&&college[tar][quota[tar]-1]==apps[i])){
                college[tar].push_back(apps[i]);
                break;
            }
        }
    }
    for(int i=0;i<M;i++) prtVec(college[i]);
    return 0;
}
