// ============================================
// PRODUCT OF ARRAY EXCEPT SELF - BETTER
// TC: O(n)  SC: O(n)
// ============================================

// Approach:
// Build two separate arrays:
// prefix[i] = product of all elements LEFT of i
// suffix[i] = product of all elements RIGHT of i
// answer[i] = prefix[i] * suffix[i]

// nums =    [  1,  2,  3,  4 ]
// prefix =  [  1,  1,  2,  6 ]
// suffix =  [ 24, 12,  4,  1 ]
// answer =  [ 24, 12,  8,  6 ]

// Why better than brute force?
// - Only O(n) time, no nested loop
// - Very easy to understand and visualize

// Why not optimal?
// - Uses 2 extra arrays → SC: O(n)
// - Can be reduced to O(1) extra space

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    vector<int> result(n);

    // Step 1: build prefix array
    prefix[0] = 1;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    // Step 2: build suffix array
    suffix[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    // Step 3: multiply prefix and suffix
    for (int i = 0; i < n; i++) {
        result[i] = prefix[i] * suffix[i];
    }

    return result;
}
