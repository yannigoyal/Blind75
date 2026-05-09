/*
Sliding Window Approach:
Use two pointers (left & right) to create a window.
Expand the window by moving right pointer and keep
track of character frequencies.

When the window contains all characters of t,
try to shrink it from the left to get the
minimum valid substring.

Store the smallest valid window answer.

TC: O(n)
SC: O(1)
*/
string minWindow(string s, string t) {
    unordered_map<char, int> freq;

    for (char ch : t) {
        freq[ch]++;
    }
    int left = 0, right = 0, count = 0, minLen = INT_MAX, startIndex = 0;

    while (right < s.size()) {
        char ch = s[right];

        if (freq[ch] > 0) {
            count++;
        }

        freq[ch]--;
        while (count == t.length()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIndex = left;
            }

            char leftChar = s[left];

            freq[leftChar]++;

            if (freq[leftChar] > 0) {
                count--;
            }
            left++;
        }
        right++;
    }
    if (minLen == INT_MAX) {
        return "";
    }
    return s.substr(startIndex, minLen);
}