/*
    Approach: DFS (Sink the Island)
    --------------------------------
    - Traverse every cell in the grid.
    - Whenever we find a '1' (land), it means a NEW island has started,
      so increment count and run DFS from that cell.
    - DFS visits all 4 connected neighbors (up, down, left, right)
      and marks every visited land as '0' to avoid revisiting
      (this also prevents infinite loops).
    - After DFS, the entire island is "sunk" (converted to water),
      so the outer loop won't count its cells again.

    Key Idea:
    - Outer loop -> finds a new island
    - DFS -> erases that whole island

    TC: O(m * n)  // each cell visited at most once
    SC: O(m * n)  // recursion stack in worst case (all cells are land)
*/
void dfs(int i, int j, int m, int n, vector<vector<char>>& grid) {
    if (i < 0 || j < 0 || i >= m || j >= n) {
        return;
    }
    if (grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';

    dfs(i + 1, j, m, n, grid);
    dfs(i - 1, j, m, n, grid);
    dfs(i, j + 1, m, n, grid);
    dfs(i, j - 1, m, n, grid);
}
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i <= m - 1; i++) {
        for (int j = 0; j <= n - 1; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(i, j, m, n, grid);
            }
        }
    }
    return count;
}
