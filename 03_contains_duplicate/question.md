# Contains Duplicate

## Problem Statement
Given an integer array nums, return true if any value appears 
at least twice, and false if every element is distinct.

## Examples
Input:  nums = [1,2,3,1]      Output: true
Input:  nums = [1,2,3,4]      Output: false
Input:  nums = [1,1,1,3,3,4,3,2,4,2]  Output: true

## Constraints
- 1 <= nums.length <= 10⁵
- -10⁹ <= nums[i] <= 10⁹

## Approaches Overview
| Approach       | TC       | SC   | Feasible |
|----------------|----------|------|----------|
| Brute Force    | O(n²)    | O(1) | ✅       |
| Sorting        | O(nlogn) | O(1) | ✅       |
| HashSet        | O(n)     | O(n) | ✅ Best  |
