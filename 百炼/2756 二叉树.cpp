//theory of this problem, parent of a node in complete binary tree is n/2;
#include <cstdio>
using namespace std;
int calCommon(int i,int j);  //calculate the minimal common ancestro
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	int ans = calCommon(x,y);
	printf("%d\n",ans);
}
int calCommon(int x,int y){
	if(x==y) return x;
	else if(x<y) return calCommon(x,y/2);
	else return calCommon(x/2,y);
}