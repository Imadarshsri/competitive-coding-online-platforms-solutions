#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define debug(x) cout<< #x << " = " << (x) << "\n"
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x.first << " : "<<x.second<<"\n"; cout<< endl
using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef uint64_t ui;

void solve(){
  int n = 1;
  cin>>n;
  // debug(n);
  vector<int> a(n), b(n);
  map<int,int> countA, countB;
  int can = INT32_MAX;
  for(int i = 0; i < n; i++){
    cin>>a[i];
    countA[a[i]]++;
    can = min(can, a[i]);
  }
  for(int i =0; i< n; i++){
    cin>>b[i];
    countB[b[i]]++;
    can = min(can, b[i]);
  }
  if(countA == countB){
    cout<<"0\n";
    return;
  }
  // look(countA);
  // look(countB);
  std::map<int, int>::iterator i;
  std::reverse_iterator<std::conditional<false, std::map<int, int>::const_iterator, std::_Rb_tree_iterator<std::pair<const int, int>>>::type> j;
  uint64_t cost = 0;
  if(countA.size() >= countB.size()){
    
    i = countA.begin();
    j = countB.rbegin();
      
    
    int countx = -1;
    int county = -1;
    int  updatedi = 0, updatedj = 0;
    for(;!countA.empty() && !countB.empty() ; ){
      cout<<"Inside for (greater)-> i = "<<(*i).first<<", j = "<<(*j).first<<"\n";
      look(countA);
      look(countB);
      cout<<"checking i\n";
      if((*i).second == 1){ 
        countA.erase((*i).first);
        // i++;
        cout<<"skipped i\n";
        updatedi = 1;
      }
      
      cout<<"checking j\n";
      if((*j).second == 1) {
        countB.erase((*j).first);
        // j++;
        cout<<"skipped j\n";
        updatedj = 1;
      }
      cout<<"checking continue\n";
      if(updatedi != 0|| updatedj != 0) {
        updatedi = 0; updatedj = 0;
        continue;
      }
      
      cout<<"checking i.second\n";
      //pro
      if(((*i).second & 1) && countx == -1){
        // cout<<"i more\n";
        // if() {
          // if(!swappedB.empty() || find(swappedB.begin(), swappedB.end(), (*i).first) == swappedB.end()){ 
        cout<<"invalid i\n";
        cout<<"-1\n";
        return;
          // }
        // }
      }
      cout<<"checking j.second\n";
      if(((*j).second & 1) && county == -1 ){
        // cout<<"j more\n";
        // if(countA.find((*j).first) == countA.end()){
        //   if(!swappedA.empty() || find(swappedA.begin(), swappedA.end(), (*j).first) == swappedA.end()){ 
        cout<<"invalid j\n";
        cout<<"-1\n";
        return;
        //   }
        // }
      }
     
       cout<<"ENter i and j\n";
      // if((*i).first == (*j).first) {
      //   i++;
      // }

      if(countx == -1 ){
        cout<<"countx uppdated\n";
        countx = (*i).second / 2;
      }
      if(county == -1){
        cout<<"county uppdated\n";
        county = (*j).second / 2;
      }
      //founded 1st swap occurence
      // flag = 1;
      int cand = min((*i).first, (*j).first);
      // int can = (*countA.begin()).first <= (*countB.begin()).first ? (*countA.begin()).first : (*countB.begin()).first;
      cost += min(cand, 2*can);
      cout<<"\nSwapped -> "<<(*i).first<<" and "<<(*j).first<<" cost = "<<min(cand, 2*can)<<"\n";
      // swappedA.push_back((*i).first);
      // swappedB.push_back((*j).first);
      // a.erase(find(a.begin(),a.end(),(*i).first));
      // b.erase(find(b.begin(),b.end(),(*j).first));

      // a.push_back((*j).first);
      // b.push_back((*i).first);
      
      (*i).second--;
      (*j).second--;
      countx--;
      county--;

      if(countx == 0){

        countx = -1;
        
        countA.erase((*i).first);
      }
      if(county == 0){
        county = -1;
        countB.erase((*j).first);
      }
    }
  } 
  else{
    i = countB.begin();
    j = countA.rbegin();

    int countx = -1;
    int county = -1;
    int updatedi = 0, updatedj = 0;
    for(; !countB.empty() && !countA.empty() ; ){
      cout<<" Inside for (lesser)-> i = "<<(*i).first<<", j = "<<(*j).first<<"\n";
      
      look(countA);
      look(countB);
      cout<<"checking i\n";
      if((*i).second == 1){ 
        countB.erase((*i).first);
        // i++;
        cout<<"skipped i\n";
        updatedi = 1;
      }
      cout<<"checking j\n";
      
      if((*j).second == 1) {
        countA.erase((*j).first);
        // j++;
        cout<<"skipped j\n";
        updatedj = 1;
      }
      cout<<"checking continue\n";
      if(updatedi || updatedj ) {
        updatedi = 0; updatedj = 0;
        continue;
      }
      cout<<"checking i more\n";

      if(((*i).second & 1) && countx == -1 ){
        // cout<<"i more\n";
        // if(((*i).second & 1) && countA.find((*i).first) == countA.end()) {
        //   if(!swappedA.empty() || find(swappedA.begin(), swappedA.end(), (*i).first) == swappedA.end()){ 
            cout<<"invalid i\n";
            cout<<"-1\n";
            return;
        //   }
        // }
      }
      // cout<<"checking j more\n";
      
      if(((*j).second & 1) && county == -1 ){
        cout<<"j more\n";
        // if(((*j).second & 1) && countB.find((*j).first) == countB.end()){
        //   if(!swappedB.empty() || find(swappedB.begin(), swappedB.end(), (*j).first) == swappedB.end()){ 
            cout<<"invalid j\n";
            cout<<"-1\n";
            return;
        //   }
        // }
      }
      // cout<<"ENter i and j\n";
      // cout<<"checking i == j\n";

      // if((*i).first == (*j).first) {
      //   i++;
      //   continue;
      // }

      if(countx == -1 ){
        cout<<"countx uppdated\n";
        countx = (*i).second / 2;
      }
      if(county == -1){
        cout<<"county uppdated\n";
        county = (*j).second / 2;
      }
      //founded 1st swap occurence
      // flag = 1;
      int cand = min((*i).first, (*j).first);
      // int can = (*countA.begin()).first <= (*countB.begin()).first ? (*countA.begin()).first : (*countB.begin()).first;
      cost += min(cand, 2*can);
      cout<<"\nSwaaped -> "<<(*i).first<<" and "<<(*j).first<<" cost = "<<min(cand, 2*can)<<"\n";
  
      (*i).second--;
      (*j).second--;
      countx--;
      county--;
      cout<<"checking countx\n";

      if(countx == 0){
        countx = -1;
      cout<<" updated countx\n";
        countB.erase((*i).first);
      }    
      cout<<"checking county\n";

      if(county == 0){
        county = -1;
      cout<<" updated county\n";

        countB.erase((*i).first);
      }
      cout<<"Exiting loop\n";
    }
    
  }
  if(countB.empty() && countA.empty() )
    cout<<cost<<"\n";  
  else cout<<"-1\n";
}

int main(){
  //fastio
  int cases=1;
  //fastscan(cases);
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}