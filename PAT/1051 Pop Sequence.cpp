#include <bits/stdc++.h>
using namespace std;
stack<int>st;
int main(){
    int M,N,K; scanf("%d%d%d",&M,&N,&K);
    while(K--){
        int val,next; bool flag = true;
        next = 1;
        while(st.size()) st.pop();
        for(int i=0;i<N;i++){
            scanf("%d",&val);
            if(flag){
                if(st.size()==0 || st.top()<val){
                    while(next<=val){
                        st.push(next);
                        next ++;
                    }
                }
                if(st.size()>M){
                    flag = false;
                    continue;
                }
                if(st.top()==val)  st.pop();
                else {
                    flag = false;
                }
            }
        }
        if(flag)    cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
