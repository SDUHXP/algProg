//before writing a program , reading the discription carefully.
//the matrix is N*M instead of M*N;
#include <cstdio>
#include <map>
using namespace std;
int main(){
	int M,N,P; scanf("%d%d%d",&N,&M,&P);
	char line[101];
	map<char,int>rcd;
	for(int i=0;i<N;i++){
		scanf("%s",line);
		for(int j=0;j<M;j++) rcd[line[j]] ++;
	}
	for(int i=0;i<P;i++){
		scanf("%s",line);
		for(int j=0;line[j]!='\0';j++) rcd[line[j]]--;
	}
	map<char,int>::iterator it = rcd.begin();
	for(;it!=rcd.end();it++) 
		while(it->second){
			printf("%c",it->first);	
			it->second --;
		}
	printf("\n");
}
