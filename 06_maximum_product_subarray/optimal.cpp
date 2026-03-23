// ============================================
// MAXIMUM PRODUCT SUBARRAY - OPTIMAL
// TC: O(n)  SC: O(1)
// ============================================

// Why NOT Kadane's algorithm directly?
// - Kadane's resets sum to 0 when negative
// - For product, negative * negative = positive
// - So we CANNOT simply reset on negative

// Why NOT just track max and min?
// - Works but needs careful handling of zeros
// - Prefix-Suffix is more intuitive

// Key Insight: Prefix and Suffix products
// Maximum product subarray is either:
//   → a prefix  (starts from left,  excludes right negatives)
//   → a suffix  (starts from right, excludes left negatives)
// By checking both, we cover all cases

// Why reset prefix/suffix to 1 on zero?
// - 0 kills the product
// - Fresh start after 0 just like Kadane's resets sum to 0

// pref = product from left  → handles odd negatives on right
// suff = product from right → handles odd negatives on left
// Together they cover ALL cases

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = INT_MIN;
    int pref = 1;
    int suff = 1;

    for (int i = 0; i < n; i++) {
        if (pref == 0) pref = 1;      // reset on zero
        if (suff == 0) suff = 1;      // reset on zero

        pref = pref * nums[i];         // prefix: left to right
        suff = suff * nums[n-i-1];     // suffix: right to left

        maxProd = max(maxProd, max(pref, suff));
    }

    return maxProd;
}
