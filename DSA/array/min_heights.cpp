#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  Problem Statement: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
int getMinDiff(vector<int> &arr, int n, int k)
{
  if (n == 1)
    return 0;

  sort(arr.begin(), arr.end());

  int ans = arr[n - 1] - arr[0];

  int small = arr[0] + k;
  int big = arr[n - 1] - k;
  if (small > big)
    swap(small, big);

  for (int i = 1; i < n - 1; i++)
  {
    int subtract = arr[i] - k;
    int add = arr[i] + k;
    if (subtract >= small || add <= big)
      continue;
    if (big - subtract <= add - small)
      small = subtract;
    else
      big = add;
  }

  return min(ans, big - small);
}

int main()
{
  //fastio

  int cases = 1;
  //fastscan(cases);
  scanf("%d", &cases);
  while (cases--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    cout << getMinDiff(v, n, k) << "\n";
  }
  return 0;
}
