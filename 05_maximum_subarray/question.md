# Maximum Subarray

## Problem Statement
Given an integer array nums, find the subarray with the largest 
sum and return its sum.

## Examples
Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]   Output: 6   → [4,-1,2,1]
Input:  nums = [1]                         Output: 1   → [1]
Input:  nums = [5,4,-1,7,8]               Output: 23  → [5,4,-1,7,8]

## Constraints
- 1 <= nums.length <= 10⁵
- -10⁴ <= nums[i] <= 10⁴

## Approaches Overview
| Approach        | TC    | SC   | Feasible  |
|-----------------|-------|------|-----------|
| Brute Force     | O(n³) | O(1) | ✅        |
| Better          | O(n²) | O(1) | ✅        |
| Kadane's Algo   | O(n)  | O(1) | ✅ Best   |

## Key Insight (Kadane's)
If running sum goes negative, it will only hurt future subarrays
So reset sum to 0 and start fresh from next element
