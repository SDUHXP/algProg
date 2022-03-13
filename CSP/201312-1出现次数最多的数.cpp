#include <iostream>
#include <map>
using namespace std;
map<int,int>record;
int main(){
    int N; cin>>N;
    for(int i=0;i<N;i++){
        int s; scanf("%d",&s);
        record[s]++;
    }
    auto ansIt = record.begin();
    for(auto it=record.begin();it!=record.end();it++){
        if(it->second>ansIt->second) ansIt = it;
    }
    cout<<ansIt->first<<endl;
}
