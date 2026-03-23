// ============================================
// CONTAINS DUPLICATE - OPTIMAL (HASHSET)
// TC: O(n)  SC: O(n)
// ============================================

// Approach:
// Insert all elements into a HashSet
// Set automatically removes duplicates
// If set size < n, duplicates existed

// Why NOT two pointer?
// - Two pointer needs sorted array
// - Even after sorting, sorting itself is O(nlogn)

// Why NOT sorting?
// - O(nlogn) vs O(n) with HashSet
// - Modifies original array

// Key Insight:
// set.size() < n means some elements were duplicates
// and got merged into one in the set

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();

    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
        set.insert(nums[i]);
    }

    return set.size() < n;
}

// BONUS - Early exit version (slightly faster in practice)
bool containsDuplicateV2(vector<int>& nums) {
    unordered_set<int> set;
    for (int num : nums) {
        if (set.count(num)) return true;   // duplicate found early
        set.insert(num);
    }
    return false;
}
