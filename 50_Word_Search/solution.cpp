/*
Backtracking + DFS:
Start DFS from every cell and try to match the word character by character.
Mark visited cells as '#' to avoid reusing them in the same path.
If all characters are matched, return true.

TC: O(m * n * 4^L)
SC: O(L)

m = rows, n = cols, L = word length
*/
bool dfs(int i, int j, int m, int n, vector<vector<char>>& board,
            string word, int k) {
    if (k == word.length())
        return true;

    if (i < 0 || j < 0 || i >= m || j >= n) {
        return false;
    }
    if (board[i][j] != word[k]) {
        return false;
    }
    board[i][j] = '#';
    int res = dfs(i + 1, j, m, n, board, word, k + 1) ||
                dfs(i - 1, j, m, n, board, word, k + 1) ||
                dfs(i, j + 1, m, n, board, word, k + 1) ||
                dfs(i, j - 1, m, n, board, word, k + 1);
    board[i][j] = word[k];
    return res;
}
bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dfs(i, j, row, col, board, word, 0)) {
                return true;
            }
        }
    }
    return false;
}