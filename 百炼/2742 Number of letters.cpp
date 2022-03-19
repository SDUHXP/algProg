#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int N; scanf("%d",&N);
	char str[1001];
	while(N--){
		scanf("%s",str);
		int cnt[26] = {0};
		int len = strlen(str);
		for(int i=0;i<len;i++)		cnt[str[i]-'a']++;
		int id,maxCnt;
		id =maxCnt =0;
		for(int i=0;i<26;i++)
			if(cnt[i]>maxCnt){
				id = i;
				maxCnt = cnt[i];
			}
		printf("%c %d\n",'a'+id,maxCnt);
	}
}