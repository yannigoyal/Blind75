/*
DSA Intuition (Decode Ways - Recursion)

1. Represent:
   - f(i) = number of ways to decode string starting from index i

2. Choices:
   - Take 1 digit → f(i+1)
   - Take 2 digits (if valid 10–26) → f(i+2)

3. Combine:
   - Total ways = sum of all valid choices

TC: O(2^n)   // exponential due to repeated calls
SC: O(n)     // recursion stack

Why MLE?
- This recursion creates many overlapping subproblems.
- Same index is recomputed again and again.
- For input like "111111111111111111111111111111111111111111111"
  (all '1's), every index has 2 choices → forms a recursion tree
  similar to Fibonacci → exponential growth.
- Huge number of calls → memory stack + function calls exceed limit.

👉 Fix: Use Memoization / DP to store results of f(i)
*/
int f(int i, string s) {

    if (i == s.size())
        return 1;
    if (s[i] == '0')
        return 0;

    int ways = 0;
    ways += f(i + 1, s);

    if (i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') >= 10 &&
        (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
        ways += f(i + 2, s);
    }
    return ways;
}
int numDecodings(string s) { return f(0, s); }
