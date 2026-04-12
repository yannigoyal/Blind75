/*
DSA Intuition (Unique Paths - Tabulation)

1. Represent:
   - dp[i][j] = number of ways to reach (i, j) from (0,0)

2. Base Case:
   - dp[0][0] = 1 (starting point)

3. Fill DP:
   - From each cell, we can come from:
       up    → dp[i-1][j]
       left  → dp[i][j-1]
   - dp[i][j] = dp[i-1][j] + dp[i][j-1]

4. Edge Handling:
   - First row → only from left
   - First col → only from up

TC: O(m*n)
SC: O(m*n)
*/
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // base case
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) continue;

            int up = 0, left = 0;

            if (i > 0) up = dp[i-1][j];
            if (j > 0) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }

    return dp[m-1][n-1];
}
