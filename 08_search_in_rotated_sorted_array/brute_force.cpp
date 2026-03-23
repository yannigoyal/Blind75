// ============================================
// SEARCH IN ROTATED SORTED ARRAY - BRUTE FORCE
// TC: O(n)  SC: O(1)
// ============================================

// Approach:
// Linear scan, return index if target found

int search(vector<int>& nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            return i;
        }
    }

    return -1;
}
