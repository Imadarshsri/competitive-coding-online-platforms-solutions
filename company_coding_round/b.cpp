#include <bits/stdc++.h>
using namespace std;

int maxHist(string &row, int C) {
   
	stack<int> result;

	int top_val;
	int max_area = 0; 

	int area = 0; 

	int i = 0;
	while (i < C) {
		if (result.empty() || row[result.top()] <= row[i])
			result.push(i++);

		else {
         
			top_val = row[result.top()];
			result.pop();
			area = top_val * i;

			if (!result.empty())
				area = top_val * (i - result.top() - 1);
			max_area = max(area, max_area);
		}
	}

	while (!result.empty()) {
		top_val = row[result.top()];
		result.pop();
		area = top_val * i;
		if (!result.empty())
			area = top_val * (i - result.top() - 1);

		max_area = max(area, max_area);
	}
	return max_area;
}

int maxRectangle(vector<string> &A, int r, int c)
{
	int result = maxHist(A[0], c);

	for (int i = 1; i < r; i++) {

		for (int j = 0; j < c; j++)
      
			if (A[i][j] == '.')
				A[i][j] += A[i - 1][j];

		result = max(result, maxHist(A[i], c));
	}

	return result;
}

int main()
{
   int r = 1, c = 1;
   cin >> r >>c;
   vector<string> A(r);
   for(int i = 0; i < r; i++) {
      string s;
      cin>> s;
      A[i] = s;
   }
	cout<<maxRectangle(A, r, c);

	return 0;
}
