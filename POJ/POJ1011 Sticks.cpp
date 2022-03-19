#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
using namespace std;
vector<int>sticks;
bool used[70];
 //means R sticks remained and the current stick remain M unit to compose the target L
bool dfs(int R,int M,int L);   
int main(){
	while(1){
		int R; scanf("%d",&R);	
		if(R==0) break;
		sticks.clear();
		sticks.resize(R);
		for(int i=0;i<R;i++)	scanf("%d",&sticks[i]);
		sort(sticks.begin(),sticks.end(),greater<int>());
		int totalLen = accumulate(sticks.begin(),sticks.end(),0);
		int L;
		for(L=sticks[0];L<=totalLen/2;L++){
			memset(used,0,sizeof(used));
			if(totalLen%L) continue;
			if(dfs(R,L,L)) break;
		}
		if(L>totalLen/2) printf("%d\n",totalLen);
		else printf("%d\n",L);
	}
}
//a solution which is simple but with great time complexity
#if 0
bool dfs(int R,int M,int L){  //R
	if(R==0&&M==0) return true;   //if all sticks used and all stick doesn't need any more height
	if(M==0) M = L;
	for(int i=0;i<sticks.size();i++)
		if(!used[i]&&sticks[i]<=M){
			used[i] = true;
			if(dfs(R-1,M-sticks[i],L)) return true;
			used[i] = false;
		}
	return false;	
}
#endif
//a more efficient method using pruning
#if 1
int latestId;
bool dfs(int R,int M,int L){
	if(R==0&&M==0) return true;  //task is finished
	if(M==0) M = L;		//begin to assemble a new baton
	int beg =0;
	if(M!=L) beg = latestId + 1;   //the sticks must be used in decrease order
	for(int i=beg;i<sticks.size();i++)
		if(!used[i]&&sticks[i]<=M){		//sticks[i]<=M is necessary, or this recursion will not meet iss ending
			//pruning operation, if a length has been tried ,don't try it in this place again
			if(i&&!used[i-1]&&sticks[i-1]==sticks[i])	continue;	
			used[i] = true;
			latestId = i;
			if(dfs(R-1,M-sticks[i],L))	return true;
			used[i] = false;
			//pruning operation, if the first stick and the last can't assemble a baton, return false and return it's caller
			if(M==L||sticks[i]==M) return false;
		}
	return false;	
}

#endif