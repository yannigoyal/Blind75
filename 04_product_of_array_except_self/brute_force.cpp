// ============================================
// PRODUCT OF ARRAY EXCEPT SELF - BRUTE FORCE
// TC: O(n²)  SC: O(1)
// ============================================

// Approach:
// For each index i, multiply all elements except nums[i]

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                product *= nums[j];
            }
        }
        result[i] = product;
    }

    return result;
}
