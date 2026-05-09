/*
Store frequency of every character from both strings
using two arrays of size 26.

First check:
If lengths are different, they can never be anagrams.

Then:
Increase character count for both strings.
Example:
"aab" -> a = 2, b = 1

Finally:
Compare both frequency arrays.
If any count is different, return false.
Otherwise both strings are anagrams.

TC: O(n)
SC: O(1)
*/
bool isAnagram(string s, string t) {
    int freqS[26] = {0}, freqT[26] = {};
    int lenOfS = s.length(), lenOfT = t.length();
    if (lenOfS != lenOfT) {
        return false;
    }
    for(int i = 0; i<lenOfS;i++) {
        freqS[s[i]-'a']++;
        freqT[t[i]-'a']++;
    }

    for(int i = 0; i < 26;i++) {
        if(freqS[i] != freqT[i])    {
            return false;
        }
    }

    return true;
}