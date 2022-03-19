#include <cstdio>
#include <cstring>
using namespace std;
const int maxN  = 1001;
int cnt[maxN],arr[maxN];
void update(int i,int n,int val){
	while(i<=n){
		cnt [i] += val;
		i += i&(-i);
	}
	return;
}
int getSum(int i,int n){
	int sum  = 0;
	while(i>0){
		sum += cnt[i];
		i -= i&(-i);	
	}
	return sum;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int sum = 0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			update(arr[i],n,1);
			sum += i - getSum(arr[i],n);
		}
		printf("%d\n",sum);
	}
}