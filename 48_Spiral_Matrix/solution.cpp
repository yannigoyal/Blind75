/*
Approach:
We use four pointers (top, bottom, left, right) to track the boundaries of the matrix.
Traverse in spiral order:
1. Left → Right (top row)
2. Top → Bottom (right column)
3. Right → Left (bottom row)
4. Bottom → Top (left column)

After each traversal, update the boundaries.
Repeat until all elements are covered.

TC: O(n*m)
SC: O(1) (excluding result)
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> result;
    int top = 0, bottom = row - 1, left = 0, right = col - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}