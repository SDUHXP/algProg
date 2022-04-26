//push is preorder, pop is in order
#include <bits/stdc++.h>
using namespace std;
const int maxN = 35;
struct node{
    int val;
    node *left,*right;
    node(int v=0):val(v),left(NULL),right(NULL){}
};
vector<int>preOrd,inOrd,postOrd;
stack<int>opStack;
void prtVec(vector<int>&vec){
    for(auto it=vec.begin();it!=vec.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
node* buildTree(int preL,int preR,int inL,int inR){
    if(preL>preR) return NULL;
    if(preL==preR){
        node* root = new node(preOrd[preL]);
        return root;
    }
    int sentinel = preOrd[preL];
    int senIdx = inL;
    while(senIdx<=inR)
        if(inOrd[senIdx]==sentinel) break;
        else senIdx++;
    node* root = new node(sentinel);
    root->left = buildTree(preL+1,preL+senIdx-inL,inL,senIdx-1);
    root->right = buildTree(preL+senIdx-inL+1,preR,senIdx+1,inR);
    return root;
}
void postTrav(node* root){
    if(root->left==NULL && root->right==NULL){
        postOrd.push_back(root->val);
        return;
    }
    if(root->left!=NULL) postTrav(root->left);
    if(root->right!=NULL) postTrav(root->right);
    postOrd.push_back(root->val);
    return;
}
int main(){
    int N; scanf("%d",&N);
    char op[5]; int val;
    for(int i=0;i<2*N;i++){
        scanf("%s",op);
        if(strcmp(op,"Push")==0){
            scanf("%d",&val);
            preOrd.push_back(val);
            opStack.push(val);
        }
        else{
            val = opStack.top();
            inOrd.push_back(val);
            opStack.pop();
        }
    }
    node* root = buildTree(0,N-1,0,N-1);;
    postTrav(root);
    for(auto it=postOrd.begin();it!=postOrd.end();it++)
        printf("%s%d",it==postOrd.begin()?"":" ",*it);
}
