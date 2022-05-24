#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    vector<int>rcd(N+1);
    for(int i=1;i<=N;i++) scanf("%d",&rcd[i]);
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++){
            vector<int>role(N+1,1);
            vector<int>liar;
            role[i] = role[j] = -1; //represent player i and player j is assumed as werewolf
            for(int k=1;k<=N;k++){
                if(rcd[k]*role[abs(rcd[k])]<0) liar.push_back(k);
            }
            if(liar.size()==2 && role[liar[0]]*role[liar[1]]<0){
                printf("%d %d",i,j);
                return 0;
            }
        }
    return 0;
}
