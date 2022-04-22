#if 0
//using blocking method
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxL = 100005;
const int block = sqrt(maxL);
int stackArr[maxL];
int table[maxL],interval[block+1];
int main(){
    int N; scanf("%d",&N);
    char op[50];  int curLen = 0;   //current length of stack Array
    for(int i=0;i<N;i++){
        cin>>op;
        if(strcmp(op,"Pop")==0){
            if(curLen==0){
                printf("Invalid\n");
                continue;
            }
            int val = stackArr[curLen-1];
            printf("%d\n",val);
            interval[val/block] --;
            table[val] --;
            curLen--;
        }
        else if(strcmp(op,"PeekMedian")==0){
            if(curLen==0){
                  printf("Invalid\n");
                    continue;
                }
            int median = (curLen+1)/2;
            int idx ,val;
            for(idx=0;idx<=block;idx++){
                if(interval[idx]>=median) break;
                median -= interval[idx];
            }
            for(int i=0;i<block;i++){
                val = idx*block + i;
                if(table[val]>=median) break;
                median -= table[val];
            }
            printf("%d\n",val);
        }
        else{
            int val;    cin>>val;
            stackArr[curLen++] = val;
            table[val]++;
            interval[val/block] ++;   //block size of val increase
        }
    }
    return 0;
}
#else
//using binary indexed tree
#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int maxL = 100005;
stack<int>st;
int Cnt[maxL]; //Cnt[i] stand for sun of value in [1,i]
#define lowBit(i)   ((i)&-(i))
//num of val increase cnt
void update(int val,int cnt){
    for(int i=val;i<maxL;i+=lowBit(i)) Cnt[i] += cnt;
}
//get order of idx ; that is sum of number no greater than idx
int getSum(int idx){
    int ans = 0;
    for(int i=idx;i>0;i-=lowBit(i)) ans += Cnt[i];
    return ans;
}
//get the value has the order
int binSearch(int order){
    int l = 1, r = maxL-1;
    while(l<r){
        int mid = (l+r)/2;
        int cnt = getSum(mid);
        if(cnt<order) l = mid+1;
        else if(cnt>=order) r = mid;
    }
    return l;
}
int main(){
    int N; scanf("%d",&N);
    string op; int val;
    for(int i=0;i<N;i++){
        cin>>op;
        if(op=="Push"){
           cin>>val; st.push(val);
           update(val,1);
        }
        else if (op=="Pop"){
            if(st.size()==0){printf("Invalid\n"); continue;};
            cout<<st.top()<<endl;
            update(st.top(),-1);
            st.pop();
        }
        else{
            if(st.size()==0){printf("Invalid\n"); continue;};
            int order = (st.size()+1)/2;
            int val = binSearch(order);
            cout<<val<<endl;
        }
    }
    return 0;
}


#endif
