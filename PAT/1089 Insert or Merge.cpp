#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>origin,mediacy,orgCopy;
void prtVec(vector<int>&vec){
    for(int i=0;i<vec.size();i++)   printf("%d%s",vec[i],(i==vec.size()-1?"\n":" "));
    return;
}
int main(){
    int N; scanf("%d",&N);
    origin.resize(N);   mediacy.resize(N);
    for(int i=0;i<N;i++) scanf("%d",&origin[i]);
    for(int i=0;i<N;i++) scanf("%d",&mediacy[i]);
    orgCopy = origin;
    for(int i=2;i<=origin.size();i++){
        sort(origin.begin(),origin.begin()+i);
        if(origin==mediacy){
            printf("Insertion Sort\n");
            sort(origin.begin(),origin.begin()+i+1);
            prtVec(origin);
            return 0;
        }
    }
    printf("Merge Sort\n");
    int step = 2;
    bool flag = false;
    while(step<=N){
        for(int i=0;i*step<N;i++)       //be careful about range of i
        sort(orgCopy.begin()+i*step,orgCopy.begin()+min((i+1)*step,N));
        if(flag==true)  {prtVec(orgCopy); return 0;}
        if(orgCopy==mediacy)    flag = true;
        step *= 2;
    }
    return 0;
}
