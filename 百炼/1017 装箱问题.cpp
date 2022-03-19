#include <cstdio>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	int re3[4] = {0,5,3,1};
	while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)){
		if(a||b||c||d||e||f){
			int N = (c+3)/4+d+e+f;		//N stands for the num of box needed
			int re2 = 5*d+re3[c%4];
			if(b>re2) N += (b-re2+8)/9;  //condition  b>re2 is necessary
			int re1 = N*36-b*4-c*9-d*16-e*25-f*36;
			if(a>re1) N += (a-re1+35)/36;   //condition a>re1 is necessary ,
			printf("%d\n",N);
		}
		else break;
	}
}