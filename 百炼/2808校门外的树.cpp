#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
	int L,M; scanf("%d%d",&L,&M);
	vector<pair<int,int>>rcd,res;
	while(M--){
		int b,e; scanf("%d%d",&b,&e);
		rcd.push_back(make_pair(b,e));
	}	
	sort(rcd.begin(),rcd.end());
	for(int i=0;i<rcd.size();i++){
		if(i==0||rcd[i].first>res.back().second) res.push_back(rcd[i]);
		else res.back().second = max(res.back().second,rcd[i].second);
	}
	int cnt = 0;
	for(int i=0;i<res.size();i++) cnt += res[i].second - res[i].first + 1;
	printf("%d\n",L+1-cnt);
}
