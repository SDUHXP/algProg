#include <cstdio>
#include <cstring>
using namespace std;
//calculate minuate difference between two zone
int minDiff(char* zone1, char* zone2){  
	char zone[32][10]={"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD","AST","ADT","NST",
		"NDT","EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};	
	float hour[32] = {0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8};
	int i,j;
	for(i=0;strcmp(zone[i],zone1);i++);
	for(j=0;strcmp(zone[j],zone2);j++);
	return int((hour[j]-hour[i])*60);   //be careful before compulsory convert, a parenthesis is needed 
}
int main(){
	int N; scanf("%d",&N);
	while(N--){
		int hour,minute;
		hour = minute = 0;
		char time[10];
		scanf("%s",time);
		switch(time[0]){
			case 'n':
				hour = 12;
				break;
			case 'm':
				hour = 0;
				break;
			default:
				sscanf(time,"%d:%d",&hour,&minute);
				scanf("%s",time);
				hour %= 12;   //since 12:xx needs additional processiong
				if(time[0]=='p') hour += 12;
		}
		char zone1[10],zone2[10];
		scanf("%s%s",zone1,zone2);
		int minZone2 = hour*60 + minute + minDiff(zone1,zone2);
		minZone2 = (minZone2+1440)%1440;
		switch(minZone2){
			case 0 :
				printf("midnight\n");
				break;
			case 720 :
				printf("noon\n");
				break;
			default:
				hour = minZone2/60;
				if(hour==0) printf("12:%02d a.m.\n",minZone2%60);
				else if(hour==12) printf("12:%02d p.m.\n",minZone2%60);
				else if(hour<12) printf("%d:%02d a.m.\n",hour,minZone2%60);
				else printf("%d:%02d p.m.\n",hour-12,minZone2%60);
		}
	}
	return 0;
}