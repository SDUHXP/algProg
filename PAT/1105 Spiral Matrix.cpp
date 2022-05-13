#include <bits/stdc++.h>
using namespace std;
const int maxN = 10005;
int arr[maxN];
int main(){
    int num; scanf("%d",&num);
    for(int i=0;i<num;i++) scanf("%d",&arr[i]);
    int M = sqrt(num);
    while(num%M) M++;
    M = max(M,num/M);
    sort(arr,arr+num,[](int a,int b){return a>b;});
    int N = num/M;

    //int (*mat)[100] = new int[M][100];

    int mat [100][100];
    int level = M/2 + M%2;
    int cnt = 0;
    for(int l=0;l<level ;l++){
        for(int j=l;j<N-l;j++) mat[l][j] = arr[cnt++];
        for(int i=l+1;i<M-l;i++) mat[i][N-l-1] = arr[cnt++];
        for(int j=N-l-2;j>=l;j--) mat[M-l-1][j] = arr[cnt++];
        for(int i=M-l-2;i>l;i--) mat[i][l] = arr[cnt++];
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++) printf("%d%s",mat[i][j],j==N-1?"\n":" ");

    }

    return 0;
}
