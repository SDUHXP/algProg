#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
int arr[maxN],pos[maxN];
set<int>disOrd; //index of 0 in array
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
         scanf("%d",&arr[i]);
         if(arr[i]!=i) disOrd.insert(i);
         pos[arr[i]] = i;
    }
    int cnt = 0;
    while(pos[0]!=0 || disOrd.size()!=0){
        if(pos[0]!=0){
            int tmpPos = pos[pos[0]];
            swap(arr[tmpPos],arr[pos[0]]);
            pos[arr[pos[0]]] = arr[pos[0]];
            pos[0] = tmpPos;
            disOrd.erase(tmpPos);
            if(pos[0]==0) disOrd.erase(0);
        }
        else if(pos[0]==0&&disOrd.size()){
            int tmpKey = *disOrd.begin();
            int tmpPos = pos[tmpKey];
            swap(arr[pos[0]],arr[tmpPos]);
            pos[tmpKey] = pos[0];
            pos[0] = tmpPos;
            disOrd.insert(0);
        }
        cnt++;
    }
    for(int i=0;i<N;i++)  printf("%d ",arr[i]);
    printf("\ncnt=%d\n",cnt);
    return 0;
}
