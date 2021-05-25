#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

///Problem Statement: https://leetcode.com/problems/3sum
///Solution: https://leetcode.com/submissions/detail/364170631/ , https://www.youtube.com/watch?v=onLoX6Nhvmg&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=41
///Concepts: 1) Iteration, 2 Pointers , T(n): O(nlogn + n^2)

//Your solution class
class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                

                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }

        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}
};

int main(){
  int n = 1;
  cin>>n;
  vector<int> nums(n);

  for(int i = 0; i< n; i++){
    cin>>nums[i];
  }
  Solution().threeSum(nums);
  return 0;
}