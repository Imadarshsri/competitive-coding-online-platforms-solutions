#include<bits/stdc++.h>
using namespace std;
int main(){
    uint64_t n=1,x = 0;
    int k;
    cin>>k;
    queue< uint64_t> q;
    
    set <uint64_t> s;
    for(int i=1;i<10;i++){
        q.push(i);
    }
    uint64_t i;
    for(i=0;i<k;i++){
        x = q.front();
        if(x >= 4000000000) break;
        int lst =x%10;
        if(lst != 0){
            q.push((x*10 + (lst -1)));
        }
        q.push((x*10 + (lst)));
        if(lst != 9){
            q.push((x*10 + (lst + 1)));
        }
        q.pop();
    }
    cout<<x;
    return 0;
}