/*
DSA Intuition (Decode Ways - Memoization)

1. Represent:
   - f(i) = number of ways to decode string starting from index i

2. Choices:
   - Take 1 digit → f(i+1)
   - Take 2 digits (if valid 10–26) → f(i+2)

3. Combine:
   - Total ways = sum of valid choices
   - Use dp[i] to store result and avoid recomputation

TC: O(n)
SC: O(n)  // dp + recursion stack
*/
int f(int i, string s, vector<int> &dp) {
    if (i == s.size())
        return 1;
    if(dp[i] != -1) {
        return dp[i];
    }
    if (s[i] == '0')
        return 0;

    int ways = 0;
    ways += f(i + 1, s, dp);

    if (i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') >= 10 &&
        (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
        ways += f(i + 2, s,dp);
    }
    return dp[i] = ways;
}
int numDecodings(string s) { 
    int n = s.size();
    vector<int> dp(n,-1);
    return f(0, s, dp); 
}
