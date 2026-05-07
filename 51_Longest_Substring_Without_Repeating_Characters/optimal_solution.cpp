/*
Sliding Window + HashMap

Store last index of each character.
If duplicate found, move left pointer after previous occurrence.
Track maximum window length.

TC: O(n)
SC: O(n)
*/
int lengthOfLongestSubstring(string s) {
    int left = 0, maxCount = 0;
    unordered_map<char,int> res;

    for(int i = 0 ;i<s.size();i++) {
        if(res.count(s[i])) {
            left = max(left, res[s[i]] + 1);
        }
        res[s[i]] = i;
        maxCount = max(maxCount, i-left+1);
    }
    return maxCount;
}