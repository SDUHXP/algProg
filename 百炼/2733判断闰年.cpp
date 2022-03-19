#include <cstdio>
using namespace std;
int main(){
	int year;
	scanf("%d",&year);
	if(year%4==0&&(year%100||year%400==0))	printf("Y\n");
	else printf("N\n");
}