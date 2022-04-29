#include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
struct node{
    int val;
    int left,right;
}tree[maxN];
int val[maxN];
void buildTree(int root,int& idx){
    if(tree[root].left==-1 && tree[root].right==-1){
        tree[root].val = val[idx++];
        return;
    }
    if(tree[root].left!=-1) buildTree(tree[root].left,idx);
    tree[root].val = val[idx++];
    if(tree[root].right!=-1) buildTree(tree[root].right,idx);
    return;
}
void levelTrav(int root){
    queue<int>idQue;
    idQue.push(root);
    while(idQue.size()){
        cout<<"helo world"<<endl;
        int cur = idQue.front();
        if(tree[cur].left!=-1) idQue.push(tree[cur].left);
        if(tree[cur].left!=-1) idQue.push(tree[cur].right);
        printf("%d ",tree[cur].val);
        idQue.pop();
    }
    return;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&tree[i].left,&tree[i].right);
    }
    for(int i=0;i<N;i++) scanf("%d",&val[i]);
    int idx = 0;
    buildTree(0,idx);
    levelTrav(0);
    return 0;
}
