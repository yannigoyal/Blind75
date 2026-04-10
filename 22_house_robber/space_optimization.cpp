/*
DSA Intuition (House Robber - Space Optimization)

1. Represent:
   - Use variables instead of dp array:
     next1 = dp[i+1], next2 = dp[i+2]

2. Choices:
   - Rob → nums[i] + next2
   - Skip → next1

3. Combine:
   - curr = max(rob, skip), then shift variables

TC: O(n)
SC: O(1)
*/
int rob(vector<int>& nums) {
    int n = nums.size();

    int next1 = 0; // dp[i+1]
    int next2 = 0; // dp[i+2]

    for (int i = n - 1; i >= 0; i--) {
        int curr = max(nums[i] + next2, next1);
        next2 = next1;
        next1 = curr;
    }

    return next1;
}
