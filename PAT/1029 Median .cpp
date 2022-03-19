#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 400005;
int arr[maxN];
int main ()
{
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    int M; scanf("%d",&M);
    for(int i=0;i<M;i++) scanf("%d",&arr[N+i]);
    sort(arr,arr+M+N);
    int mid = (M+N+1)/2-1;
    printf("%d\n",arr[mid]);
}
