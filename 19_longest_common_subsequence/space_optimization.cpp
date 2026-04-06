/*
Step 1: Represent problem in terms of index
We optimize space by using 1D arrays:
next[j] → represents dp[i+1][j]
curr[j] → represents dp[i][j]

Step 2: Try all choices
- If characters match:
    curr[j] = 1 + next[j+1]
- If not match:
    curr[j] = max(next[j], curr[j+1])

Step 3: Combine results
Store result in curr[j] and after each row update:
    next = curr

Base Case:
Initially next[] is filled with 0
(represents dp[n][*] = 0)

Filling Order:
Traverse from bottom → top (i)
and right → left (j)

Time Complexity: O(n * m)

Space Complexity: O(m) → optimized from O(n * m)
*/
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<int> next(m + 1, 0), curr(m + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                curr[j] = 1 + next[j + 1];
            } else {
                curr[j] = max(next[j], curr[j + 1]);
            }
        }
        next = curr;
    }

    return next[0];
}
