#include <iostream>
using namespace std;
const int maxR = 51;
const int maxC = 51;
char graph[maxR][maxC];
int main()
{
    int R,C; scanf("%d%d",&R,&C);
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++){
          scanf("%c",&graph[i][j]);
        }


    return 0;
}
