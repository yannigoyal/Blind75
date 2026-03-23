// ============================================
// SEARCH IN ROTATED SORTED ARRAY - OPTIMAL
// TC: O(logn)  SC: O(1)
// ============================================

// Why NOT linear scan?
// - O(n), problem demands O(logn)
// - Not using sorted property at all

// Why NOT normal binary search?
// - Normal BS only works on fully sorted array
// - Rotated array breaks the sorted property
// - Need to identify which half is sorted first

// Key Insight:
// In any rotated array, at least ONE half is always sorted
// Use that sorted half to check if target lies in it
// If yes → search that half
// If no  → search the other half

// CASE 1: Left sorted  → nums[low] <= nums[mid]
//   target in left?    → nums[low] <= target < nums[mid]
//   yes → high=mid-1   no → low=mid+1

// CASE 2: Right sorted → nums[mid] < nums[low]
//   target in right?   → nums[mid] < target <= nums[high]
//   yes → low=mid+1    no → high=mid-1

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // found target
        if (nums[mid] == target) {
            return mid;
        }

        // CASE 1: left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;    // target in left half
            } else {
                low = mid + 1;     // target in right half
            }
        }
        // CASE 2: right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;     // target in right half
            } else {
                high = mid - 1;    // target in left half
            }
        }
    }

    return -1;
}
