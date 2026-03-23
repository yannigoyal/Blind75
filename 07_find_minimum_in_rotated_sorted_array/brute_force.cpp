// ============================================
// FIND MINIMUM IN ROTATED SORTED ARRAY - BRUTE FORCE
// TC: O(n)  SC: O(1)
// ============================================

// Approach:
// Linear scan, track minimum element seen so far

int findMin(vector<int>& nums) {
    int n = nums.size();
    int mini = INT_MAX;

    for (int i = 0; i < n; i++) {
        mini = min(mini, nums[i]);
    }

    return mini;
}
