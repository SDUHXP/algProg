#include <bits/stdc++.h>
using namespace std;
struct node{
    int val,ht;
    node *left,*right;
    node():val(0),ht(0),left(NULL),right(NULL){}
};
inline int getHt(node* cur){
    return (cur==NULL?0:cur->ht);
}
node* leftRoate(node* root){
    if(root==NULL) return root;
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->ht = getHt(root->left)+1;
    return temp;
}
node* rightRotate(node* root){
    if(root==NULL) return root;
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->ht = getHt(root->right)+1;
    return temp;
}
node* insertNode(node*root,int val){
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
int main(){
    int N; scanf("%d",&N);
    node* root = NULL;
    for(int i=0;i<N;i++){
        int val; scanf("%d",&val);
        root = insertNode(root,val);
    }
    printf("%d\n",root->val);
}
