/*
Approach: Tabulation (Bottom-Up DP)
TC: O(n * n)
SC: O(n)

Logic:
- dp[i] → length of LIS ending at index i

Initialization:
- dp[i] = 1 (each element itself is LIS of length 1)

Transition:
- for every i, check all previous j < i
- if nums[i] > nums[j]:
    dp[i] = max(dp[i], 1 + dp[j])

Answer:
- max value in dp array
*/

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}
