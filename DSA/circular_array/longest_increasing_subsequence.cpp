// #include<bits/stdc++.h>
// // #include<vector>
// // #include<algorithm>

// using namespace std;
// //Macros
// #define endl "\n"
// #define fn(x,n) for(; x < n; x++)
// #define fo(n) for(auto i = 0; i < n; i++)
// #define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define look(v) cout<< #v <<" : "; for(auto x : v) cout<< x << " "; cout<< endl

// typedef uint64_t ui;

// void solve(){
//   ui n = 1, ans = 0;
//   cin>>n;
//   vector<int> v(n);
//   readSeq(v,n);
//   // look(v);
//   v.insert(v.end(), v.begin(), v.end() - 1);
//   // look(v);

//   ui arr[n];
//   for(int j = 0; j < n; j++){
//     memset(arr, 0, sizeof(arr));
//     arr[j] = 1;
//     for(int i = j + 1; i < n + j; i++){
//       if(v[i % n] >= v[(i - 1) % n]) arr[i % n] = arr[(i-1) % n] + 1;
//       else arr[i % n] = arr[(i-1) % n];
//       ans = max(ans, arr[i % n]);
//     }
//   }
//   // look(arr);
//   cout<<ans<<"\n";
// }

// int main(){
//   //fastio

//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
//   int cases=1;
//   //fastscan(cases);
//   scanf("%d",&cases);
//   while(cases--){
//     solve();
//   }
//   return 0;
// }
// C++ implementation to find LIS in circular way 
#include<bits/stdc++.h> 
using namespace std; 

// Utility function to find LIS using Dynamic programming 
int computeLIS(int circBuff[], int start, int end, int n) 
{ 
	int LIS[end-start]; 

	/* Initialize LIS values for all indexes */
	for (int i = start; i < end; i++) 
		LIS[i] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (int i = start + 1; i < end; i++) 

		// Set j on the basis of current window 
		// i.e. first element of the current window 
		for (int j = start; j < i; j++ ) 
			if (circBuff[i] > circBuff[j] && LIS[i] < LIS[j] + 1) 
				LIS[i] = LIS[j] + 1; 

	/* Pick maximum of all LIS values */
	int res = INT_MIN; 
	for (int i = start; i < end; i++) 
		res = max(res, LIS[i]); 

	return res; 
} 

// Function to find Longest Increasing subsequence in 
// Circular manner 
int LICS(int arr[], int n) 
{ 
	// Make a copy of given array by appending same 
	// array elements to itself 
	int circBuff[2 * n]; 
	for (int i = 0; i<n; i++) 
		circBuff[i] = arr[i]; 
	for (int i = n; i < 2*n; i++) 
		circBuff[i] = arr[i-n]; 

	// Perform LIS for each window of size n 
	int res = INT_MIN; 
	for (int i=0; i<n; i++) 
		res = max(computeLIS(circBuff, i, i + n, n), res); 

	return res; 
} 

/* Driver program to test above function */
int main() 
{ 
	int arr[] = { 1, 4, 6, 2, 3 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "Length of LICS is " << LICS( arr, n ); 
	return 0; 
} 
