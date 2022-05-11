#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int expPos = str.find('E');
    int exp = stoi(str.substr(expPos+1));
    str.erase(expPos);

    if(exp>0){
        int tarPos = 2+exp;
        str.erase(2,1);
        if(tarPos>str.size()) str.append(tarPos-str.size(),'0');
        if(tarPos<str.size())  str.insert(tarPos,1,'.');
    }
    else if(exp<0){
        str.erase(2,1);
        str.insert(1,-exp,'0');
        str.insert(2,1,'.');

    }
    if(str[0]=='+') str.erase(0,1);
    cout<<str<<endl;
    return 0;
}
