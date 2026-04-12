/*
DSA Intuition (Unique Paths)

1. Represent:
   - f(i, j) = number of ways to reach destination from (i, j)

2. Choices:
   - Right  → f(i, j+1)
   - Down   → f(i+1, j)

3. Combine:
   - ways = f(i, j+1) + f(i+1, j)

--------------------------------------------------
Recursion
TC: O(2^(m*n))   // exponential (overlapping subproblems)
SC: O(m+n)
*/

int f(int i, int j, int m, int n) {
    // base cases
    if (i >= m || j >= n) return 0;          // out of bound
    if (i == m-1 && j == n-1) return 1;      // destination

    // choices
    int right = f(i, j+1, m, n);
    int down  = f(i+1, j, m, n);

    // combine
    return right + down;
}

int uniquePaths(int m, int n) {
    return f(0, 0, m, n);
}

