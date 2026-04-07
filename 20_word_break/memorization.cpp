/*
Step 1: Represent problem in terms of index → f(i) means can we break string from index i to end

Step 2: Try all possibilities → from i to j, take substring and check in dict

Step 3: Combine results → store result in dp[i], if any split works return true

TC: O(n^2)
SC: O(n) + O(n) (rec stack)
*/
bool f(int i, string &s, unordered_set<string> &dict, vector<int> &dp) {
    if(i == s.size()) return true;
    
    if(dp[i]!=-1) return dp[i];

    for(int j=i;j<s.size() ;j++) {
        string temp = s.substr(i,j-i+1);
        if(dict.count(temp) && f(j+1,s,dict,dp)) {
            return dp[i] = 1;
        } 
    }
    return dp[i] = 0;

}
bool wordBreak(string s, vector<string>& wordDict) {
    int n= s.size();
    unordered_set<string> dict(wordDict.begin() ,wordDict.end());
    vector<int> dp(n,-1);

    return f(0,s,dict,dp);
}
