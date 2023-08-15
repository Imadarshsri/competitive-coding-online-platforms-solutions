// Problem: Maximum product Sum
// Link: https://leetcode.com/problems/maximum-product-subarray/solutions/3321410/c-kadane-s-algo-full-explanation/
// T(n): O(2n) || S(n): O(k) , k = constant

// Optimal Soln. [Brute: Using 2 loops to cal. products for each subarray (T(n): O(n*n) || S(n): O(k))]
// Logic & reasoning behind Algo:
// Here we are calculating both prefix and suffix product using kadane's algo
// b/z unlike maxsum, we can not overlook  -ve no. 
// as in products 2 -ve no. can give us the max product or
// the max product for the given sum might be -ve only
// We only need to take care of `0` that we are handling by the check of 0 in for loop
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int localPr = 1, globalPr = INT_MIN;
        for(int i = 0; i < n; i++) {
            localPr *= nums[i];
            globalPr = max(localPr, globalPr);
            if(localPr == 0) {
                localPr = 1;
            }
        }
        localPr = 1;
        for(int i = n - 1; i >= 0; i--) {
            localPr *= nums[i];
            globalPr = max(localPr, globalPr);
            if(localPr == 0) {
                localPr = 1;
            }
        }
        return globalPr;
    }
};
