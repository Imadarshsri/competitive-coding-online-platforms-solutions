#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
   int ans = 0;
   int noOfpoints;
   vector<pair<int,int>> points;
   cin>>noOfpoints;
   map<int,int> xp, yp;
   for(int i =0 ; i< noOfpoints; i++){
      int x,y;
      cin>>x>>y;
      points.push_back({x,y});
      xp[x]++;
      yp[y]++;
   }
   for(int i =0; i< noOfpoints; i++){
      if(xp[points[i].first] >= 3){
         int y = points[i].second;
         int down = 1, up = 1;
         int left = 1, right = 1;
         //checking for up and down
         for(int j = 0; j< noOfpoints; j++){
            if(j == i) continue;
            if(points[j].first == points[i].first){
               if(points[j].second > y && up){
                  up = 0;
               }  
               else if(points[j].second < y && down){
                  down = 0;
               }
            }
            if(up == 0 && down == 0) break;
         }
      
         //validating y
         if((up == 0 && down == 0) && yp[points[i].second] >= 3){
            int x = points[i].first;
            //checking for right and left
            for(int j = 0; j< noOfpoints; j++){
               if(j == i) continue;
               if(points[j].second == points[i].second){
                  if(points[j].first > x && right){
                     right = 0;
                  }  
                  else if(points[j].first < x && left){
                     left = 0;
                  }
               }
               if(right == 0 && left == 0) break;
            }
         }
         if(up == 0 && down == 0 && left == 0 && right == 0) ans++;
      }
   }
   cout<<ans<<"\n";
   return 0;
}