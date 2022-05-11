#include <bits/stdc++.h>
using namespace std;
char week[7][5]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main(){
    string str1,str2; cin>>str1>>str2;
    int day,hour=-1,minute;
    bool flag = false;
    for(int i=0;i<str1.length()&&i<str2.length();i++)
        if(str1[i]==str2[i]){
            if(flag==false&&str1[i]>='A'&&str1[i]<='G'){day = str1[i]-'A'+1;flag=true;}
            else if(flag==true && str1[i]>='A'&&str1[i]<='N') hour = str1[i]-'A'+10;
            else if(flag==true && isdigit(str1[i])) hour = str1[i]-'0';
            else continue;
            if(flag==true && hour!=-1) break;
        }
    cin>>str1>>str2;
    for(int i=0;i<str1.length()&&i<str2.length();i++)
        if(str1[i]==str2[i]&&isalpha(str1[i])){
            minute = i;break;
        }
    printf("%s %02d:%02d",week[day%7],hour,minute);

    return 0;
}
