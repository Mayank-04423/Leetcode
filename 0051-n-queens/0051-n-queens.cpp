class Solution {
public:
    int n;
    vector<string> board;
    vector<vector<string>> result;
    unordered_set<int> cols, diag1, diag2;

    void solve(int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.count(c) || diag1.count(row - c) || diag2.count(row + c))
                continue;

            board[row][c] = 'Q';
            cols.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            solve(row + 1);

            board[row][c] = '.';
            cols.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.assign(n, string(n, '.'));
        solve(0);
        return result;
    }
};