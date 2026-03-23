# Maximum Product Subarray

## Problem Statement
Given an integer array nums, find a subarray that has the 
largest product and return the product.

## Examples
Input:  nums = [2,3,-2,4]    Output: 6   → [2,3]
Input:  nums = [-2,0,-1]     Output: 0   → [0]

## Constraints
- 1 <= nums.length <= 2 * 10⁴
- -10 <= nums[i] <= 10
- Answer fits in 32-bit integer

## Approaches Overview
| Approach            | TC    | SC   | Feasible  |
|---------------------|-------|------|-----------|
| Brute Force         | O(n²) | O(1) | ✅        |
| Prefix-Suffix       | O(n)  | O(1) | ✅ Best   |

## Why is this harder than Maximum Subarray (sum)?
- For sum  → negative always hurts  → just reset to 0
- For product → negative * negative = positive (could be answer!)
- So we CANNOT simply reset when product goes negative

## Key Observations for Prefix-Suffix approach

### Observation 1: Zero resets everything
- Any subarray containing 0 has product 0
- So 0 acts as a divider → split array at zeros
- Reset prefix/suffix to 1 when they hit 0

### Observation 2: Negative numbers
- Odd count of negatives  → total product is negative
- Even count of negatives → total product is positive
- Maximum product subarray avoids odd count of negatives
- Either exclude leftmost negative  (suffix handles this)
- Or exclude rightmost negative     (prefix handles this)

### Observation 3: Why prefix AND suffix?
nums = [2, 3, -2, 4]
prefix products: 2, 6, -12, -48   → max = 6  ✅
suffix products: 4, -8, -24, -48  → max = 4

nums = [-2, -3, -2]
prefix products: -2,  6,  -12    → max = 6  ✅
suffix products: -2, -6,  -12    → max = -2
→ prefix catches the answer here

nums = [-2, 3, -2]
prefix products: -2, -6,  12    → max = 12 ✅
suffix products: -2, -6,  -12   → max = -2
→ prefix catches it by excluding leftmost negative

## Dry Run: nums = [2, 3, -2, 4]
i=0: pref=2,   suff=4,   max=4
i=1: pref=6,   suff=-8,  max=6
i=2: pref=-12, suff=-24, max=6
i=3: pref=-48, suff=-48, max=6
answer = 6 ✅

## Dry Run: nums = [-2, 0, -1]
i=0: pref=-2,  suff=-1,  max=-1
i=1: pref=0→1, suff=0→1, max=-1   (reset on 0)
i=2: pref=-2,  suff=-2,  max=0
answer = 0 ✅
