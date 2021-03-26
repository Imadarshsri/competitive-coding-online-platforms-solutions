#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1#
///Solution: https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19
///Concepts: 1) Recursion Brute : T(n):O(n^2), S(n): O(n)
// 2) ??
// See Josepfus Problem at GFG for k = 2
class Solution {
  public:
  //  1) Recursion Brute : T(n):O(n^2), S(n): O(n)
    int solve(int k, int idx, vector<int> &person){
        if(person.size() == 1){
            return person[0];
        }
        
        idx = (idx + k)% person.size();
        person.erase(person.begin() + idx);
        return solve(k, idx, person);
    }
    int safePos(int n, int k) {
        k--; // to point to kth element itself
        
        vector<int> person(n);
        
        for(int i = 1; i <= n; i++)
            person[i-1] = i;
        
        return solve(k,0, person);
    }
// T(n): O(n), S(N): O(1) ???
  int josephus(int n, int k) {
      if (n == 1)
          return 1;
      else
          /* The position returned by josephus(n - 1, k)
          is adjusted because the recursive call 
          josephus(n - 1, k) considers the 
          original position k % n + 1 as position 1 */
          return (josephus(n - 1, k) + k-1) % n + 1;
  }

};


int main(){
  //fastio

  int n=1, k = 0;
  //fastscan(cases);
  scanf("%d %d",&n, &k);
  cout<<"Last Person Standing is: "<<Solution().safePos(n,k);
  return 0;
}