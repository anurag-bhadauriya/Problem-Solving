// https://leetcode.com/problems/flood-fill/

#include <iostream>
#include <vector>
using namespace std;

void performFill(vector<vector<int>> &image, int sr, int sc, int newColor, int prevColor)
{
    int row = image.size();
    int col = image[0].size();

    if (newColor == prevColor)
        return;

    // Fill the color
    image[sr][sc] = newColor;

    // Left Fill
    if (sc - 1 >= 0 && image[sr][sc - 1] == prevColor)
        performFill(image, sr, sc - 1, newColor, image[sr][sc - 1]);
    // Right Fill
    if (sc + 1 < col && image[sr][sc + 1] == prevColor)
        performFill(image, sr, sc + 1, newColor, image[sr][sc + 1]);
    // Up Fill
    if (sr - 1 >= 0 && image[sr - 1][sc] == prevColor)
        performFill(image, sr - 1, sc, newColor, image[sr - 1][sc]);
    // Down Fill
    if (sr + 1 < row && image[sr + 1][sc] == prevColor)
        performFill(image, sr + 1, sc, newColor, image[sr + 1][sc]);
    return;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int prevColor = image[sr][sc];

    performFill(image, sr, sc, newColor, prevColor);
    return image;
}

int main()
{
    return 0;
}
