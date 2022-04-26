#include <bits/stdc++.h>
using namespace std;
const int maxN = 15;
struct node{
    int val;
    int left,right,father;
    node():val(-1),left(-1),right(-1),father(-1){}
}tree[maxN];
vector<int>levOrd,inOrd;
int revTree(int root){
    if(root==-1) return root;
    int left = tree[root].left;
    int right = tree[root].right;
    tree[root].left = revTree(right);
    tree[root].right = revTree(left);
    return root;
}
void levTra(int root){
    queue<int>nodeQue;
    nodeQue.push(root);
    while(nodeQue.size()){
        int ft = nodeQue.front();
        if(tree[ft].left!=-1) nodeQue.push(tree[ft].left);
        if(tree[ft].right!=-1) nodeQue.push(tree[ft].right);
        levOrd.push_back(ft);
        nodeQue.pop();
    }
    return;
}
void inTra(int root){
    if(tree[root].left==-1 && tree[root].right==-1){
        inOrd.push_back(root);
        return;
    }
    if(tree[root].left!=-1) inTra(tree[root].left);
    inOrd.push_back(root);
    if(tree[root].right!=-1) inTra(tree[root].right);
    return;
}
void prtVec(vector<int>&vec){
    for(auto it=vec.begin();it!=vec.end();it++)
        printf("%d%s",*it,it==vec.end()-1?"\n":" ");
}
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
        char left[5],right[5];
        scanf("%s%s",left,right);
        tree[i].left = left[0]=='-'?-1:atoi(left);
        tree[i].right = right[0]=='-'?-1:atoi(right);
        if(tree[i].left!=-1) tree[tree[i].left].father = i;
        if(tree[i].right!=-1) tree[tree[i].right].father = i;
    }
    int root = 0;
    while(tree[root].father!=-1) root = tree[root].father;
    revTree(root);  levTra(root);   inTra(root);
    prtVec(levOrd); prtVec(inOrd);
    return 0;
}
