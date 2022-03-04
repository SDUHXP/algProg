#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 100005;
struct node{
    int val;
    bool valid;
    int addr,next;
}myList[maxN];
bool cmpNode(const node& nodeA,const node& nodeB ){
    if(nodeA.valid!=nodeB.valid) return nodeA.valid;
    else  return nodeA.val<nodeB.val;
}
int main(){
    int N,start; scanf("%d%d",&N,&start);
    if(start==-1) {printf("0 -1"); return 0;}   //be carefule about N>1 start = -1;
    for(int i=0;i<N;i++){
        int addr; scanf("%d",&addr);
        myList[addr].addr = addr;
        scanf("%d%d",&myList[addr].val,&myList[addr].next);
    }
    int cur = start;
    int cnt = 0;
    while(cur!=-1){
        myList[cur].valid = true;
        cur = myList[cur].next;
        cnt ++;
    }
    sort(myList,myList+maxN,cmpNode);
    printf("%d %05d\n",cnt,myList[0].addr);
    for(int i=0;i<cnt;i++){
        printf("%05d %d ",myList[i].addr,myList[i].val);
        if(i==cnt-1) printf("-1\n");
        else printf("%05d\n",myList[i+1].addr);
    }
}
