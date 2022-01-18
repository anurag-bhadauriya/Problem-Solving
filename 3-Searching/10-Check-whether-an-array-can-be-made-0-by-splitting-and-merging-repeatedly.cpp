// https://www.geeksforgeeks.org/check-whether-an-array-can-be-made-0-by-splitting-and-merging-repeatedly/

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function that finds if it is
// possible to make the array
// contain only 1 element i.e. 0
string solve(vector<int>& A)
{
	int i, ctr = 0;
	for (i = 0; i < A.size();
		i++) {

		// Check if element is odd
		if (A[i] % 2) {
			ctr++;
		}
	}

	// According to the logic
	// in above approach
	if (ctr % 2) {
		return "No";
	}
	else {
		return "Yes";
	}
}

// Driver code
int main()
{

	vector<int> arr = { 9, 17 };

	cout << solve(arr) << endl;
	return 0;
}
