#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		char start[5],dst[5];
		scanf("%s%s",start,dst);
		int dx = abs(dst[0]-start[0]);
		int dy = abs(dst[1]-start[1]);
		if(dx==0&&dy==0) printf("0 0 0 0\n");
		else{
			printf("%d ",dx>dy?dx:dy);		//steps of the king
			printf("%d ",dx&&dy&&dx!=dy?2:1);		//steps of the queen
			printf("%d ",dx&&dy?2:1);  //steps of the rook
			//steps of bishop
			if((dx-dy)%2) printf("Inf\n");
			else printf("%d\n",dx==dy?1:2);
		}
	}
}