#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
bool lesser (int &a, int &b){
  return a>b;
}
void solve(){
  int passengers = 1, planes;
  uint64_t minCost = 0, maxCost = 0;
  cin>>passengers>>planes;
  vector <int> seats(planes);
  priority_queue <int, vector<int>, greater<int>> minHeap;
  priority_queue<int> maxHeap;
  for(int i =0;i < planes; i++){
    cin>>seats[i];
    minHeap.push(seats[i]);
    maxHeap.push(seats[i]);
  }
  int tempPass = passengers;
  //MIN
  sort(seats.begin(),seats.end());
  for(int i = 0; i < planes && tempPass>0; i++){
    if(seats[i] > 0 && seats[i] <= tempPass){
      minCost += (seats[i] * (seats[i] + 1))/2;
      tempPass -= seats[i];
      seats[i] -= seats[i];
      // cout<<"if minCost"<<minCost<<"\n";
    }
    else if(seats[i] > 0){
      minCost += (seats[i] * (seats[i] + 1))/2 - ((seats[i] - tempPass)* (seats[i] + 1 - tempPass))/2;
      tempPass = 0;
      seats[i] -= seats[i] - tempPass;
      // cout<<"else minCost"<<minCost<<"\n";

    }
  }
  if(tempPass > 0){
    cout<<"-1\n";
    return;
  }
  tempPass = passengers;
  //MAX
  while (!maxHeap.empty() && tempPass > 0){
    int selectedSeat = maxHeap.top();
    maxHeap.pop();
    if(selectedSeat == 0) continue;
    maxCost += selectedSeat;
    maxHeap.push(selectedSeat-1);
    tempPass--;
  }
  cout<<maxCost<<" "<<minCost<<"\n";
  return;
}
int main(){
  int cases  = 1;
  while(cases--) solve();
  return 0;
}