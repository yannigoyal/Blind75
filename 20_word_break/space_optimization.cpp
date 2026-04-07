/*
Step 1: same dp[i] meaning → can break from i

Step 2: reduce extra usage → only 1D dp used

Step 3: reuse dp array efficiently

TC: O(n^2)
SC: O(n)
*/

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    
    vector<bool> dp(n+1, false);
    dp[n] = true;

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(dict.count(s.substr(i, j-i+1)) && dp[j+1]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0];
}
