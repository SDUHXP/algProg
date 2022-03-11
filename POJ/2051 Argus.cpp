#include <cstdio>
#include <queue>
using namespace std;
struct node{
    int id;
    int time;
    int interval;   //interval of last apperance
    node(int i,int t,int f):id(i),time(t),interval(f){};
    bool operator<(const node &a)const{
        return (time>a.time) ||(time==a.time && id>a.id);
    }
};
priority_queue<node>que;
int main(){
    int Q_num,Period; char str[20];
    while(scanf("%s",str)){
        if(str[0]=='#') break;
        scanf("%d %d",&Q_num,&Period);
        que.push(node(Q_num,Period,Period));
    }
    int K; scanf("%d",&K);
    while(K--){
        node temp = que.top();
        que.pop();
        printf("%d\n",temp.id);
        temp.time += temp.interval;
        que.push(temp);
    }
    return 0;
}
