#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int maxN = 100005;
struct node{
    int val;
    bool valid;
    int addr,next;
}myList[maxN];
set<int>nodeVal;
vector<int>delNode;
int main(){
    int N,start; scanf("%d%d",&start,&N);
    if(start==-1) {printf("0 -1"); return 0;}   //be carefule about N>1 start = -1;
    for(int i=0;i<N;i++){
        int addr; scanf("%d",&addr);
        myList[addr].addr = addr;
        scanf("%d%d",&myList[addr].val,&myList[addr].next);
    }
    int pre,cur; pre=cur=start;
    while(cur!=-1){
        int absVal = abs(myList[cur].val);
        if(nodeVal.find(absVal)==nodeVal.end()){
            nodeVal.insert(absVal);
            pre = cur;
            cur = myList[cur].next;
        }
        else{
            delNode.push_back(cur);
            int temp = myList[cur].next;
            myList[pre].next = temp;
            cur = temp;
        }
    }
    cur = start;
    while(cur!=-1){
        printf("%05d %d ",myList[cur].addr,myList[cur].val);
        if(myList[cur].next==-1) printf("-1\n");
        else printf("%05d\n",myList[cur].next);
        cur = myList[cur].next;
    }
    for(int i=0;i<delNode.size();i++){
        printf("%05d %d ",delNode[i],myList[delNode[i]].val);
        if(i==delNode.size()-1) printf("-1\n");
        else printf("%05d\n",delNode[i+1]);
    }
    return 0;
}

