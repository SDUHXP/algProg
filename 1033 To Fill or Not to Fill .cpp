#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN = 505;
const int inf = 0x3fffffff;
vector<pair<float,float>>station;
int main(){
    float C,D,A; int N; scanf("%f%f%f%d",&C,&D,&A,&N);
    for(int i=0;i<N;i++){
        float price; int pos;
        scanf("%f%d",&price,&pos);
        station.push_back(make_pair(pos,price));
    }
    float range = C*A;
    station.push_back(make_pair(D,0));
    sort(station.begin(),station.end(),[](pair<float,float>&a,pair<float,float>&b){return a.first<b.first;});
    int idx = 0,cur = 0;        //current idx of station index;
    float remain = 0; //range can reach using remaining petrol
    float cost = 0;
    while (cur!=station.size()-1){   //while not arrive destination
        if(station[cur+1].first-station[cur].first>range) break;
        int  minIdx = idx = cur+1;
        while(idx != station.size() && station[idx].first<=station[cur].first+range){
            if(station[idx].second<station[minIdx].second){
                minIdx = idx;
            }
            idx ++;
        }
        //if the cheapest gas station in range cheaper than current,reserve capacity to reach
        if(station[minIdx].second<station[cur].second){
            int flag = cur + 1;
            while(flag != station.size() && station[flag].second>station[cur].second) flag ++;
            cost += (station[flag].first-station[cur].first- remain)/A*station[cur].second;
            remain = 0;   //range of petrol when reach next target
            cur = flag;
        }
        else{
            cost += (C-remain/A)*station[cur].second;
            remain = range - (station[minIdx].first-station[cur].first);
            cur = minIdx;
        }
    }
    if(cur==station.size()-1) printf("%.2f\n",cost);
    else printf("The maximum travel distance = %.2f\n",station[cur].first+range);
    return 0;
}
