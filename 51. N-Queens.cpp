class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> colOccupied(n);
        vector<int> diagonalOccupied(n << 1);
        vector<int> antiDiagonalOccupied(n << 1);
        vector<vector<string>> result;
        vector<string> currentBoard(n, string(n, '.'));
        function<void(int)> backtrack = [&](int row) -> void {
            if (row == n) {
                result.push_back(currentBoard);
                return;
            }
            for (int col = 0; col < n; ++col) {
                if (colOccupied[col] + diagonalOccupied[row + col] + 
                    antiDiagonalOccupied[n - row + col] == 0) {
                    currentBoard[row][col] = 'Q';
                    colOccupied[col] = 1;
                    diagonalOccupied[row + col] = 1;
                    antiDiagonalOccupied[n - row + col] = 1;
                    backtrack(row + 1);
                    colOccupied[col] = 0;
                    diagonalOccupied[row + col] = 0;
                    antiDiagonalOccupied[n - row + col] = 0;
                    currentBoard[row][col] = '.';
                }
            }
        };
        backtrack(0);
        return result;
    }
};
