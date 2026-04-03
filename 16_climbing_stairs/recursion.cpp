/*
Approach: Recursion (Brute Force)

Idea:
- At each step, we have two choices:
  1. Take 1 step
  2. Take 2 steps
- So the total ways to reach nth stair = ways(n-1) + ways(n-2)

Base Case:
- If n == 0 or n == 1, return 1
  (There is only one way to stay or take one step)

Problems with this approach:
- Overlapping subproblems:
  Same values are computed multiple times (e.g., f(3) gets recomputed)
- High time complexity:
  O(2^n), since each call branches into two
- Recursion stack space:
  O(n), due to recursive calls

Conclusion:
- This is not optimal and can be improved using Dynamic Programming
*/

int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;

    return climbStairs(n - 1) + climbStairs(n - 2);
}
