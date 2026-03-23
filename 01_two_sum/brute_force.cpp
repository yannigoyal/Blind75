// ============================================
// TWO SUM - BRUTE FORCE
// ============================================
// Approach: Check every pair
// TC: O(n²)  SC: O(1)
// ============================================

// Why this works:
// Try all combinations of i and j, return when sum == target

vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}
