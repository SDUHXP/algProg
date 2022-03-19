#include <cstdio>
#include <string.h>
using namespace std;
char strArr[101][101];
//note strrev is not implemented in g++(unix), but implemented in minGw
void mystrrev(char *str){
	int len = strlen(str);
	int j =0;
	char temp;
	while(len-1-j>j){
		temp = str[j];
		str[j] = str[len-1-j];
		str[len-1-j] = temp;
		j++;
	}  
}
int maxSubLen(char* str,int N){
	int len = strlen(str);
	char sub[101],subRev[101];
	int subLen = len;
	while(subLen>0){
		for(int i=0;i<=len-subLen;i++){
			strncpy(sub,str+i,subLen);
			strncpy(subRev,str+i,subLen);
			sub[subLen] = subRev[subLen] = '\0';
			mystrrev(subRev);
			bool flag = true;	//if the maxLen
			for(int j=0;j<N;j++)
				if(strstr(strArr[j],sub)==NULL&&strstr(strArr[j],subRev)==NULL){
					flag = false;
					break;
				}
			if(flag) return subLen;	
		}
		subLen--;
	}
	return subLen;
}
int main(){
	int T; scanf("%d",&T);
	char str[101];
	while(T--){
		int minLen = 101;
		int N; scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%s",strArr[i]);	
			if(strlen(strArr[i])<minLen){
				minLen = strlen(strArr[i]);
				strcpy(str,strArr[i]);
			} 
		}
		int len = maxSubLen(str,N);
		printf("%d\n",len);
	}
}