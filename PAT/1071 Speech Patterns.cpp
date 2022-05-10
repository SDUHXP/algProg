#include <bits/stdc++.h>
using namespace std;
map<string,int>keyCnt;
//bool isalphaNumerical(char c){return (isalpha(c) || isdigit(c));}
string alphaNum = "abcdefghijklmnopqrstuvwxyz0123456789";
vector<string> maxKey; int maxNum;
int main(){
    string str; getline(cin,str);
    transform(str.begin(),str.end(),str.begin(),::tolower);
    int posSearch = 0;
    while(posSearch!=-1){
        int pos = str.find_first_of(alphaNum,posSearch);
        if(pos==-1) break;
        int posPun = str.find_first_not_of(alphaNum,pos);;
        posSearch = posPun;
        string key;
        if(posPun==-1) key = str.substr(pos);
        else key = str.substr(pos,posPun-pos);
        keyCnt[key]++;
        if(keyCnt[key]>maxNum){
            maxNum = keyCnt[key];
            maxKey.clear();
            maxKey.push_back(key);
        }
        else if(keyCnt[key]==maxNum) maxKey.push_back(key);
    }
    sort(maxKey.begin(),maxKey.end());
    cout<<maxKey[0]<<" "<<maxNum<<endl;


    return 0;
}

