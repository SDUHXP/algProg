#include <cstdio>
void prtCol(int n){
    int h = n/13;
    int l = n%13;
    if(h>9) printf("%c",'A'+h-10);
    else printf("%d",h);
    if(l>9) printf("%c",'A'+l-10);
    else printf("%d",l);
    return;

}
int main ()
{
  printf("#");
  for(int i=0;i<3;i++){
    int n; scanf("%d",&n);
    prtCol(n);
  }
  return 0;
}
