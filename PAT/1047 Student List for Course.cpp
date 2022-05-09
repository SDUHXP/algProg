#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<string>>course;
int main(){
    int N,K; scanf("%d%d",&N,&K);
    char stu[10]; int num,id;
    for(int i=0;i<N;i++){
        scanf("%s%d",stu,&num);
        for(int j=0;j<num;j++){
            scanf("%d",&id);
            course[id].push_back(stu);
        }
    }
    for(int id=1;id<=K;id++){
        printf("%d %d\n",id,course[id].size());
        sort(course[id].begin(),course[id].end());
        for(auto it:course[id]) printf("%s\n",it.c_str());
    }
    return 0;
}
