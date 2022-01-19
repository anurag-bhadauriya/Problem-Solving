// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target);

int main() {
	vector<int> arr {4,5,6,7,0,1,2};
	int target = 3;
	
	int res = search(arr, target);
	cout << res;
	return 0;
}

int search(vector<int>& nums, int target) {
	int lo =0, hi = nums.size()-1;
	while( lo <= hi){
		int mid = (( lo+hi )/2);
		if( nums[mid] == target)
			return mid;
		// If array is sorted b/n lo to mid
		if( nums[lo] <= nums[mid]){
			if(target >= nums[lo] && target < nums[mid])
				hi = mid-1;
			else
				lo = mid+1;
		}
		// If array is sorted b/n mid & high
		else if (nums[mid] < nums[hi]){
			if(target > nums[mid] && target <=nums[hi])
				lo = mid+1;
			else
				hi = mid-1;
		}
	}
	return -1;
}