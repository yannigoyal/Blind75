// ============================================
// CONTAINS DUPLICATE - BRUTE FORCE
// TC: O(n²)  SC: O(1)
// ============================================

// Approach:
// Check every pair (i, j) where j > i
// If any pair has same value, return true

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }

    return false;
}
