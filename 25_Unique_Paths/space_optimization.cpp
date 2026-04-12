/*
DSA Intuition (Unique Paths - Space Optimization)

1. Observation:
   - We only need previous row to compute current row

2. Use 1D array:
   - dp[j] represents current row
   - dp[j] = dp[j] (up) + dp[j-1] (left)

3. Initialization:
   - dp[0] = 1 (first column always 1 way)

TC: O(m*n)
SC: O(n)
*/
int uniquePaths(int m, int n) {
    vector<int> dp(n, 0);

    dp[0] = 1;  // base case

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (j > 0) {
                dp[j] = dp[j] + dp[j-1];  // up + left
            }
        }
    }

    return dp[n-1];
}
