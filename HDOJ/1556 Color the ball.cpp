#include <cstdio>
#include <cstring>
using namespace std;
const int maxN = 100001;
int arr[maxN],cnt[maxN];
void update(int i,int N,int val){
	while(i<=N){
		cnt[i] += val;
		i += i&(-i);
	}
	return;
}
int calSum(int i){
	int sum = 0;
	while(i>0){
		sum += cnt[i];
		i -= i&(-i);
	}
	return sum;
}
int main(){
	int N,beg,end; 
	while(scanf("%d",&N)!=EOF && N){
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=N;i++){
			scanf("%d%d",&beg,&end);
			update(beg,N,1);
			update(end+1,N,-1);
		}
		for(int i=1;i<=N;i++)
			printf("%d%c",calSum(i),i==N?'\n':' ');
	}
}