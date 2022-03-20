#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
struct interval{
    int diff;
    int left,right;
    interval(int d,int l,int r):diff(d),left(l),right(r){}
    bool operator<(interval &other){
        if(diff!=other.diff) return diff<other.diff;
        else return left<other.left;
    }
};
int binSearch(int arr[],int low,int high,int val){
    int mid = (low+high)/2;
    while(low<high){
        //mid+1 or mid is important, it means result no less than val
        if(arr[mid]<val) low = mid+1;
        else high = mid;
        mid = (low+high)/2;
    }
    return low;
}
int main(){
    int N,M; scanf("%d%d",&N,&M);
    int sum[N+1] = {0};
    for(int i=1;i<=N;i++) {
        int val; scanf("%d",&val);
        sum[i] = sum[i-1] + val;
    }
    vector<interval> cache;
    for(int i=0;i<N;i++){
        if(sum[N]-sum[i]<M) continue;
//        int pos = binSearch(sum,i+1,N,sum[i]+M);   //[i+1,pos] is ans
        int pos = lower_bound(sum+(i+1),sum+N,sum[i]+M)-sum;   //[i+1,pos] is ans
        cache.push_back(interval(sum[pos]-sum[i],i+1,pos));
    }
    sort(cache.begin(),cache.end());
    int diff = cache[0].diff;
    for(int i=0;i<cache.size();i++)
        if(cache[i].diff==diff) printf("%d-%d\n",cache[i].left,cache[i].right);

    return 0;
}
