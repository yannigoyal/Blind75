/*
Brute Force Approach:
Try every possible substring using two loops.
For each substring, check if it contains all
characters of string t using a frequency array.

If the substring is valid, update the minimum
length answer.

TC:
- Generating all substrings -> O(n^2)
- Checking each substring -> O(n)
Overall TC: O(n^3)

SC: O(1)
(Frequency array size is fixed: 256)
*/

class Solution {
public:
    bool hasAllChars(string &sub, string &t) {
        int count[256] = {0};
        for (char ch : t)
            count[ch]++;
        for (char ch : sub) {
            if (count[ch] > 0)
                count[ch]--;
        }
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.length();
        int minLen = INT_MAX;
        string res = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                if (hasAllChars(sub, t)) {
                    int currLen = sub.length();
                    if (currLen < minLen) {
                        minLen = currLen;
                        res = sub;
                    }
                }
            }
        }
        return res;
    }
};