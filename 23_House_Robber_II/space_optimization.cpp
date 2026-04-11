/*
DSA Intuition (House Robber II - Space Optimization)

1. Represent:
   - Instead of dp[], use variables:
     next1 = dp[i+1], next2 = dp[i+2]
   - Solve 2 linear cases due to circular

2. Choices:
   - Rob → nums[i] + next2
   - Skip → next1

3. Combine:
   - curr = max(rob, skip), shift variables
   - Answer = max(case1, case2)

TC: O(n)
SC: O(1)
*/

int solve(vector<int>& nums, int start, int end) {
    int next1 = 0; // dp[i+1]
    int next2 = 0; // dp[i+2]

    for (int i = end; i >= start; i--) {
        int curr = max(nums[i] + next2, next1);
        next2 = next1;
        next1 = curr;
    }

    return next1;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int case1 = solve(nums, 0, n - 2);
    int case2 = solve(nums, 1, n - 1);

    return max(case1, case2);
}
