/*
Step 1: Represent problem in terms of index → f(i) means can we break string from index i to end

Step 2: Try all possibilities → from i to j, take substring and check if it exists in dict

Step 3: Combine results → if any valid split gives true, return true

TC: O(2^n * n)
SC: O(n)
*/

bool f(int i, string &s, unordered_set<string> &dict) {
    if(i == s.size()) return true;
    
    for(int j=i;j<s.size() ;j++) {
        string temp = s.substr(i,j-i+1);
        if(dict.count(temp) && f(j+1,s,dict)) {
            return true;
        } 
    }
    return false;

}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin() ,wordDict.end());
    return f(0,s,dict);
}
