//map 1-n in range [1,13],   f(i) = 1 + (i-1)%13;  
#include <cstdio>
#include <cstring>
using namespace std;
const int maxLen = 10;
//using replace function in vscode can add quotations to word in bracket fast, needing a little knowledge of regular expression 
char haabMon[19][maxLen] = {"pop", "no", "zip","zotz","tzec","xul","yoxkin","mol","chen",
								"yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char TzoDay[20][maxLen] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", 	
							"muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};							
int main(){
	int N; scanf("%d",&N);
	printf("%d\n",N);
	while(N--){
		int day,month,year;
		char monName[maxLen];
		scanf("%d.%s%d",&day,monName,&year);
		month = 0;
		while(strcmp(monName,haabMon[month]))  month++;
		int days = day + month*20 + year*365;   //be careful days is counted from 0
		printf("%d %s %d\n",1+days%13,TzoDay[days%20],days/260);
	}
}