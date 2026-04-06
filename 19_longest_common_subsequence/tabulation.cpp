/*
Step 1: Represent problem in terms of index
dp[i][j] → LCS of text1 starting from index i and text2 starting from index j

Step 2: Try all choices
- If characters match:
    dp[i][j] = 1 + dp[i+1][j+1]
- If not match:
    dp[i][j] = max(dp[i+1][j], dp[i][j+1])

Step 3: Combine results
Store the result directly in dp table (bottom-up)

Base Case:
dp[n][*] = 0 and dp[*][m] = 0
(If any string is exhausted → LCS = 0)

Filling Order:
Fill dp from bottom-right → top-left
(because dp[i] depends on future states)

Time Complexity: O(n * m)

Space Complexity: O(n * m)
*/

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[0][0];
}
