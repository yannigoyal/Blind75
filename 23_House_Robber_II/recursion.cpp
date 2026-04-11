/*
DSA Intuition (House Robber II - Recursion)

1. Represent:
   - f(i, end) = maximum money we can rob from index i to end
   - Since houses are circular, break into 2 cases:
     (0 → n-2) and (1 → n-1)

2. Choices:
   - Rob current → nums[i] + f(i+2, end)
   - Skip current → f(i+1, end)

3. Combine:
   - Take max of both → max(rob, skip)
   - Final answer = max(case1, case2)

⚠️ Note:
   - This solution explores all possibilities (no caching),
     so it will give TLE on LeetCode due to exponential calls.

TC: O(2^n)
SC: O(n)
*/
int f(int i, int end, vector<int>& nums) {
    if(i > end) return 0;

    int rob = nums[i] + f(i+2, end,nums);
    int skip = f(i+1,end,nums);
    return max(rob,skip);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int case1 = f(0, n-2,nums);
    int case2 = f(1, n-1, nums);

    return max(case1, case2);
}
