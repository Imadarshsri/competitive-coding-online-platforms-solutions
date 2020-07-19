/*Ques 
There are n children in Jzzhu's school. Jzzhu is going to give some candies to them. Let's number all the children from 1 to n. The i-th child wants to get at least a i candies.

Jzzhu asks children to line up. Initially, the i-th child stands at the i-th place of the line. Then Jzzhu start distribution of the candies. He follows the algorithm:

Give m candies to the first child of the line.
If this child still haven't got enough candies, then the child goes to the end of the line, else the child go home.
Repeat the first two steps while the line is not empty.
Consider all the children in the order they go home. Jzzhu wants to know, which child will be the last in this order?
*/
#include<iostream>

using namespace std;
int main(){
   int candies,children;
   cin>>children>>candies;

   int ans = -1, ans2 = -1;
   for(int i = 0;i<children; i++){
      int x;
      cin>>x;
      if(x/candies >= ans2){
         ans = i+1;
         ans2 = x/candies;
      }
      cout<<"Orig>"<<i<<" "<<ans<<"ANS->"<<ans2<<" \n";
   }
   cout<<ans<<"\n";
   return 0;
}