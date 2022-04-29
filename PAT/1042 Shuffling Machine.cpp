//method to map number in [1,N] ; for each i,, i->(i-1)%N+1;
#include <bits/stdc++.h>
using namespace std;
const int cardNum = 54;
int perOrd[cardNum+1],curOrd[cardNum+1],nextOrd[cardNum+1];
map<int,string>strMap;
void initMap(){
    int cardVal = 13;
    int ch[5] = {'S','H','C','D','J'};
    for(int i=1;i<=cardNum;i++){
      strMap[i] = ch[(i-1)/cardVal];
      strMap[i] += to_string((i-1)%cardVal+1);
    }
    return;
}
int main(){
    initMap();
    int K; scanf("%d",&K);
    for(int i=1;i<=cardNum;i++) scanf("%d",&perOrd[i]);
    for(int i=1;i<=cardNum;i++) curOrd[i] = i;
    while(K--){
        for(int i=1;i<=cardNum;i++)  nextOrd[perOrd[i]] = curOrd[i];
        for(int i=1;i<=cardNum;i++)  curOrd[i] = nextOrd[i];
    }
    for(int i=1;i<=cardNum;i++)
        printf("%s%s",i==1?"":" ",strMap[curOrd[i]].c_str());
    return 0;
}
