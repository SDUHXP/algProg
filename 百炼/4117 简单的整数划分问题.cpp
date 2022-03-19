//recursion
#include <cstdio>
using namespace std;
//this function calculate the sum of permutation to comprise N,using integer [1,M]
int calCnt(int N,int M){   
	if(N==0) return 1;    //N=0 means a permutation has been got
	if(M==0) return 0;   //no number to be choosen, while the target has not been reached
	if(N>=M) return calCnt(N-M,M) + calCnt(N,M-1);  //condition N>=M,not N>M. becase if N=M, M could be used
	else return calCnt(N,M-1);
}
int main(){
	int N;
	while(EOF!=scanf("%d",&N)){  //if get nothing scanf will return EOF,not 0; 
	int ans = calCnt(N,N);
	printf("%d\n",ans);		
	}
}

#if 0
//dynamic programming 
#include <cstdio>
using namespace std;
int cnt[60][60];
int main(){
	for(int i=0;i<60;i++) cnt[i][0] = 0;
	for(int j=0;j<60;j++) cnt[0][j] = 1;
	for(int i=1;i<60;i++)
		for(int j=1;j<60;j++){
			if(i>=j) cnt[i][j] = cnt[i-j][j] + cnt[i][j-1];
			else cnt[i][j] = cnt[i][j-1];
		}
	int N; 
	while(scanf("%d",&N)!=EOF)
	printf("%d\n",cnt[N][N]);
}
#endif

#if 0
//dynamic programming in recrusion model
#include <cstdio>
#include <cstring>
using namespace std;
int cnt[60][60];
int calCnt(int N,int M){   
	if(cnt[N][M]!=-1) return cnt[N][M];
	if(N>=M)  cnt[N][M] = calCnt(N-M,M) + calCnt(N,M-1);  //condition N>=M,not N>M. becase if N=M, M could be used
	else  cnt[N][M] = calCnt(N,M-1);
	return cnt[N][M];
}
int main(){
	memset(cnt,255,sizeof(cnt));
	for(int i=0;i<60;i++) cnt[i][0] = 0;
	for(int j=0;j<60;j++) cnt[0][j] = 1;
	int N;
	while(EOF!=scanf("%d",&N)){
	int ans = calCnt(N,N);
	printf("%d\n",ans);		
	}
}

#endif