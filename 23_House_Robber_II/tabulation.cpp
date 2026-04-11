/*
DSA Intuition (House Robber II - Tabulation)

1. Represent:
   - dp[i] = maximum money from index i to end
   - Solve 2 cases due to circular:
     (0 → n-2) and (1 → n-1)

2. Choices:
   - Rob → nums[i] + dp[i+2]
   - Skip → dp[i+1]

3. Combine:
   - dp[i] = max(rob, skip), fill from back
   - Answer = max(case1, case2)

TC: O(n)
SC: O(n)
*/

int solve(vector<int>& nums, int start, int end) {
    vector<int> dp(end + 3, 0);

    for (int i = end; i >= start; i--) {
        int rob = nums[i] + dp[i + 2];
        int skip = dp[i + 1];
        dp[i] = max(rob, skip);
    }

    return dp[start];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int case1 = solve(nums, 0, n - 2);
    int case2 = solve(nums, 1, n - 1);

    return max(case1, case2);
}
