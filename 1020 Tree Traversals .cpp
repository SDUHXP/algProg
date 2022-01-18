#include <cstdio>
#include <queue>
using namespace std;
const int maxN = 32;
int post[maxN],in[maxN];
struct node{
    int val;
    node *left,*right;
};
node* buildTree(int postL,int postR,int inL,int inR){
    if(postL>postR) return NULL;
    node* root = new node;
    root->val = post[postR];
    int idx = inR;
    while(idx>=inL){
        if(in[idx]==post[postR]) break;
        idx --;
    }
    root->left = buildTree(postL,postL+idx-inL-1,inL,idx-1);
    root->right = buildTree(postL+idx-inL,postR-1,idx+1,inR);
    return root;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&post[i]);
    for(int i=0;i<N;i++) scanf("%d",&in[i]);
    node* root = buildTree(0,N-1,0,N-1);
    queue<node*>que;
    que.push(root);
    while(que.size()){
        node* cur = que.front();
       if(cur->left)  que.push(cur->left);
       if(cur->right) que.push(cur->right);
       printf("%s%d",cur==root?"":" ",cur->val);
       que.pop();
    }
    return 0;

}
