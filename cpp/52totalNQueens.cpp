class Solution {
private:
    int res = 0;
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) { res++; return; }
        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col)) continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // �����
        for (int i = 0; i < n; i++)
            if (board[i][col] == 'Q') return false;
        // ������Ϸ�
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        // ������Ϸ�
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        return true;
    }
};