 // --------------------<optimizations>--------------------\
 #pragma GCC optimize("O3")
 //(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
 #pragma comment(linker, "/stack:200000000")
 //(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
 #pragma GCC optimize("unroll-loops")
 // -------------------</optimizations>--------------------
 
 #include<iostream>
 using namespace std;

 void solve(){
   int n = 0, xi = 0, yi = 0, zi = 0, x = 0, y = 0, z = 0;
   cin>>n;
   for(int i = 0; i < n; i++){
      cin>>xi>>yi>>zi;
      x+=xi; y +=yi;z += zi;
   }
   (x == 0 && y == 0 && z == 0) ? cout<<"YES\n": cout<<"NO\n";
 }
 
 int main(){
   int cases=1;
   //fastscan(cases);
  //  scanf("%d",&cases);
   while(cases--){
     solve();
   }
   return 0;
 }