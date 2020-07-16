// Chef has N axis-parallel rectangles in a 2D Cartesian coordinate system. These rectangles may intersect, but it is guaranteed that all their 4N vertices are pairwise distinct.

// Unfortunately, Chef lost one vertex, and up until now, none of his fixes have worked (although putting an image of a point on a milk carton might not have been the greatest idea after all…). Therefore, he gave you the task of finding it! You are given the remaining 4N−1 points and you should find the missing one.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// Then, 4N−1 lines follow. Each of these lines contains two space-separated integers x and y denoting a vertex (x,y) of some rectangle.
// Output
// For each test case, print a single line containing two space-separated integers X and Y ― the coordinates of the missing point. It can be proved that the missing point can be determined uniquely.

// Constraints
// T≤100
// 1≤N≤2*10^5
// |x|,|y|≤10^9
// the sum of N over all test cases does not exceed 2*10^5
#include <iostream>
#include <map>
using namespace std;

int main(){
  int cases = 1;
  scanf("%d", &cases);
  while(cases--){
    map<int,int> x_coordinate, y_coordinate;
    uint64_t n;
    cin>>n;
    n = 4*n - 1;
    while(n--){
      int x,y;
      cin>>x>>y;
      if(x_coordinate[x] & 1) x_coordinate.erase(x);
      if(y_coordinate[y] & 1) y_coordinate.erase(y);
    }
    int ans_x, ans_y;
    for(auto x: x_coordinate) ans_x = x.first;
    for(auto y: y_coordinate) ans_y = y.first;
    cout<<ans_x<<" "<<ans_y<<"\n";
    x_coordinate.clear();y_coordinate.clear();
  }
}