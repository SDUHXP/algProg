#include <bits/stdc++.h>
using namespace std;
vector<int>orgOrd,travOrd;
struct node{
    int val;
    node *left,*right;
    node():val(0),left(NULL),right(NULL){}
};
node* insNode(node *root,int val){
    if(root==NULL){
        root = new node();root->val = val;
        return root;
    }
    if(val<root->val)  root->left = insNode(root->left,val);
    else root->right = insNode(root->right,val);
    return root;
}
void treeTrav(node* root,vector<int>&path,bool pre,bool mirror){
    if(root==NULL) return;
    if(pre==true) path.push_back(root->val);
    if(mirror==false){
        treeTrav(root->left,path,pre,mirror);
        treeTrav(root->right,path,pre,mirror);
    }
    else{
        treeTrav(root->right,path,pre,mirror);
        treeTrav(root->left,path,pre,mirror);
    }
    if(pre==false) path.push_back(root->val);
    return;
}
void prtPath(vector<int>& path){
    for(auto it=path.begin();it!=path.end();it++)
        printf("%d%s",*it,it==path.end()-1?"\n":" ");
    return;
}

int main(){
    int N; scanf("%d",&N);
    node* root = NULL;
    orgOrd.resize(N);
    for(int i=0;i<N;i++){
        scanf("%d",&orgOrd[i]);
        root = insNode(root,orgOrd[i]);
    }
    treeTrav(root,travOrd,true,false);
    if(travOrd==orgOrd){
        printf("YES\n");  travOrd.clear();
        treeTrav(root,travOrd,false,false);
        prtPath(travOrd);  return 0;
    }
    else{
        travOrd.clear();  treeTrav(root,travOrd,true,true);
        if(travOrd==orgOrd){
            printf("YES\n");  travOrd.clear();
            treeTrav(root,travOrd,false,true);
            prtPath(travOrd);  return 0;
        }
    }
    printf("NO\n");
    return 0;
}
