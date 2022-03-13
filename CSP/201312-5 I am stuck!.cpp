#include <iostream>
using namespace std;
const int maxR = 51;
const int maxC = 51;
int R,C;
char graph[maxR][maxC];
bool visit[maxR][maxC];
bool sReach[maxR][maxC];
//dfs from point (i,j)
int dfs(int i,int j,char endChar){
    if(i<1||i>R||j<1||j>C||graph[i][j]=='#') return -1;
    if(visit[i][j]==true) return 0;
    visit[i][j] = true;
    if(graph[i][j]==endChar) return 0;
    else if(graph[i][j]='+'){
        dfs(i,j+1,endChar);
        dfs(i,j-1,endChar);
        dfs(i+1,j,endChar);
        dfs(i-1,j,endChar);
    }
    else if(graph[i][j]=='-'){
        dfs(i,j+1,endChar);
        dfs(i,j-1,endChar);
    }
    else if(graph[i][j]=='|'){
        dfs(i-1,j,endChar);
        dfs(i+1,j,endChar);
    }
    else if(graph[i][j]=='.'){
        dfs(i+1,j,endChar);
    }
}
int main()
{
    scanf("%d%d",&R,&C);
    int si,sj,ti,tj;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++){
          scanf(" %c",&graph[i][j]);
          if(graph[i][j]=='S'){
                si = i;
                sj = j;
          }
          if(graph[i][j]=='S'){
                ti = i;
                tj = j;
          }
        }
    dfs(si,sj,'T');
    memcpy(sReach,visit,sizeof(visit));
    dfs(ti,tj,'S');
    int ans = 0;
    for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++){
        if(sReach[i][j]==true && visit[i][j]==false) ans ++;
    }
    cout<<ans<<endl;
    return 0;
}
