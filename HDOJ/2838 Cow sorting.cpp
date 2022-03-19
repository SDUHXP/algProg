#include <cstdio>
#include <cstring>
using namespace std;
const int maxN  = 100001;
struct cow{
	int cnt;	//the num of cows has lower grumpness 
	long long cost; //the time needed to make row sorted
}cows[maxN];
void update(int i,int cnt,int cost){
	while(i<maxN){
		cows[i].cnt += cnt;		//cows with lower grumpness range before
		cows[i].cost += cost;	//grumpnes accounted till i
		i += i&(-i);
	}
	return;
}								
int getSum(int i,int &cnt,long long &cost){
	cnt = cost = 0;
	while(i>0){
		cnt += cows[i].cnt;
		cost += cows[i].cost;
		i -= i&(-i);	
	}
	return cost;
}
int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		long long cost = 0;
		int grump;
		memset(cows,0,sizeof(cows));
		for(int i=1;i<=N;i++){
			scanf("%d",&grump);
			update(grump,1,grump);
			int cnt1,cnt2;
			long long cost1,cost2;
			cnt1 = cost1 = cnt2 = cost2 = 0;
			getSum(grump,cnt1,cost1);
			getSum(maxN-1,cnt2,cost2);
			//be care about overflow
			cost += (long long)(i-cnt1)*grump + (cost2-cost1);	
			
		}
		printf("%I64d\n",cost);
	}
}