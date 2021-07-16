#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#
///Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=8ffb3e51ece8e7d04323c4002a53255e&pid=704867&user=imadarshsri
///Concepts: Strings, Hashing, Greedy
///Complexity: T(n): O(26*n), S(n): O(n)

class Solution{
public:
    string chooseandswap(string a){
        char largestAlphabet = a[0], smallestAlphabet = a[0];
        int n = a.length();
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
            if(vis[i] != 0) continue;
            largestAlphabet = a[i], smallestAlphabet = largestAlphabet;
            vis[i] = 1;
            for(int j = i+1; j < n; j++) {
                if(vis[j] == 0 && a[j] < smallestAlphabet){
                    smallestAlphabet = a[j];
                }
                else if(a[j] == a[i]){
                    vis[j] = 1;
                }
            }
            if(smallestAlphabet!=largestAlphabet)
                break;
        }
        if(smallestAlphabet != largestAlphabet) 
            for(int i = 0; i < n; i++) {
                if(a[i] == smallestAlphabet){
                    a[i] = largestAlphabet;
                }
                else if(a[i] == largestAlphabet) {
                    a[i] = smallestAlphabet;
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