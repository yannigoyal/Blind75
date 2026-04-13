/*
DSA Intuition (Jump Game - Memoization)

1. Represent:
   - f(i) = can we reach last index starting from index i

2. Choices:
   - From index i, try all jumps from 1 → nums[i]
   - Move to (i + step) and check if it can reach end

3. Combine:
   - If any path returns true → return true
   - Else → return false

TC: O(n * maxJump)  
SC: O(n) + recursion stack
*/
bool f(int i, vector<int> &nums, vector<int>& dp) {
    int n = nums.size();

    if(i >=n-1) return true; 
    if(nums[i] == 0) return false;

    if(dp[i] != -1) {
        return dp[i];
    }
    for(int step = 1; step<=nums[i]; step++) {
        if(f(i+step, nums,dp))  {
            dp[i] = 1;
            return true;
        }
    }
    dp[i] = 0;
    return false;
}
bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,-1);
    return f(0, nums, dp); 
}
