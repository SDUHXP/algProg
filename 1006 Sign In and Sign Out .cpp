#include <cstdio>
#include <algorithm>
using namespace std;
const int maxM = 1001;
struct stu{
    char name[20];
    int enter;
    int exit;
}lab[maxM];
int main(){
    int M; scanf("%d",&M);
    for(int i=0;i<M;i++){
        int h,m,s;
        scanf("%s%d:%d:%d",lab[i].name,&h,&m,&s);
        lab[i].enter = h*3600 + m*60 + s;
        scanf("%d:%d:%d",&h,&m,&s);
        lab[i].exit = h*3600 + m*60 + s;
    }
    sort(lab,lab+M,[](stu &a,stu &b){return a.enter<b.enter;});
    printf("%s",lab[0].name);
    sort(lab,lab+M,[](stu &a,stu &b){return a.exit<b.exit;});
    printf(" %s",lab[M-1].name);

}
