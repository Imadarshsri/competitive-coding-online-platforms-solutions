#include<bits/stdc++.h>
using namespace std;

// Max. no of house
int N = 25;

// DFS function to store the diameter of min. pipe that will be installed
// Returns the House no. which will have the outgoing pipe
int dfs(int root, vector<int> &out, int *dia, vector<int> &wt) {
    // Store min. diameter
    if(wt[root] < *dia)
        *dia = wt[root];
        
    // If there is no outgoing pipe, then this will be our ans
    if(out[root] == -1) 
        return root;
        
    // Perform DFS for outgoing pipe house no.
    return dfs(out[root], out, dia, wt);
}
// Comparator Function to sort the ans vector by house no. of tank
bool comp(vector<int> &a, vector<int> & b) {
    return a[0] < b[0];
}

vector<vector<int>> solve(int n, int p, int a[], int b[], int d[]) {
    // wt[i]: The diameter incoming pipe at house no. i 
    // wt[i] will also represent whether house no. i has an incoming pipe or not
    // out[i]: House no. to which outgoing pipe is connected
    vector<int> wt(N, -1), out(N, -1);
    for(int i = 0; i < p; i++) {
        out[a[i]] = b[i];
        wt[b[i]] = d[i];
    }
    
    vector<vector<int>> ans;
    for(int i = 0; i < p; i++) {
        /* If a house has no incoming pipe 
        that means a tank will be installed in this house
        and has an outgoing pipe then we need
        to start DFS with this vertex. */
        if(wt[a[i]] == -1) {
            // This will have the min. diameter of pipe that will be installed
            int dia = INT_MAX;
            // DFS will return the house no. of the house which will have the tap and wil be connected to a[i]
            int houseNoOfTap = dfs(out[a[i]], out, &dia, wt);
             
            // We put the details of component
            // in final ans array
            ans.push_back({a[i], houseNoOfTap, dia});
        }
    }
    sort(ans.begin(), ans.end(), comp);
    return ans;
}

// Driver function
int main()
{
    int n = 9, p = 6;
    
    int a[] = {7, 5, 4, 2, 9, 3};
    int b[] = {4, 9, 6, 8, 7, 1};
    int d[] = {98, 72, 10, 22, 17, 66};
 
    vector<vector<int>> ans = solve(n, p, a, b, d);
    cout << ans.size() << "\n";
    for(vector<int> v: ans) {
        cout << v[0] << v[1] << v[2] <<"\n";
    }
    return 0;
}