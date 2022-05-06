#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int diff = -1;
    cout<<setfill('0');
    while(diff!=6174 && diff!=0){
        sort(str.begin(),str.end());
        int minN = stoi(str);
        sort(str.begin(),str.end(),[](char a,char b){return a>b;});
        int maxN = stoi(str);
        diff = maxN - minN;

        cout<<setw(4)<<maxN<<" - "<<setw(4)<<minN<<" = "<<setw(4)<<diff<<endl;
        char tempArr[5]; sprintf(tempArr,"%04d",diff);
        str.assign(tempArr);

    }
    return 0;
}
