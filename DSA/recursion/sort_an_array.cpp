#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: 
///Solution: 
///Concepts: 

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
//Your solution class
class Solution {
public:
    
    void insert(int arr[],int n, int temp){
        // cout<<"\nInsert "<<n<<": ";
        // for(int i = 0; i< n; i++){
        //   cout<<arr[i]<<" ";
        // }

        if((n == 0) || (arr[n - 1] <= temp)){  // Base Condtition
          arr[n] = temp;
          return;
        }        
        int x = arr[n - 1];  // Induction
        insert(arr, n - 1, temp);  // Hypothesis (on smaller input)
        arr[n] = x;  // Induction
    }
    
    void sort(int arr[],int n){
        // cout<<"\nSort "<<n<<": ";
        // for(int i = 0; i< n; i++){
        //   cout<<arr[i]<<" ";
        // }
        cout<<endl;
        if(n == 0) return;  // Base Condtition
        sort(arr, n - 1); // Hypothesis (on smaller input)
        int x = arr[n - 1];  // Induction
        insert(arr, n - 1, x);  // Induction
    }
    int* sortArray(int nums[],int n) {
        // int n = nums.size();
        sort(nums, n);        
        return nums;
    }
};

int main(){
  int n = 1;
  cin>>n;
  int nums[n];

  for(int i = 0; i< n; i++){
    cin>>nums[i];
  }
  int *ans = Solution().sortArray(nums, n);
  cout<<"\nAns : ";
  for(int i = 0; i< n; i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}