#include <bits/stdc++.h>
using namespace std;
stack<int>st;
int main(){
    int M,N,K; scanf("%d%d%d",&M,&N,&K);
    while(K--){
        int val;
        bool flag = true;
        st.push(1);
        int next = 2;
        for(int i=0;i<N;i++){
            scanf("%d",&val);
            if(st.top()==val)  st.pop();
            else if(st.top()<val){
                while(next<=val){
                    st.push(next);
                    next ++;
                }
            }
            else if(val<st.top()){
                flag = false;
            }
        }
        if(flag)    cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
