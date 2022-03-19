#include <cstdio>
#include <cstring>
using namespace std;
int b2Dec(char* str,int b){	//convert a str based b, to decimal number
	int len = strlen(str);
	int res = 0;
	for(int i=0;i<len;i++){
		if(str[i]-'0'>=b) return -1;
		res *= b;
		res += str[i]-'0';
	}
	return res;
}
int main(){
	char p[10],q[10],r[10];
	scanf("%s%s%s",&p,&q,&r);
	int b;
	for(b=2;b<=16;b++){
		int decP = b2Dec(p,b);
		int decQ = b2Dec(q,b);
		int decR = b2Dec(r,b);
		if(decP==-1||decQ==-1||decR==-1) continue;
		if(decP*decQ==decR) break;
	}
	if(b<=16) printf("%d\n",b);
	else printf("0\n");
	
}