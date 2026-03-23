// ============================================
// PRODUCT OF ARRAY EXCEPT SELF - OPTIMAL
// TC: O(n)  SC: O(1) (excluding output array)
// ============================================

// Why NOT better approach?
// - Uses 2 extra arrays of size n → SC: O(n)
// - We can eliminate both arrays

// Space Optimization over better approach:
// - Instead of storing prefix array → reuse result[]
// - Instead of storing suffix array → use a single variable

// nums =   [  1,  2,  3,  4 ]
// prefix = [  1,  1,  2,  6 ]   stored in result[]
// suffix     24  12   4   1     tracked via variable (right to left)
// answer = [ 24, 12,  8,  6 ]

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    // Step 1: store prefix products in result[]
    result[0] = 1;
    for (int i = 1; i < n; i++) {
        result[i] = result[i-1] * nums[i-1];
    }

    // Step 2: multiply suffix on the fly using variable
    int suffix = 1;
    for (int i = n-1; i >= 0; i--) {
        result[i] = result[i] * suffix;
        suffix *= nums[i];
    }

    return result;
}
