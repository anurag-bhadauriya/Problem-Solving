// https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1, maxWater = 0;

    // Using two pointer approach
    while (i < j)
    {
        int area = (j - i) * min(height[i], height[j]);
        if (area > maxWater)
            maxWater = area;
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxWater;
}

int main()
{
    return 0;
}
