// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

enum Move_Type { LEFT, RIGHT};
vector<int> searchRange(vector<int>& nums, int target);
int SearchOccurenceAsPerMove( vector<int>& nums, int target, Move_Type move);

int main() {
	vector<int> arr {5,7,7,8,8,10};
	int target = 6;
	
	vector<int> res = searchRange(arr, target);
	for(auto i=res.begin(); i<res.end(); i++)
		cout << *i << ",";

	return 0;
}

vector<int> searchRange(vector<int>& nums, int target) {
	Move_Type left = LEFT;
	Move_Type right = RIGHT;
	int leftMostOccurence = SearchOccurenceAsPerMove(nums, target, left);
	int rightMostOccurence = SearchOccurenceAsPerMove(nums, target, right);
	vector<int> result {leftMostOccurence, rightMostOccurence};
	return result;
}

int SearchOccurenceAsPerMove( vector<int>& nums, int target, Move_Type move){
	int low =0;
	int high = nums.size()-1;
	int idx = -1;
	if( high >= low){
		while( low <= high){
			int mid = ((low + high)/2);
			if( nums[mid] == target ){
				idx = mid;
				if( move == LEFT)
					high = mid-1;
				else 
					low = mid+1;
			}
			else if (nums[mid] > target)
				high = mid-1;
			else
				low = mid+1;
		}
	}
	return idx;
}

