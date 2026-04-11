/*
DSA Intuition (House Robber II - Memoization)

1. Represent:
   - f(i, end) = maximum money from i to end
   - Use dp[i] to store results, handle 2 cases due to circular array

2. Choices:
   - Rob → nums[i] + f(i+2, end)
   - Skip → f(i+1, end)

3. Combine:
   - dp[i] = max(rob, skip)
   - Answer = max(case1, case2)

TC: O(n)
SC: O(n) + O(n) recursion stack
*/
int f(int i, int end, vector<int>& nums, vector<int>&dp) {
    if(i > end) return 0;

    if(dp[i] != -1) return dp[i];
    int rob = nums[i] + f(i+2, end,nums,dp);
    int skip = f(i+1,end,nums,dp);
    return dp[i] = max(rob,skip);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    vector<int> dp1(n,-1);
    vector<int> dp2(n,-1);
    int case1 = f(0, n-2,nums, dp1);
    int case2 = f(1, n-1, nums,dp2);

    return max(case1, case2);
}
