#include <iostream>
#include <map>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    int arr[N];
    map<int,int>cnt;
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        cnt[arr[i]]++;
    }
    for(int i=0;i<N;i++)
        if(cnt[arr[i]]==1){
            printf("%d\n",arr[i]);
            return 0;
        }
    printf("None\n");
    return 0;
}
