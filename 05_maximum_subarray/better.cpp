// ============================================
// MAXIMUM SUBARRAY - BETTER
// TC: O(n²)  SC: O(1)
// ============================================

// Approach:
// Fix start point, keep extending end
// Instead of recalculating sum from scratch each time,
// reuse previous sum and just add next element to it

// Why better than brute force?
// - Eliminated the 3rd inner loop (k loop)
// - Reuse sum instead of recalculating → O(n²) vs O(n³)

// Why not optimal?
// - Still has nested loop → O(n²)
// - Kadane's does it in single pass O(n)

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maximum = INT_MIN;

    for (int st = 0; st < n; st++) {
        int sum = 0;
        for (int end = st; end < n; end++) {
            sum += nums[end];              // reuse previous sum
            maximum = max(maximum, sum);
        }
    }

    return maximum;
}
