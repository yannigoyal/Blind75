/*
Approach:
We use a frequency array of size n*n + 1 to count how many times each number appears in the grid.

- Traverse the grid and increase freq[value] for each element.
- Then iterate from 1 to n*n:
  - If freq[i] == 2 → this number is repeating.
  - If freq[i] == 0 → this number is missing.

Finally, return {repeating, missing}.

TC: O(n^2)
SC: O(n^2)
*/
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> freq(n * n + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            freq[grid[i][j]]++;
        }
    }
    vector<int> ans(2);
    for (int i = 1; i <= n * n; i++) {
        if (freq[i] == 2)
            ans[0] = i;

        if (freq[i] == 0)
            ans[1] = i;
    }
    return ans;
}
