#include <bits/stdc++.h>
using namespace std;
char week[7][5]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main(){
    string str1,str2;
    cin>>str1>>str2;
    int day,hour,minute;
    bool flag = false;
    for(int i=0;i<str1.length()&&i<str2.length();i++)
        if(str1[i]==str2[i]){
            if(flag==false&&isupper(str1[i])){day = str1[i]-'A'+1;flag=true;}
            else if(flag==true && isupper(str1[i])) hour = str1[i]-'A'+10;
            else if(flag==true && isdigit(str1[i])) hour = str1[i]-'0';
            else continue;
        }

    cin>>str1>>str2;
    for(int i=0;i<str1.length()&&i<str2.length();i++)
        if(str1[i]==str2[i]&&isalpha(str1[i])){
            minute = i;break;
        }
    printf("%s %02d:%02d",week[day%7],hour,minute);

    return 0;
}
