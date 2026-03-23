// ============================================
// MAXIMUM PRODUCT SUBARRAY - BRUTE FORCE
// TC: O(n²)  SC: O(1)
// ============================================

// Approach:
// Fix start point, keep extending end
// Reuse previous product by multiplying next element
// Track maximum product across all subarrays

// Why not O(n³)?
// Reuse product instead of recalculating from scratch
// Same optimization as maximum subarray better approach

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = INT_MIN;

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = i; j < n; j++) {
            product *= nums[j];               // reuse previous product
            maxProd = max(maxProd, product);
        }
    }

    return maxProd;
}
