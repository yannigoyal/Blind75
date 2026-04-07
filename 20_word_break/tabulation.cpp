/*
Step 1: dp[i] → can we break string from index i to end

Step 2: iterate i from n-1 → 0 and try all j from i → n-1

Step 3: if substring valid and dp[j+1] true → dp[i] = true

TC: O(n^2)
SC: O(n)
*/

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    
    vector<int> dp(n+1, 0);
    dp[n] = 1; // base case

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            string temp = s.substr(i, j-i+1);
            if(dict.count(temp) && dp[j+1]) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[0];
}
