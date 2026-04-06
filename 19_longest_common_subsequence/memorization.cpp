/*
  Changes from recursion → memoization:

  1. Added DP array: vector<vector<int>> dp(n, vector<int>(m, -1));
  2. Added DP check: if(dp[i][j] != -1)
                        return dp[i][j];
  3. Stored results in DP: return dp[i][j] = ...
  4. Function signature updated: added dp parameter → vector<vector<int>> &dp
  5. Time complexity: O(n * m)
  6. Space Complexity: O(n * m) → dp array, O(n + m) → recursion stack
*/

int f(int  i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        
    if(i == text1.size() || j == text2.size() )
        return 0;
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(text1[i] == text2[j]) {
        return dp[i][j] = 1 + f(i+1, j+1, text1, text2, dp);
    } else {
        return dp[i][j] = max(f(i+1, j,text1, text2,dp), f(i,j+1,text1, text2,dp));
    }
}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(0,0,text1,text2,dp);
}
