#include <cstdio>
using namespace std;
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int N; scanf("%d",&N);
	int mon1,day1,mon2,day2,num;
	while(N--){
		scanf("%d%d%d%d%d",&mon1,&day1,&num,&mon2,&day2);
		int cnt = day2 - day1;
		for(int m=mon1;m<mon2;m++) cnt += month[m];
		while(cnt--) num *= 2;
		printf("%d\n",num);
	}
}