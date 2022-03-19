#include <cstdio>
#include <cstring>
#include <algorithm>
char map[26] = "2223334445556667777888999";
using namespace std;
char rcd[100001][10];
void stdizeToTel(int id,char *str){
	int j=0,k=0;
	int len = strlen(str);
	while(k<=7&&j<len){
		if(k==3){
			rcd[id][k] = '-';
			k++;
			continue;
		} 	
		if(str[j]=='-'){
			j++;
			continue;
		}	
		else if(str[j]>='A'&&str[j]<='Z') rcd[id][k] = map[str[j]-'A'];
		else rcd[id][k] = str[j];
		k++;
		j++;
	}
	rcd[id][k] = '\0';
}
int main(){
	int N; scanf("%d",&N);
	char str[60];		// alloc 20 will cause runtime error
	for(int i=0;i<N;i++){
		scanf("%s",str);
		stdizeToTel(i,str);
	}
	char *pRcd[N];
	for(int i=0;i<N;i++) pRcd[i] = rcd[i];
	sort(pRcd,pRcd+N,[](char* s1,char* s2){return strcmp(s1,s2)<0;});
	//for(int i=0;i<N;i++) printf("%s\n",pRcd[i]);
	bool flag = false;   //flag to imply whether 
	for(int i=0;i<N;){
		int j = i+1;
		while(j<N&&strcmp(pRcd[j],pRcd[i])==0) j++;
		if(j-i>1){
			printf("%s %d\n",pRcd[i],j-i);	
			flag = true;
		}
		i = j; 
	}
	if(!flag) printf("No duplicates.\n");
}