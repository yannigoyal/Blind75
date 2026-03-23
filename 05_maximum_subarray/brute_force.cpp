// ============================================
// MAXIMUM SUBARRAY - BRUTE FORCE
// TC: O(n³)  SC: O(1)
// ============================================

// Approach:
// Try every possible subarray using 3 loops
// st = start, end = end, k = iterate inside to get sum
// Track maximum sum across all subarrays

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maximum = INT_MIN;

    for (int st = 0; st < n; st++) {
        for (int end = st; end < n; end++) {
            int sum = 0;
            for (int k = st; k <= end; k++) {
                sum += nums[k];
            }
            maximum = max(maximum, sum);
        }
    }

    return maximum;
}
