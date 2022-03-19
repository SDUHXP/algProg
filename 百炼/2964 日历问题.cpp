#include <cstdio>
using namespace std;
int month[2][12] = {31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
char week[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int year[2] = {365,366};
int type(int year){
	if(year%4==0&&(year%400==0||year%100!=0)) return 1;
	else return 0;
}
int main(){
	int days;
	int y,m;
	while(scanf("%d",&days)&&days!=-1){
		int dayOfWeek = days%7;
		for(y=2000;days>=year[type(y)];y++)	days -= year[type(y)];
		for(m=0;days>=month[type(y)][m];m++) days -= month[type(y)][m];
		printf("%d-%02d-%02d %s\n",y,m+1,days+1,week[dayOfWeek]);
	}
}