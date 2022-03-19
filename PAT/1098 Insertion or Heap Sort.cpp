#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>org,mediacy;
void prtVec(vector<int>vec){
    for(int i=0;i<vec.size();i++) printf("%d%s",vec[i],i==vec.size()-1?"\n":" ");
    return;
}
void downAdjust(vector<int>&vec,int cur,int high){
    int ch = 2*cur +1;
    while(ch<=high){
        if(ch<high && vec[ch+1]>vec[ch]) ch ++;
        if(vec[cur]<vec[ch]) swap(vec[cur],vec[ch]);
        cur = ch;
        ch = cur*2 +1;
    }
    return;
}
int main(){
    int N; scanf("%d",&N);
    org.resize(N);  mediacy.resize(N);
    for(int i=0;i<N;i++)  scanf("%d",&org[i]);
    for(int i=0;i<N;i++)  scanf("%d",&mediacy[i]);
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
        sort(org.begin(),org.begin()+pos);
        prtVec(org);
    }
    else{
        printf("Heap Sort\n");
        for(int i=(org.size()-2)/2;i>=0;i--)  downAdjust(org,i,org.size()-1);
        bool flag = false;
        for(int i=org.size()-1;i>0;i--){
            swap(org[0],org[i]);
            downAdjust(org,0,i-1);
            if(flag==true) break;
            if(org==mediacy) flag = true;
        }
        prtVec(org);
    }
    return 0;
}
