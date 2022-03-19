#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<double,double>>station;
int main(){
    double C,D,A; int N;
    scanf("%lf%lf%lf%d",&C,&D,&A,&N);
    for(int i=0;i<N;i++){
        double price,pos;
        scanf("%lf%lf",&price,&pos);
        station.push_back(make_pair(pos,price));
    }
    double range = C*A;
    station.push_back(make_pair(D,0));
    sort(station.begin(),station.end());
    if(station[0].first){
        printf("The maximum travel distance = 0.00\0");
        return 0;
    }
    int idx,cur = 0;        //current idx of station index;
    double remain = 0,cost = 0; //range can reach using remaining petrol, and total cost
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
            cur = flag;
            remain = 0;   //range of petrol when reach next target
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

