#include <cstdio>
#include <iostream>
using namespace std;
const int maxN = 100010;
struct node{
    int val;
    int addr,next;
}listArr[maxN];
//[beg,end)
void outputlistArr(int beg){
    while(listArr[beg].next!=-1){
        printf("%05d %d %05d\n",beg,listArr[beg].val,listArr[beg].next);
        beg = listArr[beg].next;
    }
     printf("%05d %d -1\n",beg,listArr[beg].val);
}
int getKLen(int beg,int &end,int K,int term){
    int cnt = 0;
    int cur = beg;
    while(cur!=term && cnt<K){
        cnt ++;
        cur = listArr[cur].next;
    }
    end = cur;
    return cnt;
}
int  reverselistArr(int beg,int end,int K,int term){
    int len = getKLen(beg,end,K,term);
    if(len<K) return beg;
    int pre = beg;
    int cur = listArr[beg].next;
    while(cur!=end){
        int next = listArr[cur].next;
        listArr[cur].next = pre;
        pre = cur;
        cur = next;
    }
    listArr[beg].next = reverselistArr(end,-1,K,-1);
    return pre;
}
int main(){
    int start,N,K;
    scanf("%d%d%d",&start,&N,&K);
    for(int i=0;i<N;i++){
        int addr,val,next;
        scanf("%d%d%d",&addr,&val,&next);
        listArr[addr].val = val;
        listArr[addr].next = next;
    }
    //outputlistArr(start);
    int head = reverselistArr(start,-1,K,-1);
    outputlistArr(head);
}
