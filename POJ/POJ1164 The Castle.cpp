//precedence of == is higher than bitwise and &
#include <cstdio>
using namespace std;
const int maxN = 60;
int rooms[maxN][maxN];
int color[maxN][maxN];
int maxArea;
int colorCnt = 0;
void dfs(int r,int c,int &area){
	if(color[r][c]) return;
	color[r][c] = colorCnt;
	area ++;
	if((rooms[r][c]&1)==0) dfs(r,c-1,area);		//15 means there exist wall in four direction
	if((rooms[r][c]&2)==0) dfs(r-1,c,area);		//0 means no wall exist at all
	if((rooms[r][c]&4)==0) dfs(r,c+1,area);
	if((rooms[r][c]&8)==0) dfs(r+1,c,area);
	return;
}
int main(){
	int R,C; scanf("%d%d",&R,&C);
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)  scanf("%d",&rooms[i][j]);
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			if(!color[i][j]){
				int area = 0;
				colorCnt ++;
				dfs(i,j,area);	
				maxArea = (maxArea>area)?maxArea:area;
		}
	printf("%d\n%d\n",colorCnt,maxArea);
}