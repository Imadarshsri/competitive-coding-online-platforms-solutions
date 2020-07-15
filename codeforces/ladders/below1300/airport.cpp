#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool lesser (int &a, int &b){
  return a>b;
}
void solve(){
  int passengers = 1, planes;
  cin>>passengers>>planes;
  vector <int> seats(planes);
  
  //MIN
  sort(seats.begin(), seats.end());

  //MAX
  sort(seats.begin(), seats.end(), lesser);
  return;

}
int main(){
  int cases  = 1;
  while(cases--) solve();
  return 0;
}