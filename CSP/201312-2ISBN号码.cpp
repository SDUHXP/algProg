#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int len = str.length();
    int sum  = 0;
    int w = 0;
    for(int i=0;i<len-1;i++){
        if(str[i]!='-'){
            sum += (str[i]-'0')*(w+1);
            w++;
        }
    }
    char check = sum%11<10?sum%11+'0':'X';
    if(check==str[len-1]) cout<<"Right"<<endl;
    else{
        str[len-1] = check;
        cout<<str<<endl;
    }
    return 0;
}
