#include <bits/stdc++.h>
using namespace std;
int main(){
    int res; cin>>res;
    cout<<setfill('0');
    do{
        char tempArr[5]; sprintf(tempArr,"%04d",res);
        sort(tempArr,tempArr+4);
        int minN = atoi(tempArr);
        sort(tempArr,tempArr+4,[](char a,char b){return a>b;});
        int maxN = atoi(tempArr);
        res = maxN - minN;
        cout<<setw(4)<<maxN<<" - "<<setw(4)<<minN<<" = "<<setw(4)<<res<<endl;
    }while(res!=6174 && res!=0);
    return 0;
}
