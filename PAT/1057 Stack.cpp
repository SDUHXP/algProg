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
