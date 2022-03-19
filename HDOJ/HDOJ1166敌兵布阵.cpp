//Ctrl + 箭头，逐词移动光标。
#include <cstdio>
#include <cstring>
using namespace std;
const int maxN = 50001;
int site[maxN],cnt[maxN];
void update(int i,int n,int val){
 	while(i<=n){
 		cnt[i] += val;
 		i +=  i&(-i);
	 }	
	 return;
}
int calSum(int i,int j){
	int sum1,sum2;
	sum1 = sum2 = 0;
	while(i>0){
		sum1 += cnt[i];
		i -= i&(-i);
	}
	while(j>0){
		sum2 += cnt[j];
		j -= j&(-j);
	}
	return sum2 - sum1;
}

int main(){
	int T;
	scanf("%d",&T);
	char oper[20];
	for(int t=1;t<=T;t++){
		int N; 
		scanf("%d",&N);
		memset(site,0,sizeof(site));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=N;i++){
			scanf("%d",&site[i]);
			update(i,N,site[i]);
		}
		printf("Case %d:\n",t);
		while(scanf("%s",oper)&&strcmp(oper,"End")){
			int start,end;
			scanf("%d%d",&start,&end);
			switch(oper[0]){
				case 'Q': 
					printf("%d\n",calSum(start-1,end));
					break;
				case 'A':
					update(start,N,end);
					break;
				case 'S':
					update(start,N,-end);
					break;
			}
		}
	}
	return 0;
}
