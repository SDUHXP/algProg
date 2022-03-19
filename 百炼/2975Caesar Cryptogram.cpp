#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
void decode(char* str){
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(isupper(str[i])){
			int incr = str[i] - 'A';
			int newIncr = (incr+21)%26;
			str[i] = 'A'+newIncr;
		}
	}
	return;
}
int main(){
	char str[250];
	gets(str);
	while(strcmp(str,"START")==0){
		gets(str);
		decode(str);
		puts(str);
		gets(str);
		gets(str);
	}
	return 0;
}
