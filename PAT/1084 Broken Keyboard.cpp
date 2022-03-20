#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    string str1,str2;   cin>>str1>>str2;
    transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    transform(str2.begin(),str2.end(),str2.begin(),::toupper);
    map<char,int>map1,map2;
    for(int i=0;i<str2.size();i++) map2[str2[i]]++;
    for(int i=0;i<str1.size();i++)
    if(map1[str1[i]]==0){
        if(map2[str1[i]]==0) printf("%c",str1[i]);
        map1[str1[i]] ++;
    }
    return 0;
}
