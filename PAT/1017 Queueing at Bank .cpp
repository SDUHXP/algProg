#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 10010;
const int maxK = 110;
struct custom{
    int arr;
    int proc;
    int serv;
}csters[maxN];
int windows[maxK];
int getMinWin(int N){
    int idx=0;
    int earest = 30*3600;
    for(int i=0;i<N;i++)
        if(windows[i]<earest){
            idx = i;
            earest = windows[i];
        }
    return idx;
}
int main(){
    int N,K; scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++) windows[i] = 8*3600;
    int h,m,s,t;
    int cnt = 0; //the number of customers can be servered
    for(int i=0;i<N;i++){
        scanf("%d:%d:%d%d",&h,&m,&s,&t);
        int arr = h*3600+m*60+s;
        if(arr>17*3600) continue;
        csters[cnt].arr = arr;
        csters[cnt].proc = t*60;
        cnt ++;
    }
    sort(csters,csters+cnt,[](custom &a,custom &b){return a.arr<b.arr;});
    for(int i=0;i<cnt;i++){
        int minId = getMinWin(K);
        csters[i].serv = max(windows[minId],csters[i].arr);
        windows[minId] = csters[i].serv + csters[i].proc;
    }
    int ans = 0;
    for(int i=0;i<cnt;i++)
        ans += csters[i].serv - csters[i].arr;
    printf("%.1f\n",ans/cnt/60.0);
}
