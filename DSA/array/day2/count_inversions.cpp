#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
///Solution: https://www.youtube.com/watch?v=kQ1mJlwW-c0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=10
/// Concepts: 0) Naive Method (T(n): O(n^2)), S(n) : O(1)
///           1) Modified merge Sort (T(n): O(nlogn)), S(n) : O(n)
///           2) Self Balance BST, i.e. AVL (T(n): O(nlogn)), S(n) : O(1)
///           3) Using C++ Set(as it is implemented using Self Balance BST), In Worst case O(n^2)), S(n) : O(n)
///           4) Using BIT (Binary Indexed Tree) Refer to: https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/ [Time and Space is same as above]?

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef long long int ll;
ll merge(ll arr[], ll low, ll mid, ll high){
  if(high<low) return 0;
  ll cnt = 0;
  ll N = high-low+1;
  ll tempArr[N];
  ll i = low, j = mid+1, k = 0;
  while(i < mid+1 && j <= high){

    if(arr[i] > arr[j]){
      cnt += mid-i+1;
      tempArr[k] = arr[j];
      j++; k++;
    }
    else if(arr[i] <= arr[j]){
      tempArr[k] = arr[i];
      i++; k++;
    }
  }

  while (i < mid+1){
      tempArr[k] = arr[i];
      i++; k++;
  }
  
  while (j <= high){
      tempArr[k] = arr[j];
      j++; k++;
  }
  for(i = low, k = 0; i <= high; i++, k++){
    arr[i] = tempArr[k];
  }
  // cout<<" <- "<<low<<" - "<<mid<<" - "<<high<<" -> Merge: ";
  // for(i = low; i <= high;i++){
  //   cout<<arr[i]<<" ";
  // } 
  // cout<<endl;
  return cnt;
}
ll mergeSort(ll arr[], ll low, ll high){
  if(low >= high) return 0;
  ll mid = (high-low)/2 + low;
  
  ll leftInvCnt = mergeSort(arr, low, mid);
  // cout<<" <- "<<low<<" - "<<mid<<" - "<<high<<" -> L: "<<leftInvCnt<<"\n";
  ll rightInvCnt = mergeSort(arr, mid+1, high);
  // cout<<" <- "<<low<<" - "<<mid<<" - "<<high<<" -> R: "<<rightInvCnt<<"\n";
  ll mergeInvCnt = merge(arr, low, mid, high);
  // cout<<" <- "<<low<<" - "<<mid<<" - "<<high<<" -> M: "<<mergeInvCnt<<"\n";
  return (ll)(leftInvCnt + rightInvCnt + mergeInvCnt);
}

ll inversionCount(ll arr[], ll N){
  return mergeSort(arr, 0, N-1);
}

int main(){
  ll n = 1;
  cin>>n;
  ll nums[n];

  for(ll i = 0; i< n; i++){
    cin>>nums[i];
  }
  cout<<inversionCount(nums, n)<<endl;
  // look(nums);
  return 0;
}