#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
int arr[maxN];
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    int maxL = -1,minR = 0x3fffffff;
    int maxLArr[N],minRArr[N];
    for(int i=0;i<N;i++){
        if(arr[i]>maxL) maxL = arr[i];
        maxLArr[i] = maxL;
    }
    for(int i=N-1;i>=0;i--){
        if(arr[i]<minR) minR = arr[i];
        minRArr[i] = minR;
    }
    bool flag = true;
    set<int>res;
    for(int i=0;i<N;i++)
        if(arr[i]>=maxLArr[i] &&arr[i]<=minRArr[i]) res.insert(arr[i]);
    printf("%d\n",res.size());
    for(auto it=res.begin();it!=res.end();it++)
        printf("%d%s",*it,it==(--res.end())?"\n":" ");
    if(res.size()==0) printf("\n");
    return 0;

}
