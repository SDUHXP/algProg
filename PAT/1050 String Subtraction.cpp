#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    map<char,int>map2;
    for(int i=0;i<str2.size();i++) map2[str2[i]]++;
    for(int i=0;i<str1.size();i++)
        if(map2[str1[i]]==0) printf("%c",str1[i]);
    return 0;
}
