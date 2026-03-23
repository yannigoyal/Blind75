// ============================================
// MAXIMUM SUBARRAY - OPTIMAL (KADANE'S ALGORITHM)
// TC: O(n)  SC: O(1)
// ============================================

// Why NOT better approach?
// - Still O(n²) due to nested loop
// - We can solve in single pass

// Key Insight:
// If current running sum becomes negative,
// it will only REDUCE any future subarray sum
// So reset sum = 0 and start fresh from next element

// Why reset to 0 and not INT_MIN?
// - 0 means "start fresh, take nothing from before"
// - INT_MIN would break the addition

// Dry Run: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
// sum  →  -2  1  -2  4   3   5  6   1   5
// max  →  -2  1   1  4   4   5  6   6   6
// sum<0 → reset → 0  0   0   -   -  -   -   -   -
// answer = 6 ✅

// Why not two pointer?
// - Subarray sum can be negative, two pointer won't work correctly

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maximum = INT_MIN;
    int sum = 0;

    for (int st = 0; st < n; st++) {
        sum += nums[st];
        maximum = max(maximum, sum);

        // if sum is negative, reset → fresh start
        if (sum < 0) {
            sum = 0;
        }
    }

    return maximum;
}
