#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
        string str; cin>>str;
        long long val = stoi(str);
        int pos = str.length()/2;
        string str1 = str.substr(pos);
        int val1 = stoi(str1);
        str.erase(pos);
        int val2 = stoi(str);
        long long product = val1*val2;
        if(product && val%product==0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
