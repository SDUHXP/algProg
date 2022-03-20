#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    string str1,str2; cin>>str1>>str2;
    map<char,int>map1,map2;
    for(int i=0;i<str1.size();i++) map1[str1[i]]++;
    for(int i=0;i<str2.size();i++) map2[str2[i]]++;
    int miss = 0;
    for(auto it=map2.begin();it!=map2.end();it++){
        char ch = it->first;
        if(it->second>map1[ch]){
            miss += it->second - map1[ch];
        }

    }
    if(miss) printf("No %d\n",miss);
    else printf("Yes %d\n",str1.size()-str2.size());



}
