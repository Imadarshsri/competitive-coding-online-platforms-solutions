#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
///Solution: https://www.youtube.com/watch?v=F_DDzYnxO14&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=49
///Concepts: Greedy
///Complexity: T(n): O(nlogn), S(n): O(1)
 
struct Item{
    int value;
    int weight;
};
bool comp (Item &a, Item &b) {
    double ratioA = a.value/(1.0 * a.weight);
    double ratioB = b.value/(1.0 * b.weight);
    if(ratioA > ratioB) return true;
    return false;
}
class Solution {
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr+n, comp);
        double ans = 0;
        for(int i = 0; i < n && W > 0; i++) {
            if(arr[i].weight <= W) {
                ans += arr[i].value;
                W -= arr[i].weight;
            }
            else{
                ans += (arr[i].value/(1.0 * arr[i].weight)) * W;
                W = 0;
            }
        }
        return ans;
    }
        
};