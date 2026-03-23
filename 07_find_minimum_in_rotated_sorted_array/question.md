# Find Minimum in Rotated Sorted Array

## Problem Statement
Given a sorted rotated array of unique elements,
return the minimum element. Must run in O(log n).

## Examples
Input:  nums = [3,4,5,1,2]        Output: 1
Input:  nums = [4,5,6,7,0,1,2]    Output: 0
Input:  nums = [11,13,15,17]       Output: 11

## Constraints
- n == nums.length
- 1 <= n <= 5000
- -5000 <= nums[i] <= 5000
- All elements are unique
- Must be O(log n)

## Approaches Overview
| Approach       | TC       | SC   | Feasible  |
|----------------|----------|------|-----------|
| Brute Force    | O(n)     | O(1) | ✅        |
| Binary Search  | O(logn)  | O(1) | ✅ Best   |

## Key Insight (Binary Search)
Array has two sorted halves due to rotation:
[4, 5, 6, 7, | 0, 1, 2]
 left half      right half
 
Minimum is always at the START of the right half (rotation point)

## How to identify which half we are in?
if nums[low] <= nums[mid] → we are in LEFT sorted half
   → minimum is somewhere in right half → low = mid + 1
   → but nums[low] could itself be answer, so track it

if nums[mid] < nums[low] → we are in RIGHT sorted half  
   → minimum is somewhere in left half → high = mid - 1
   → but nums[mid] could itself be answer, so track it

## Dry Run: [4, 5, 6, 7, 0, 1, 2]
low=0 high=6 mid=3 → nums[3]=7
nums[low]=4 <= nums[mid]=7 → left sorted half
ans = min(INT_MAX, 4) = 4 → low = mid+1 = 4

low=4 high=6 mid=5 → nums[5]=1
nums[low]=0 <= nums[mid]=1 → left sorted half  
ans = min(4, 0) = 0 → low = mid+1 =
