/*
Step 1: Represent problem in terms of index
f(i, j) → LCS of text1 starting from i and text2 starting from j

Step 2: Try all choices
- If characters match:
    take it → 1 + f(i+1, j+1)
- If not match:
    skip one character → max(f(i+1, j), f(i, j+1))

Step 3: Combine results
Take maximum of both choices to get longest subsequence

Base Case:
If i == text1.size() or j == text2.size() → return 0

Time Complexity: O(2^(n+m)) → exponential (all possibilities)

Space Complexity: O(n + m) → recursion stack
*/

int f(int  i, int j, string &text1, string &text2) {
    if(i == text1.size() || j == text2.size() )
    return 0;

    if(text1[i] == text2[j]) {
        return 1 + f(i+1, j+1, text1, text2);
    } else {
        return max(f(i+1, j,text1, text2), f(i,j+1,text1, text2));
    }
}
int longestCommonSubsequence(string text1, string text2) {
    return f(0,0,text1,text2);
}
