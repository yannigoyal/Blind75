/*
Expand Around Center Approach:

A palindrome mirrors around its center.
So for every index, we try 2 possibilities:

1. Odd Length Palindrome
   Center = single character
   Example: "aba"

2. Even Length Palindrome
   Center = between two characters
   Example: "abba"

From the center, expand left and right
while characters are equal.

Whenever a longer palindrome is found,
update:
- start = starting index
- maxLen = palindrome length

Finally, return substring using
start and maxLen.

TC: O(n^2)
SC: O(1)
*/
class Solution {
public:
    int start = 0;
    int maxLen = 0;
    void expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {

            int len = right - left + 1;

            if (len > maxLen) {
                start = left;
                maxLen = len;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            // Odd length palindrome
            expand(s, i, i);
            // Even length palindrome
            expand(s, i, i + 1);
        }
        return s.substr(start, maxLen);
    }
};
