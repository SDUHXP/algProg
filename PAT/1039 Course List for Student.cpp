#include <bits/stdc++.h>
using namespace std;
vector<vector<string>>course;
map<string,set<int>>schedule;
int main(){
    int N,K; scanf("%d%d",&N,&K);
    course.resize(K);
    for(int i=0;i<K;i++){
        int id,num; scanf("%d%d",&id,&num);
        string str;
        for(int j=0;j<num;j++){
            cin>>str; schedule[str].insert(id);
        }
    }
    for(int i=0;i<N;i++){
        string stu; cin>>stu;
        cout<<stu<<" "<<schedule[stu].size();
        for(auto cou:schedule[stu]) printf(" %d",cou);
        cout<<endl;
    }
    return 0;
}
