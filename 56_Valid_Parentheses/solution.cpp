/*
Push opening brackets into stack.
For closing brackets, check top of stack matches or not.
If mismatch or stack becomes empty, return false.
At the end, stack should be empty for valid parentheses.

TC: O(n)
SC: O(n)
*/
bool isValid(string s) {stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty())
                return false;
            char top = st.top();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
            st.pop();
        }
    }
    return st.empty();
}