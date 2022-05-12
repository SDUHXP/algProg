#include <bits/stdc++.h>
char marDig[26][10] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec",
                            "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
using namespace std;
int main(){
    int N; scanf("%d%*c",&N);
    char str[100];
    for(int i=0;i<N;i++){
       // gets(str);
        scanf("%[^\n]%*c",str);
        if(isdigit(str[0])==true){
            string res; int val = atoi(str);
            int l = val%13; int h = val/13;
            if(h!=0 && l!=0) {res += marDig[h+12]; res += " "; res += marDig[l];}
            else if(h!=0) res += marDig[h+12];
            else res += marDig[l];
            cout<<res<<endl;
        }
        else{
            int ans = 0;  char *ptr;
            ptr = strtok(str," ");
            while(ptr!=NULL){
                for(int i=0;i<25;i++)
                    if(strcmp(ptr,marDig[i])==0) ans += i>12?(i-12)*13:i;
                ptr = strtok(NULL," ");
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
