#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(long long arr[],int left,int right,long long val){
    if(arr[right-1]<=val)   return right;
    right--;
    int mid = (left+right)/2;
    while(left<right){
        if(arr[mid]<=val)   left = mid+1;
        else  right = mid;
        mid = (left+right)/2;
    }
    return left;
}
int main(){
    int N,P; scanf("%d%d",&N,&P);
    long long arr[N];
    for(int i=0;i<N;i++) scanf("%lld",&arr[i]);
    sort(arr,arr+N);
    int ans = 1;
    for(int st=0;st<N;st++){
        int pos = binarySearch(arr,st,N,arr[st]*P);
        ans = max(ans,pos-st);
    }
    printf("%d\n",ans);
    return 0;
}
