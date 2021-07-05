#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#
///Solution: 
///Concepts: Strings, Hashing, Greedy ??
///Complexity: T(n): O(26*n), S(n): O(n)

class Solution{
public:
    string chooseandswap(string a){
        char f = a[0], l = a[0];
        int n = a.length();
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
            if(vis[i] != 0) continue;
            f = a[i], l = f;
            vis[i] = 1;
            for(int j = i+1; j < n; j++) {
                if(vis[j] == 0 && a[j] < l){
                    l = a[j];
                }
                else if(a[j] == a[i]){
                    vis[j] = 1;
                }
            }
            if(l!=f)
                break;
        }
        if(l != f) 
            for(int i = 0; i < n; i++) {
                if(a[i] == l){
                    a[i] = f;
                }
                else if(a[i] == f) {
                    a[i] = l;
                }
            }
        
        return a;
    }
    
};

int main(){
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}