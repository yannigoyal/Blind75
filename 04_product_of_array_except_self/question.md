# Product of Array Except Self

## Problem Statement
Given an integer array nums, return an array answer such that 
answer[i] is equal to the product of all elements except nums[i].
Must run in O(n) time without using division.

## Examples
Input:  nums = [1,2,3,4]          Output: [24,12,8,6]
Input:  nums = [-1,1,0,-3,3]      Output: [0,0,9,0,0]

## Constraints
- 2 <= nums.length <= 10⁵
- -30 <= nums[i] <= 30
- Cannot use division operator
- Must be O(n)

## Approaches Overview
| Approach             | TC    | SC   | Feasible       |
|----------------------|-------|------|----------------|
| Brute Force          | O(n²) | O(1) | ✅             |
| Division (total/num) | O(n)  | O(1) | ❌ not allowed |
| Prefix + Suffix      | O(n)  | O(n) | ✅ Best        |

## Why can't we use Division?
- Seems easy: totalProduct / nums[i]
- But fails when array contains 0
- Also problem explicitly disallows it

## Key Insight: Prefix and Suffix
For each index i:
  answer[i] = product of everything LEFT of i
            * product of everything RIGHT of i

Example: nums = [1, 2, 3, 4]

  prefix  = [1,  1,  2,  6 ]   (product of all elements before i)
  suffix  = [24, 12, 4,  1 ]   (product of all elements after i)
  answer  = [24, 12, 8,  6 ]   (prefix[i] * suffix[i])

## Space Optimization
Instead of 2 separate arrays, reuse result array:
- First pass: store prefix in result[]
- Second pass: multiply suffix on the fly using a variable
- SC goes from O(n) to O(1) (excluding output array)
