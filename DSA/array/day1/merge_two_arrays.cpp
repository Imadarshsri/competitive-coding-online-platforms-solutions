// Merge two sorted array w/o using extraspace

// Problem link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
// Solution: https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4

#include <bits/stdc++.h>
using namespace std;

//Macros
#define endl "\n"
#define fn(x, n) for (; x < n; x++)
#define fo(n) for (auto i = 0; i < n; i++)
typedef uint64_t ui;

void merge(vector<int>& a, vector<int>& b, int n, int m) {
    /*Insertion Sort O(n*m) */
    //int i = 0, j = 0;
    //while(i < n && j < m){
    //    if(a[i] <= b[j]) i++;
    //    else{
    //        swap(a[i], b[j]);
    //        //sort b //Using Insertion Sort
    //        int k = j + 1;
    //        int x = b[j];
    //        while(k < m && b[k] <= x){
    //            b[k-1] = b[k];
    //            k++;
    //        }
    //        b[k-1] = x;
    //        i++;
    //    }
    //}
    
    /* GAP Method O((n+m)log(n+m))*/ 
    
    int i = 0, g = n+m;
    while(g > 1){
        
        // cout<<"\nG->"<<g<<": ";
        g = ceil(g/2.0);
        for(int i = 0, j = g; (i < n || (i - n) < m) && (j < n || (j - n) < m); i++ , j++){
            if(i < n && j < n && a[i] > a[j]){
                swap(a[i], a[j]);
            }
            else if(j >= n &&  i < n && a[i] > b[j - n]){
                swap(a[i], b[j - n]);
            }
            else if(j >= n &&  i >= n && b[i - n] > b[j - n]){
                swap(b[i - n], b[j - n]);
            }
            // else{
            //   cout<<"wr->"<<i<<"-"<<j<<endl;
            // }
        }
        // cout<<"\nG->"<<g<<": ";
        // for(int i = 0; i < n; i++) cout<<a[i]<<" ";
        // for(int i = 0; i < m; i++) cout<<b[i]<<" ";
        
    }
        
}
void solve(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  fo(n) cin >> a[i];
  fo(m) cin >> b[i];
  merge(a,b, n , m);
  fo(n) cout << a[i] << " ";
  fo(m) cout << b[i] << " ";
  cout<<endl;
}

int main(){
  //fastio

  int cases = 1;
  //fastscan(cases);
  scanf("%d", &cases);
  while (cases--)  {
    solve();
  }
  return 0;
}