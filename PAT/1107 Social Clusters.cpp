#include <cstdio>
#include <map>
#include <set>
#include <functional>
using namespace std;
const int maxN = 1010;
int father[maxN],hobby[maxN];
int findRoot(int node){
    int root = node;
    while(father[root]!=root){
        root = father[root];
    }
    while(father[node]!=root){
        int temp = father[node];
        father[node] = root;
        node = temp;
    }
    return root;
}
void unite(int a,int b){
    int ra = findRoot(a);
    int rb = findRoot(b);
    father[rb] = ra;
    return;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++) father[i] = i;
    for(int i=1;i<=N;i++){
        int K; scanf("%d:",&K);
        for(int j=0;j<K;j++){
            int h; scanf("%d",&h);
            if(hobby[h]==0) hobby[h] = i;
            else unite(i,hobby[h]);
        }
    }
    map<int,int>res;
    for(int i=1;i<=N;i++)   res[findRoot(i)] ++;
    printf("%d\n",res.size());
    set<int,greater<int>> ans;
    for(auto it = res.begin();it != res.end();it++)
        ans.insert(it->second);
    for(auto it=ans.begin();it!=ans.end();it++)
        printf("%s%d",(it==ans.begin()?"":" "),*it);
    return 0;
}
