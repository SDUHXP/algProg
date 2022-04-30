#include <bits/stdc++.h>
using namespace std;
struct stu{
    char name[15];
    char id[15];
    char gender;
    int score;
    stu():score(-1){}
}minMale,maxFemale,tempStu;
int main(){
    int N;  scanf("%d",&N);
    minMale.score = 101;
    for(int i=0;i<N;i++){
        scanf("%s %c%s%d",tempStu.name,&tempStu.gender,tempStu.id,&tempStu.score);
        if(tempStu.gender=='M'&& tempStu.score<minMale.score) minMale = tempStu;
        else if(tempStu.gender=='F' && tempStu.score>maxFemale.score) maxFemale = tempStu;
    }
    if(maxFemale.score!=-1) printf("%s %s\n",maxFemale.name,maxFemale.id);
    else printf("Absent\n");
    if(minMale.score!=101) printf("%s %s\n",minMale.name,minMale.id);
    else printf("Absent\n");

    if(minMale.score!=101 && maxFemale.score!=-1) printf("%d\n",maxFemale.score-minMale.score);
    else printf("NA\n");
    return 0;

}
