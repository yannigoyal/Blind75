/*
Convert number into string and create its reverse.
Compare original string with reversed string.
If both are same, number is palindrome.

TC: O(n)
SC: O(n)
*/
bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }
    string ori = to_string(x);
    string rev = ori;
    reverse(rev.begin(), rev.end());

    return rev == ori;
}