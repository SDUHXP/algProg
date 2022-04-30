#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
struct richer{
    char name[10];
    int age,worth;
    bool operator <(const richer& oth){
        if(worth!=oth.worth) return worth>oth.worth;
        else if(age!=oth.age) return age<oth.age;
        else return strcmp(name,oth.name)<0;
    }
}forbes[maxN];
int main(){
    int N,K; scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%s%d%d",forbes[i].name,&forbes[i].age,&forbes[i].worth);
    sort(forbes,forbes+N);
    for(int k=1;k<=K;k++){
        int M,minAge,maxAge; scanf("%d%d%d",&M,&minAge,&maxAge);
        printf("Case #%d:\n",k);
        int cnt = 1;
        for(int i=0;i<N && cnt<=M;i++)
            if(forbes[i].age>=minAge && forbes[i].age<=maxAge){
                printf("%s %d %d\n",forbes[i].name,forbes[i].age,forbes[i].worth);
                cnt ++;
            }
        if(cnt==1) printf("None\n");
    }
    return 0;

}
