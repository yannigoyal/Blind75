/*
DSA Intuition (House Robber - DP + Memoization)

1. Represent:
   - f(i) = maximum money we can rob starting from index i

2. Choices:
   - Rob current house → nums[i] + f(i+2)
   - Skip current house → f(i+1)

3. Combine:
   - Take max of both choices → max(rob, skip)

TC: O(n)
SC: O(n) + O(n) recursion stack
*/
int f(int i, vector<int>& nums, vector<int>& dp) {
    if (i >= nums.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int rob = nums[i] + f(i + 2, nums, dp);
    int skip = f(i + 1, nums, dp);

    return dp[i] = max(rob, skip);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(0, nums, dp);
}
