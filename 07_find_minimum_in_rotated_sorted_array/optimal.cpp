// ============================================
// FIND MINIMUM IN ROTATED SORTED ARRAY - OPTIMAL
// TC: O(logn)  SC: O(1)
// ============================================

// Why NOT linear scan?
// - O(n) but problem demands O(logn)
// - Not utilizing the sorted property at all

// Why NOT normal binary search?
// - Normal BS finds a target, here we find minimum
// - Array is not fully sorted, it's rotated
// - Need modified BS to handle rotation

// Key Insight:
// Rotated array has two sorted halves
// [4, 5, 6, 7, 0, 1, 2]
//  ← left half → ← right half →
// Minimum is always at start of right half

// Rule:
// if nums[low] <= nums[mid] → in left sorted half
//    → answer could be nums[low], search right half
// if nums[mid] < nums[low]  → in right sorted half
//    → answer could be nums[mid], search left half

int findMin(vector<int>& arr) {
    int n = arr.size();
    int ans = INT_MAX;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[mid]) {
            // left half is sorted
            // smallest in this half is arr[low]
            ans = min(ans, arr[low]);
            low = mid + 1;        // search right half
        } else {
            // right half is sorted
            // smallest in this half is arr[mid]
            ans = min(ans, arr[mid]);
            high = mid - 1;       // search left half
        }
    }

    return ans;
}
