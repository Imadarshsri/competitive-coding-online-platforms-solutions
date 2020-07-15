#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int x){
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries,int n) {
    cout<<"ans::\n";
    for(auto x:indexes){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    vector<node> tree[n+1];
    for(int i=1;i<=n;i++){
        tree[i] = vector<node>();
        tree[i].push_back(node(i));
    }
    for(auto i=indexes.begin();i!=indexes.end();i++){
        for(auto x:*i){
            tree[]
        }
    }
    for(auto x: queries){
        cout<<x<<"\n";
    }
    return indexes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries, n);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            // fout << result[result_row_itr][result_column_itr];
            cout << result[result_row_itr][result_column_itr];


            if (result_column_itr != result[result_row_itr].size() - 1) {
                // fout << " ";
                cout<<" ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            // fout << "\n";
    fout << "\n";

        }
    }

    // fout << "\n";
    cout << "\n";

    fout.close();

    return 0;
}
