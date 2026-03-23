// ============================================
// CONTAINS DUPLICATE - BETTER (SORTING)
// TC: O(nlogn)  SC: O(1)
// ============================================

// Approach:
// Sort the array so duplicates come adjacent
// Then just check if any neighbor is same

// Why better than brute force?
// - No nested loop, just one pass after sorting
// - SC is O(1), no extra space needed

// Why not optimal?
// - Sorting takes O(nlogn), we can do O(n) with HashSet
// - Also modifies the original array

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}
