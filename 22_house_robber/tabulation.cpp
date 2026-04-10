/*
DSA Intuition (House Robber - Tabulation)

1. Represent:
   - dp[i] = maximum money we can rob starting from index i

2. Choices:
   - Rob current house → nums[i] + dp[i+2]
   - Skip current house → dp[i+1]

3. Combine:
   - dp[i] = max(rob, skip), fill from back

TC: O(n)
SC: O(n)
*/
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 2, 0); // extra space to avoid bounds check

    for (int i = n - 1; i >= 0; i--) {
        int rob = nums[i] + dp[i + 2];
        int skip = dp[i + 1];
        dp[i] = max(rob, skip);
    }

    return dp[0];
}
