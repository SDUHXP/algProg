//hints: this problem is different from the classic math problem
//placing M balls in N box,and each box alloc at least one ball
#include <cstdio>
using namespace std;
int calCnt(int M,int N){
	if(M==0||N==1) return 1;  //no apple, all empty; one plate, all apples must place here
	if(M<N) return calCnt(M,M);   //be careful,  condition is M<N not M<=N 
	else return calCnt(M,N-1) + calCnt(M-N,N);   //at least one plate is empty and no empty plate
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int M,N; 
		scanf("%d%d",&M,&N);
		int ans = calCnt(M,N);
		printf("%d\n",ans);
	}
	return 0;
}