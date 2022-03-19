#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int base[31];
	base[0] = 1;
	for(int i=1;i<31;i++) base[i] = 2*base[i-1]+1;
	char str[32];
	while(scanf("%s",str)){
		if(strcmp(str,"0")==0) break;
		int res = 0;
		int len = strlen(str);
		for(int i=0;i<len;i++) res += (str[i]-'0')*base[len-i-1];
		printf("%d\n",res);
	} 
}