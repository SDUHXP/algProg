#include <cstdio>
#include <map>
#include <set>
#include <functional>
using namespace std;
const int maxN = 1010;
int father[maxN],hobby[maxN];
int findRoot(int node){
    int root = node;
    while(father[root]!=root){
        root = father[root];
    }
    while(father[node]!=root){
        int temp = father[node];
        father[node] = root;
        node = temp;
    }
    return root;
}
void unite(int a,int b){
    int ra = findRoot(a);
    int rb = findRoot(b);
    father[rb] = ra;
    return;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++) father[i] = i;
    for(int i=1;i<=N;i++){
        int K; scanf("%d:",&K);
        for(int j=0;j<K;j++){
            int h; scanf("%d",&h);
            if(hobby[h]==0) hobby[h] = i;
            else unite(i,hobby[h]);
        }
    }
    map<int,int>res;
    for(int i=1;i<=N;i++)   res[findRoot(i)] ++;
    printf("%d\n",res.size());
    set<int,greater<int>> ans;
    for(auto it=res.begin();it!=res.end();it++)     ans.insert(it->second);
    for(auto it=ans.begin();it!=ans.end();it++)     printf("%s%d",(it==ans.begin()?"":" "),*it);
    return 0;
}


#ifdef USE_CORRECT_ANS

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int s[1001];
void Union(int root1,int root2)
{
	if(s[root1]<s[root2]){
		s[root1] += s[root2];
		s[root2] = root1;
	}
	else{
		s[root2] += s[root1];
		s[root1] = root2;
	}
}
int Find(int X)
{
	if(s[X]<0) return X;
	else return s[X] = Find(s[X]);
}
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	fill(s,s+1001,-1);
	int n,k,root1,root2,h;
	int hobby[1001];
	fill(hobby,hobby+1001,0);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d:",&k);
		for(int j=0; j<k; j++){
			scanf("%d",&h);
			if(hobby[h]==0){
				hobby[h] = i;
			}
			else{
				root1 = Find(hobby[h]);
				root2 = Find(i);
                if(root1!=root2)
				    Union(root1,root2);
			}
		}
	}
	vector<int> v;
	for(int i=1; i<=n; i++){
		if(s[i]<=-1){
			v.push_back(-s[i]);
		}
	}
	sort(v.begin(),v.end(),cmp);
	printf("%d\n",v.size());
	for(int i=0; i<v.size(); i++){
		printf("%d",v[i]);
		if(i!=v.size()-1) printf(" ");
		else printf("\n");
	}
	return 0;
}

#endif // CORRECT
