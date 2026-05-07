/*
Brute Force

Start from every index and keep adding characters
until a duplicate character is found.
Update max length for every valid substring.

TC: O(n^2)
SC: O(n)
*/
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<char> st;

        for (int j = i; j < n; j++) {
            if (st.count(s[j])) {
                break;
            }

            st.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}