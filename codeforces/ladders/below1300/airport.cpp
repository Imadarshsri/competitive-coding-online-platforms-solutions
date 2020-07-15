#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lesser(int &a, int &b){
  return a>b;
}
int main(){
  int passengers = 1, noOfPlanes = 1;
  cin>>passengers>>noOfPlanes;
  vector<int> v;
  int sum = 0;
  for(int i =0 ; i < noOfPlanes ; i++){
    int x;
    cin>>x;
    v.push_back(x);
    sum += x;
  }

  // for(auto x : v) cout<<x<<" ";
  sort(v.begin(), v.end());
  // for(auto x : v) cout<<x<<" ";
  int minCost =0 , maxCost = 0;
  int tempPass = passengers;
  for(int i = 0; i< noOfPlanes && tempPass > 0; i++){
    if(v[i] <= tempPass){
      minCost +=( v[i] * (v[i] + 1))/2;
      tempPass -= v[i];
    }
    else{
      minCost +=(( v[i] * ((v[i] + 1))/2) )- (( (v[i] - tempPass) * ((v[i] + 1 - tempPass)))/2);
      tempPass  = 0;
    }
  }
  
  sort(v.begin(), v.end(), lesser);
  tempPass = passengers;
  //max
  while (tempPass > 0){
    for(int i = 0; i< noOfPlanes - 1 && tempPass > 0; i++){
     while(v[i] >= v[i+1] && tempPass > 0){
       if(v[i] > 0){
       cout<<"chanrges i -"<<v[i]<<"\n";
        maxCost += v[i];
        v[i]--;
        tempPass--;
      }
     }
    }
    if(v[noOfPlanes - 1] > 0 && tempPass > 0){
      //  cout<<"chanrges\n";
        maxCost += v[noOfPlanes - 1];
        v[noOfPlanes - 1]--;
        tempPass--;
    }
  }
  cout<<maxCost<<" "<<minCost<<"\n";
  return 0;
}