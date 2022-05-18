#include <bits/stdc++.h>
using namespace std;
set<int>row,diagnoal,antiDiagnoal;
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
        int K; scanf("%d",&K);
        row.clear(); diagnoal.clear();
        antiDiagnoal.clear();
        for(int col=1;col<=K;col++){
            int val; scanf("%d",&val);
            row.insert(val);
            diagnoal.insert(val-col);
            antiDiagnoal.insert(val+col);
        }
        if(row.size()==K && diagnoal.size()==K && antiDiagnoal.size()==K) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
