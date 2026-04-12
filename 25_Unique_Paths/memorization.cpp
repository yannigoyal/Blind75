/*
Memoization (Top-Down DP)

1. Use dp[i][j] to store result of f(i,j)
2. Avoid recomputation of same states

TC: O(m*n)
SC: O(m*n) + O(m+n)
*/

int f(int i, int j, int m, int n, vector<vector<int>> &dp) {
    // base cases
    if (i >= m || j >= n) return 0;
    if (i == m-1 && j == n-1) return 1;

    // dp check
    if (dp[i][j] != -1) return dp[i][j];

    // choices
    int right = f(i, j+1, m, n, dp);
    int down  = f(i+1, j, m, n, dp);

    // store & return
    return dp[i][j] = right + down;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(0, 0, m, n, dp);
}

