/*
DSA Intuition (Jump Game - Tabulation)

1. Represent:
   - dp[i] = can we reach last index starting from index i

2. Choices:
   - From index i, try all jumps from 1 → nums[i]
   - Check dp[i + step]

3. Combine:
   - If any dp[i + step] is true → dp[i] = true
   - Else → false

TC: O(n * maxJump)  
SC: O(n)
*/

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);

    dp[n-1] = true;

    for(int i = n-2; i >= 0; i--) {
        for(int step = 1; step <= nums[i] && i + step < n; step++) {
            if(dp[i + step]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0];
}
