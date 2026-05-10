/*
Convert number into string and use two pointers.
Compare characters from start and end.
If any mismatch found, return false.
If loop completes, number is palindrome.

TC: O(n)
SC: O(n)
*/
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    string str = to_string(x);
    int left = 0, right = str.size() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}