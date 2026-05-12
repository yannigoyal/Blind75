/*
Brute Force:
Generate all possible substrings.
Check each substring separately to see if it is a palindrome.
Count all valid palindromic substrings.

TC: O(n^3)
SC: O(1)
*/
class Solution {
public:
    bool isPalindrome(string& str, int left, int right) {
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};
