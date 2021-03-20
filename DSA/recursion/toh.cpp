#include<iostream>
#include<math.h>
using namespace std;

///Problem Statement: https://leetcode.com/problems/k-th-symbol-in-grammar/
///Solution: https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=10
// Concepts: 
// 1) Recursion IBH: T(n): O(2^(n) - 1)
class Solution {
public:
    long long toh(int n, char src, char dest, char aux) {
      if(n==0) // Base Condition
        return 0;
      long long  ans = toh(n - 1, src, aux, dest); // Hypothesis
      printf("Move disk %d from rod %c to rod %c.\n", n,src, dest); // Induction
      ans++;
      ans += toh(n - 1, aux, dest, src); // Induction + Hypo
      return ans;
    }
};

int main(){
  int N;
  scanf("%d",&N);
  auto ans = Solution().toh(N, 'A', 'C', 'B');
  cout<<"No. of Steps taken: "<<ans;
  return 0;
} 