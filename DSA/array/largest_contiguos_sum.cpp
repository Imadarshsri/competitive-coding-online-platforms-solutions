#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
// int kadane(int a[], int n){ //kadane's Original algo
    
//     long long int max_so_far = INT_MINw, max_ending_here = 0;
//     for(int i = 0; i< n; i++){
//       max_ending_here += a[i];
//       if(max_so_far < max_ending_here){ 
//           max_so_far = max_ending_here;
//       }
//       if(max_ending_here < 0) max_ending_here = 0;
//     }
//     if(max_so_far < max_ending_here) max_so_far = max_ending_here;
//     return max_so_far;
// }
int maxSubarraySum(int a[], int n){ //similar to kadane's algo 
    
    long long int gsum = INT_MIN, lsum = INT_MIN;
    for(int i = 0; i< n; i++){
        if(gsum < lsum){ 
            gsum = lsum;
        }
        if(a[i] <= lsum + a[i]){
            lsum += a[i];
        }
        else{
            if(gsum < lsum){ 
                gsum = lsum;
            }
            lsum = a[i];
        }
    }
    if(gsum < lsum) gsum = lsum;
    return gsum;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends