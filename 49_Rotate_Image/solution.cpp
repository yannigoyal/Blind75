/*
Rotate matrix 90° clockwise using extra space:

- Create a new matrix (temp)
- Place each element at its rotated position:
  matrix[i][j] → temp[j][n-i-1]

- Copy temp back to original matrix

TC: O(n^2)
SC: O(n^2)
*/
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - i - 1] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}