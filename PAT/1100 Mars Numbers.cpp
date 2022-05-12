#include <bits/stdc++.h>
char marDig[26][10] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec",
                            "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
using namespace std;
int main(){
    int N; scanf("%d%*c",&N);
    string str;
    for(int i=0;i<N;i++){
        getline(cin,str);
        if(isdigit(str[0])==true){
            string res; int val = stoi(str);
            int l = val%13; int h = val/13;
            if(h!=0 && l!=0) {res += marDig[h+12]; res += " "; res += marDig[l];}
            else if(h!=0) res += marDig[h+12];
            else res += marDig[l];
            cout<<res<<endl;
        }
        else{
            int ans = 0;
            int delPos = str.find(' ');
            if(delPos!=-1){
                string temp = str.substr(0,delPos);
                for(int i=13;i<25;i++)
                    if(strcmp(temp.c_str(),marDig[i])==0)  ans += 13*(i-12);
                str.erase(0,delPos+1);
            }
            for(int i=0;i<25;i++)
                if(strcmp(str.c_str(),marDig[i])==0)  ans += i>12?(i-12)*13:i;
            cout<<ans<<endl;
        }
    }
    return 0;
}
