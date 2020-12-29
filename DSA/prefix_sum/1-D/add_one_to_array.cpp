#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases = 1;
	cin>>cases;
	while(cases--){
	    int n = 1, k = 1;
	    cin>>n>>k;
	    int arr[n];
        memset(arr, 0, sizeof(arr)); 
        
	    // for(int i = 0; i < n; i++){
	    //     cout<<arr[i]<<" ";
	    // }
	    while(k--){
	        int x = 0;
	        cin>>x;
	        arr[x - 1] += 1;
	    }
	    for(int i = 1; i < n; i++){
	        arr[i] +=arr[i - 1];
	    }
	    for(int i = 0; i < n; i++){
	        cout<<arr[i]<<" ";
	    }
	}
	return 0;
}