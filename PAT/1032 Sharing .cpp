#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxN = 100005;
struct node{
    char val;
    int next;
    bool visit;
}lib[maxN];

int main(){
    int addr,addr1,addr2,N;
    scanf("%d%d%d",&addr1,&addr2,&N);
    for(int i=0;i<N;i++){
        scanf("%d",&addr);
        scanf(" %c%d",&lib[addr].val,&lib[addr].next);
    }
    addr = addr1;
    while(addr!=-1){
        lib[addr].visit = true;
        addr = lib[addr].next;
    }
    addr = addr2;
    int flag = -1;
    while(addr!=-1){
        if(flag==-1 && lib[addr].visit) flag = addr;
        else if(flag!=-1 && lib[addr].visit==false) flag = -1;
        addr = lib[addr].next;
    }
    if(flag!=-1) printf("%05d\n",flag);
    else printf("-1\n");
    return 0;
}
