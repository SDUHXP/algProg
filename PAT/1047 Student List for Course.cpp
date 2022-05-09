#include <bits/stdc++.h>
using namespace std;
map<int,set<string>>course;
int main(){
    int N,K; scanf("%d%d",&N,&K);
    string str; int num,id;
    for(int i=0;i<N;i++){
        cin>>str>>num;
        for(int j=0;j<num;j++){
            scanf("%d",&id);
            course[id].insert(str);
        }
    }
    for(int id=1;id<=K;id++){
        printf("%d %d\n",id,course[id].size());
        for(auto it:course[id]) printf("%s\n",it.c_str());
    }
    return 0;
}
