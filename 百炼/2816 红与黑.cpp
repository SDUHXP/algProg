//this problem can be translated to get the maximum connected graph
//this problem contain some implied term, move direction only inclue up,down,left,right; 
//a board can be traveled more than once
#include <cstdio>
using namespace std;
char board[25][25];
int calCnt(int i,int j,int m,int n);  //black board can be reached from (i,j)
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)&&n&&m){
	//read a line once instead of reading char by char。since its result may change if extra space exist in each line
		for(int i=0;i<m;i++)	scanf("%s",board[i]);  
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(board[i][j]=='@') printf("%d\n",calCnt(i,j,m,n));
	}
}
int calCnt(int i,int j,int m,int n){
	if(i<0||i>=m||j<0||j>=n)  return 0;   //if outof board no black can be reached
	if(board[i][j]=='#') return 0;  //(i,j) can't be placed, so no black can be reached
	board[i][j] = '#';
	return 1+calCnt(i-1,j,m,n)+calCnt(i+1,j,m,n)+calCnt(i,j-1,m,n)+calCnt(i,j+1,m,n);
}