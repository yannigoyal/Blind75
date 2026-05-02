/*
Approach:
1. First check if first row or first column has any 0.
   → Use rowZero & colZero flags, because we will overwrite them later.

2. Use first row and first column as markers:
   → If matrix[i][j] == 0, mark:
        matrix[i][0] = 0  (entire row i should be zero)
        matrix[0][j] = 0  (entire col j should be zero)

3. Traverse the matrix again (excluding first row & col):
   → If row marker OR col marker is 0, make that cell 0.

4. Finally handle first row and first column separately
   → Because they were used as markers.

Key Idea:
Reuse matrix itself for marking to achieve O(1) space.

TC: O(m*n)
SC: O(1)
*/
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();


    bool rowZero = false;
    bool colZero = false;

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            rowZero = true;
            break;
        }
    }

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            colZero = true;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (rowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    if (colZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}
