/*
Sliding Window + Frequency Count

We keep a window [left ... right] and try to make all characters
inside the window the same by replacing at most k characters.

maxFreq = frequency of the most repeated character in current window.

If:
(window size - maxFreq) > k

It means more than k replacements are needed,
so shrink the window from the left.

At every step, store the maximum valid window size.

Example:
s = "AABABBA", k = 1

Window "AABA"
maxFreq = 3 ('A')
window size = 4

4 - 3 = 1 replacement needed -> valid

TC: O(n)
SC: O(1)
*/
int characterReplacement(string s, int k) {
    int freq[26] = {0};

    int maxFreq = 0, ans = 0, left = 0;

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'A']++;

        maxFreq = max(maxFreq, freq[s[i] - 'A']);

        if ((i - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }
        ans = max(ans, i - left + 1);
    }
    return ans;
}