/*
Brute Force Approach:

Generate all possible substrings
using two loops.

For every substring:
- Check if it is a palindrome
  using two pointers.
- If palindrome and length is greater
  than current answer, update ans.

Palindrome Check:
Compare characters from left and right.
If mismatch occurs, return false.
If all characters match, it is a palindrome.

TC: O(n^3)
SC: O(1)
*/
bool isPalindrome(string str) {
       int left = 0;
       int right = str.size() - 1;
       while (left < right) {
           if (str[left] != str[right]) {
               return false;
           }
           left++;
           right--;
       }
       return true;
}


string longestPalindrome(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        string str = "";
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            if (isPalindrome(str) && str.size() > ans.size()) {
                ans = str;
            }
        }
    }


    return ans;
}
