/*
Sort both strings and compare them.
If both become equal after sorting, then they are anagrams.

TC: O(n log n)
SC: O(1)
*/
bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s==t;
}