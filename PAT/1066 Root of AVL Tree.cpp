#include <bits/stdc++.h>
using namespace std;
struct node{
    int val,ht;
    node *left,*right;
    node():val(0),ht(0),left(NULL),right(NULL){}
};
node* leftRoate(node* root){
    if(root==NULL) return root;
    node* temp = root->right;
    temp->left = root;
    root->right = temp->left;
    return temp;
}
node* rightRotate(node* root){
    if(root==NULL) return root;
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
inline int getHt(node* cur){
    return (cur==NULL?0:cur->ht);
}
node* insertNode(node*root,int val){
    cout<<"hello world"<<endl;
    if(root==NULL){
        root = new node(); root->val = val;
        root->ht = 1;       return root;
    }
    if(val<root->val) root->left = insertNode(root->left,val);
    else root->right = insertNode(root->right,val);
    int htL = getHt(root->left);
    int htR = getHt(root->right);
    if(htL-htR==2){
        int htLL = getHt(root->left->left);
        int htLR = getHt(root->left->right);
        if(htLL>htLR){
            root = rightRotate(root);
        }
        else {
            root->left = leftRoate(root->left);
            root = rightRotate(root);
        }
        htL = htL - 1;
        htR = htR + 1;
    }
    else if(htL-htR==-2){
        int htRL = getHt(root->right->left);
        int htRR = getHt(root->right->right);
        if(htRL<htRR) root = leftRoate(root);
        else{
            root->right = rightRotate(root->right);
            root = leftRoate(root);
        }
        htR = htR -1;
        htL = htL + 1;
    }
    root->ht = max(htL,htR) + 1;
    return root;
}
void levelTrav(node* root){
    queue<node*> nodeQue;
    nodeQue.push(root);
    while(nodeQue.size()!=0){
        node* cur = nodeQue.front();
        if(cur->left!=NULL) nodeQue.push(cur->left);
        if(cur->right!=NULL) nodeQue.push(cur->right);
        printf("(%d,%d) ",cur->val,cur->ht);
        nodeQue.pop();
    }
    return;

}
int main(){
    int N; scanf("%d",&N);
    node* root = NULL;
    for(int i=0;i<N;i++){
        int val; scanf("%d",&val);
        root = insertNode(root,val);
    }
   // node* cur = root->left->left->left;
//    printf("%d  %d\n",cur->val,cur->ht);
    levelTrav(root);
}
