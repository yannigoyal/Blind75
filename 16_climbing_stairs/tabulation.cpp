/*
Time Complexity: O(n)
Space Complexity: O(n)

Tabulation (Bottom-Up):
- Start from base cases dp[0] = 1, dp[1] = 1
- Build answer from 2 to n using previous values
- dp[i] = dp[i-1] + dp[i-2]
*/

int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;

    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
