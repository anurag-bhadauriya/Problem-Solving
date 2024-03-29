// https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/

// C++ program to compute sum of pairwise bit differences
#include <bits/stdc++.h>
using namespace std;

int sum_bit_diff(vector<int> a)
{
	int n = a.size();
	int ans = 0;

	for (int i = 0; i < n - 1; i++) {
		int count = 0;

		for (int j = i; j < n; j++) {
			// Bitwise and of pair (a[i], a[j])
			int x = a[i] & a[j];
			// Bitwise or of pair (a[i], a[j])
			int y = a[i] | a[j];

			bitset<32> b1(x);
			bitset<32> b2(y);

			// to count set bits in and of two numbers
			int r1 = b1.count();
			// to count set bits in or of two numbers
			int r2 = b2.count();

			// Absolute differences at individual bit positions of two
			// numbers is contributed by pair (a[i], a[j]) in count
			count = abs(r1 - r2);

			// each pair adds twice of contributed count
			// as both (a, b) and (b, a) are considered
			// two separate pairs.
			ans = ans + (2 * count);
		}
	}
	return ans;
}

int main()
{

	vector<int> nums{ 10, 5 };
	int ans = sum_bit_diff(nums);

	cout << ans;
}
