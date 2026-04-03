/*
Time Complexity: O(n)
Space Complexity: O(n)

Memorization (Top-Down):
- Store results of sub problems in DP array
- Avoid re computation
- From any n, we go to n-1 or n-2
*/ 

int solve(int n, vector<int> &dp) {
    if (n == 0 || n == 1) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}
