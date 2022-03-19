#include <cstdio>
using namespace std;
int rcd[100][10];
int cnt = 1;
bool flag[10];	//if one column is occupied
bool diag[17];  //record diagnoal (9+i-j)  all map to [2,16]
bool atiDiag[17];   //record if an anti-diagonal has been occupy (i+j)
int mark[10];   //transfer array, record one permutation ,this array is necessary
void permute(int idx){		//idx stands for 
	if(idx>8){
		for(int j=1;j<=8;j++) rcd[cnt][j] = mark[j];    //mark数组中转是必须的，否则会出错
		cnt ++;
		return;
	}
	for(int j=1;j<=8;j++)
		if(!flag[j]&&!diag[9+idx-j]&&!atiDiag[idx+j]){
		//	rcd[cnt][idx] = j;	//this operation will cause error
			mark[idx] = j;
			flag[j] = true;
			diag[9+idx-j] = atiDiag[idx+j] = true;
			permute(idx+1);
			flag[j] = false;
			diag[9+idx-j] = atiDiag[idx+j] = false;
		}
}
int main(){
	int N; scanf("%d",&N);
	permute(1);
	while(N--){
		int b; scanf("%d",&b);	
		for(int j=1;j<=8;j++)	printf("%d",rcd[b][j]);
		printf("\n");
	}	
}