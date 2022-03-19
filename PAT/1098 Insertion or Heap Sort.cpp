#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>org,mediacy,op;
void prtVec(vector<int>vec){
    for(int i=0;i<vec.size();i++) printf("%d%s",vec[i],i==vec.size()-1?"\n":" ");
    return;
}
int main(){
    int N; scanf("%d",&N);
    org.resize(N);  mediacy.resize(N);
    for(int i=0;i<N;i++)  scanf("%d",&org[i]);
    for(int i=0;i<N;i++)  scanf("%d",&mediacy[i]);
    op = org;
    int pos = 0;  bool flag = true;
    for(int i=1;i<mediacy.size();i++)
        if(pos ==0 && mediacy[i]<mediacy[i-1]){
            pos = i; flag = true;
        }
        else if(pos && org[i]!=mediacy[i]){
            flag = false; break;
        }
    if(flag){
        printf("Insertion Sort\n");
        sort(op.begin(),op.begin()+pos);
        prtVec(op);
    }
    else{
        printf("Heap Sort\n");

    }


}
