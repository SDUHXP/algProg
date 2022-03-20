#include <iostream>
#include <algorithm>
using namespace std;
int binSearch(int arr[],int low,int high,int val){
    int mid = (low+high)/2;
    while(low<high){
        if(arr[mid]==val) return mid;
        else if(arr[mid]<val) low = mid+1;
        else high = mid -1;
        mid = (low+high)/2;
    }
    return low;
}
int main(){
    int N,M; scanf("%d%d",&N,&M);
    int coin[N+1];
    for(int i=0;i<N;i++) scanf("%d",&coin[i]);
    sort(coin,coin+N);
    for(int i=0;i<N-1;i++){
        if(coin[N-1]<M-coin[i]) continue;
        int pos = binSearch(coin,i+1,N-1,M-coin[i]);
//          int pos = lower_bound(coin+i+1,coin+N,M-coin[i]) - coin;
          if(coin[pos]==M-coin[i]){
                printf("%d %d\n",coin[i],coin[pos]);
                return 0;
          }
    }
    printf("No Solution\n");
}

