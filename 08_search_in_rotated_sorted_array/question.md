# Search in Rotated Sorted Array

## Problem Statement
Given a rotated sorted array of distinct values and a target,
return the index of target or -1 if not found.
Must run in O(log n).

## Examples
Input: nums = [4,5,6,7,0,1,2], target = 0   Output: 4
Input: nums = [4,5,6,7,0,1,2], target = 3   Output: -1
Input: nums = [1],             target = 0   Output: -1

## Constraints
- 1 <= nums.length <= 5000
- -10⁴ <= nums[i] <= 10⁴
- All values are distinct
- Must be O(log n)

## Approaches Overview
| Approach      | TC      | SC   | Feasible  |
|---------------|---------|------|-----------|
| Brute Force   | O(n)    | O(1) | ✅        |
| Binary Search | O(logn) | O(1) | ✅ Best   |

## Key Insight (Binary Search)
Even in a rotated array, ONE half is always sorted.
Use that to decide which half target can be in.

## How to identify which half and where target is?

CASE 1: Left half is sorted (nums[low] <= nums[mid])
   → Check if target lies in left half range:
     if nums[low] <= target < nums[mid]  → go left  (high = mid-1)
     else                                → go right (low  = mid+1)

CASE 2: Right half is sorted (nums[mid] < nums[low])
   → Check if target lies in right half range:
     if nums[mid] < target <= nums[high] → go right (low  = mid+1)
     else                                → go left  (high = mid-1)

## Dry Run: nums = [4,5,6,7,0,1,2], target = 0
low=0 high=6 mid=3 → nums[3]=7
nums[low]=4 <= nums[mid]=7 → left sorted half
target=0, is 4<=0<7? NO → go right → low = 4

low=4 high=6 mid=5 → nums[5]=1
nums[low]=0 <= nums[mid]=1 → left sorted half
target=0, is 0<=0<1? YES → go left → high = 4

low=4 high=4 mid=4 → nums[4]=0
nums[mid] == target → return 4 ✅

## Difference from Find Minimum problem?
| Find Minimum          | Search in Rotated          |
|-----------------------|----------------------------|
| Find rotation point   | Find a specific target     |
| Track ans = min       | Return index if found      |
| Always pick min side  | Pick side based on target  |
