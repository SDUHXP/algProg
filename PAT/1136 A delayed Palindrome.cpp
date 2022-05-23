#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str){
    int len = str.length();
    for(int i=0;i<len/2;i++) 
        if(str[i]!=str[len-i-1]) return false;
    return true;
}
string addStr(string str){
    string str1 = str;
    string strRes;
    reverse(str1.begin(),str1.end());
    int residual = 0;
    for(int i=0;i<str.length();i++){
        int sum = str[i]-'0'+str1[i]-'0';
        char ch = (residual + sum)%10 + '0';
        strRes.append(1,ch);
        residual = (residual+sum)/10;
    }
    if(residual!=0) strRes.append(1,residual+'0');
    reverse(strRes.begin(),strRes.end());
    cout<<str<<" + "<<str1<<" = "<<strRes<<endl;
    return strRes;
}
int main(){
    string str; cin>>str;
    int cnt = 0;
    while(cnt<=10 && isPalindrome(str)==false){
        if(cnt<10) str = addStr(str);
        cnt ++;
    }
    if(cnt>10) printf("Not found in 10 iterations.\n");
    else printf("%s is a palindromic number.\n",str.c_str());
    return 0;
}