#include<iostream>
#include<math.h>
using namespace std;

///Problem Statement: https://leetcode.com/problems/k-th-symbol-in-grammar/
///Solution: https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=10
// /Concepts: // 1) Observation Skills (IMP.) && Recursion IBH
/* Observations:
a) Nth Row Length: 2^(N-1)
b) Length of Nth Row is --> 2 * Length of (N-1)th row
c) If we divide the row is 2 halfs:
i) First half of Nth Row  == (N-1) row
ii) 2nd Half is complement of (N-1)Row i.e. == ~(N-1)th Row
*/
//Your solution class
// 1) Recursion IBH
class Solution {
public:
    int kthGrammar(int N, int K) {
      if(N==1 && K == 1) // Base Condition
        return 0;

      int mid = pow(2, N - 2); 
      if(K <= mid)     // Induction
        return kthGrammar(N - 1, K); //Hypothesis
      else
        return !kthGrammar(N-1, K - mid); //Hypothesis
    }
};

int main(){
  int N,K;
  scanf("%d %d",&N, &K);
  cout<<Solution().kthGrammar(N,K);
  return 0;
}