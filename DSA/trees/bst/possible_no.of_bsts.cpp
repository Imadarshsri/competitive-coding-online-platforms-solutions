#include<iostream>
#include<vector>
using namespace std;

int possibleNoOfBSTs(int n) {
   if(n <= 1)
      return 1;
}
int main() {
   int n = 1;
   cin >> n;
   cout << "Possible No. of BST with " << n << " nodes are: " << possibleNoOfBSTs(n);
 
}