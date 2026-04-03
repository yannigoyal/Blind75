/*
Time Complexity: O(n)
Space Complexity: O(1)

Space Optimized:
- We only store last two values (prev1, prev2)
- Each step is sum of previous two (like Fibonacci)
*/

int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;

    int prev2 = 1; // dp[0]
    int prev1 = 1; // dp[1]

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
