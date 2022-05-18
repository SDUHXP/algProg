#include <bits/stdc++.h>
#include <regex>
using namespace std;

bool isNumber(string str){
    regex pattern ("-?[0-9]+(.[0-9]+)?");
    if(regex_match(str,pattern)) return true;
    else return false;
}

bool isLegal(string str){
    if(isNumber(str)==false) return false;
    int pos = str.find('.');
    if(pos!=-1&&str.length()-pos>3) return false;

    double val = stod(str);
    if(val<-1000||val>1000) return false;
    return true;
}

int main(){
    int N; scanf("%d",&N);
    double sum = 0; int cnt = 0;
    for(int i=0;i<N;i++){
        string str; cin>>str;
        if(isLegal(str)){
            sum += stod(str);
            cnt ++;
        }
        else printf("ERROR: %s is not a legal number\n",str.c_str());
    }
    if(cnt==0) printf("The average of 0 numbers is Undefined\n");
    else printf("The average of %d number%s is %.2f\n",cnt,cnt==1?"":"s",sum/cnt);

}
