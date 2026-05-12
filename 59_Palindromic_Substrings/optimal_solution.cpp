/*
Expand Around Center:
Treat every index as the center of a palindrome.
Check both odd length (i,i) and even length (i,i+1) palindromes.
Expand outward while characters match and count all valid palindromes.

TC: O(n^2)
SC: O(1)
*/
class Solution {
public:
    int expand(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count += expand(s, i, i);
            count += expand(s, i, i + 1);
        }
        return count;
    }
};