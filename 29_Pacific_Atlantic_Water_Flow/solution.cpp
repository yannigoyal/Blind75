/*
 * Pacific Atlantic Water Flow
 *
 * INTUITION:
 * Water flows downhill (or equal height).
 * We need cells where water can reach BOTH oceans.
 *
 * BRUTE FORCE IDEA (too slow):
 * For every cell, run DFS and check if it reaches
 * both oceans. O(m*n)^2 — too expensive.
 *
 * BETTER APPROACH (reverse DFS):
 * Instead of going ocean → cell (downhill),
 * we go border → inland (uphill/equal allowed).
 * This way we only do DFS twice total.
 *
 * HOW IT WORKS:
 * 1. Pacific borders = top row + left col
 *    Start DFS from all these cells → mark pacific[][]
 *
 * 2. Atlantic borders = bottom row + right col
 *    Start DFS from all these cells → mark atlantic[][]
 *
 * 3. Scan every cell — if pacific[i][j] == 1
 *    AND atlantic[i][j] == 1 → add to answer.
 *
 * WHY REVERSE WORKS:
 * Normal:  water flows high → low  (downhill)
 * Reverse: we walk  low  → high  (uphill)
 * Same reachability, but now we start from borders
 * so we never repeat work.
 *
 * TC: O(m * n)  — each cell visited at most twice
 * SC: O(m * n)  — pacific + atlantic visited grids
 */
 
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

    vector<vector<int>> ans;
    if(heights.empty()) return ans;

    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> pacific(m, vector<int>(n, 0));
    vector<vector<int>> atlantic(m, vector<int>(n, 0));

    // Pacific (top + left)
    for(int col = 0; col < n; col++) {
        fnc(heights, 0, col, INT_MIN, pacific);
        fnc(heights, m-1, col, INT_MIN, atlantic);
    }

    for(int row = 0; row < m; row++) {
        fnc(heights, row, 0, INT_MIN, pacific);
        fnc(heights, row, n-1, INT_MIN, atlantic);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(pacific[i][j] && atlantic[i][j]) {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}
void fnc(vector<vector<int>>& heights, int i, int j, int prev,
         vector<vector<int>>& ocean) {

    int m = heights.size();
    int n = heights[0].size();

    if(i < 0 || j < 0 || i >= m || j >= n)
        return;

    if(ocean[i][j] == 1)
        return;

    if(heights[i][j] < prev)
        return;

    ocean[i][j] = 1;

    fnc(heights, i+1, j, heights[i][j], ocean);
    fnc(heights, i-1, j, heights[i][j], ocean);
    fnc(heights, i, j+1, heights[i][j], ocean);
    fnc(heights, i, j-1, heights[i][j], ocean);
}
