#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
int arr[maxN],pos[maxN];
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
         scanf("%d",&arr[i]);
         pos[arr[i]] = i;
    }
    int cnt = 0;
    for(int i=0;i<N;i++){
        if(arr[i]!=i){
            swap(arr[i],arr[pos[i]]);
            cnt ++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
