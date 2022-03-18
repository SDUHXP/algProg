#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>origin,mediacy,orgCopy;
void prtVec(vector<int>&vec){
    for(int i=0;i<vec.size();i++)   printf("%s%d",(i==0?"":" "),vec[i]);
    cout<<endl;         return;
}
int main(){
    int N; scanf("%d",&N);
    origin.resize(N);   mediacy.resize(N);
    for(int i=0;i<N;i++) scanf("%d",&origin[i]);
    for(int i=0;i<N;i++) scanf("%d",&mediacy[i]);
    orgCopy = origin;
    //simulate insertion sort
    for(int i=1;i<=origin.size();i++){
        sort(origin.begin(),origin.begin()+i);
        if(i>1 && origin==mediacy){
            printf("Insertion Sort\n");
            sort(origin.begin(),origin.begin()+i+1);
            prtVec(origin);
            return 0;
        }
    }
    //simulate merge sort
    printf("Merge Sort\n");
    int step = 2;
    bool flag = false;
    while(step<=N){
        for(int i=1;i*step<=N;i++)
        sort(orgCopy.begin()+(i-1)*step,orgCopy.begin()+min(i*step,N));
        if(flag==true)  {prtVec(orgCopy); return 0;}
        if(orgCopy==mediacy)    flag = true;
        step *= 2;
    }
    return 0;
}
