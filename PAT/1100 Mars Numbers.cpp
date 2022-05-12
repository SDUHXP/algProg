#include <bits/stdc++.h>
char lower[14][10] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char higher[14][10] = {"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
using namespace std;
int main(){
    int N; scanf("%d%*c",&N);
    string str;
    for(int i=0;i<N;i++){
        getline(cin,str);
        if(isdigit(str[0])==true){
            string res; int val = stoi(str);
            int l = val%13; int h = val/13;
            if(h!=0 && l!=0) {res += higher[h]; res += " "; res += lower[l];}
            else if(h!=0) res += higher[h];
            else res += lower[l];
            cout<<res<<endl;
        }
        else{
            int ans = 0;
            int delPos = str.find(' ');
            if(delPos!=-1){
                string temp = str.substr(0,delPos);
                for(int i=1;i<13;i++)
                    if(strcmp(temp.c_str(),higher[i])==0)  ans += 13*i;
                str.erase(0,delPos+1);
            }
            for(int i=0;i<13;i++)
                if(strcmp(str.c_str(),lower[i])==0)  ans += i;
            for(int i=0;i<13;i++)
                if(strcmp(str.c_str(),higher[i])==0)  ans += 13*i;
            cout<<ans<<endl;
        }
    }
    return 0;
}
