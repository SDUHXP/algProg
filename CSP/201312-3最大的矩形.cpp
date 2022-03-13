#include <iostream>
using namespace std;
int main(){
    int N; cin>>N;
    int arr[N+1];
    for(int i=1;i<=N;i++) cin>>arr[i];
    int maxArea = 0;
    int idx = 0;
    for(int i=1;i<=N;i++){
        int l = i,r = i;
        while(l>0 && arr[l]>=arr[i]) l --;
        while(r<=N && arr[r]>=arr[i])  r ++;
        if(maxArea<(r-l-1)*arr[i]) maxArea = (r-l-1)*arr[i];
    }
    cout<<maxArea<<endl;
}
