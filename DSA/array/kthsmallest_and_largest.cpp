#include<bits/stdc++.h>
using namespace std;

//User function template for C++
// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
// int kthSmallest(int *, int, int, int);

//Sort
// int kthSmallest(int arr[], int l, int r, int k) {
//     sort(arr, arr + r + 1);
//     return arr[k-1];
// }

//Max Heap
// int kthSmallest(int arr[], int l, int r, int k) {
//     priority_queue<int> q;
//     int x = 0;
//     for(; x < k; x++){
//         q.push(arr[x]);
//     }
//     for(;x<=r; x++){
//         if(arr[x] < q.top()){
//             q.pop();
//             q.push(arr[x]);
//         }
//     }
//     return q.top();
// }

// Quick Select
int randPartition(int arr[], int l , int r){
    int i = l - 1, n = r - l + 1;
    int idx = (rand() % n) + l;
    
    swap(arr[idx], arr[r]);
    int pivot = arr[r];
    for(int j = l; j < r; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int kthSmallest(int arr[], int l, int r, int k) {
    if(k > 0 && k <= (r-l +1)){
        int pos = randPartition(arr,l,r);
        if(pos - l == (k-1)){
            return arr[pos];
        }
        else if(pos - l > ( k - 1)){
            return kthSmallest(arr, l, pos-1, k);
        }
        else
            return kthSmallest(arr, pos+1, r, k - pos + l -1);
    }
}
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends

