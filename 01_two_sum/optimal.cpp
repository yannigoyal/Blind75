// ============================================
// TWO SUM - OPTIMAL
// ============================================
// Approach: HashMap
// TC: O(n)  SC: O(n)
// ============================================

// Why NOT two pointers?
// - Two pointer needs sorted array
// - Sorting loses original indices
// - We need to return indices, not values
// - So two pointer doesn't work here

// Why NOT sliding window?
// - Sliding window works on contiguous subarrays
// - No such constraint here

// Key Insight:
// For each num, check if (target - num) already seen
// Store {value -> index} in hashmap

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.count(complement))
            return {mp[complement], i};
        mp[nums[i]] = i;
    }
    return {};
}
