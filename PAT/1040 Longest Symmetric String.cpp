#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define GETELE(arr,col,i,j)   arr[(i)*(col)+(j)]
int dpSolve(string str){
    int len = str.length();
    bool* dp = new bool[len*len];   //dp[i][j] means if str.substr(i,j-i+1) is symetric
    memset(dp,0,sizeof(dp));
    int ans = 1;
    for(int i=0;i<len;i++){
        GETELE(dp,len,i,i) = true;
        if(i<len-1){
            GETELE(dp,len,i,i+1) = (str[i]==str[i+1]);
            if(GETELE(dp,len,i,i+1)) ans = 2;
        }
    }
    for(int interval=3;interval<=len;interval++)
        for(int i=0;i<=len-interval;i++){
            int j = i+interval-1;
            GETELE(dp,len,i,j) = GETELE(dp,len,i+1,j-1) && (str[i]==str[j]);
           if(GETELE(dp,len,i,j)) ans = interval;
        }
    delete[] dp;
    return ans;
}
int hashSolve(string str){

    return 0;
}
int computeWidth(string str,int left,int right){
    while(left>=0&&right<str.length()){
        if(str[left]!=str[right]) break;
        left --; right++;
    }
    return max(right-left-1,0);
}
int centralExtension(string str){
    //use str[i] as definite central or double centre
    int ans = 0;
    for(int i=0;i<=str.length();i++){
        int cenLen1 = computeWidth(str,i,i);
        int cenLen2 = computeWidth(str,i,i+1);
        ans = max(ans,max(cenLen1,cenLen2));
     }
     return ans;
}

int main(){
    string str;  getline(cin,str);
//    int res = dpSolve(str);
    int res = centralExtension(str);
    cout<<res<<endl;
}
