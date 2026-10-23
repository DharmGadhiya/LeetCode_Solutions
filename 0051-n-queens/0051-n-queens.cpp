class Solution {
public:
    vector<vector<string>> ans;

    bool safe(vector<string>& board, int r, int c, int n) {
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 'Q')
                return false;

            if (c - (r - i) >= 0 && board[i][c - (r - i)] == 'Q')
                return false;

            if (c + (r - i) < n && board[i][c + (r - i)] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int r, int n) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (safe(board, r, c, n)) {
                board[r][c] = 'Q';

                solve(board, r + 1, n);

                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string> board(n, string(n, '.'));

        solve(board, 0, n);

        return ans;
    }
};