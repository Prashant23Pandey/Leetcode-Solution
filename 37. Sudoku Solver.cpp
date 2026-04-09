class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { 
        bool rowUsed[9][9] = {false};
        bool colUsed[9][9] = {false};
        bool blockUsed[3][3][9] = {false};
        bool solutionFound = false;
        vector<pair<int, int>> emptyCells;
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    emptyCells.push_back({row, col});
                } else {
                    int digit = board[row][col] - '1'; 
                    rowUsed[row][digit] = true;
                    colUsed[col][digit] = true;
                    blockUsed[row / 3][col / 3][digit] = true;
                }
            }
        }
        function<void(int)> backtrack = [&](int cellIndex) {
            if (cellIndex == emptyCells.size()) {
                solutionFound = true;
                return;
            }
            int currentRow = emptyCells[cellIndex].first;
            int currentCol = emptyCells[cellIndex].second;
            int blockRow = currentRow / 3;
            int blockCol = currentCol / 3;
            for (int digit = 0; digit < 9; ++digit) {
                if (!rowUsed[currentRow][digit] && 
                    !colUsed[currentCol][digit] && 
                    !blockUsed[blockRow][blockCol][digit]) {
                    rowUsed[currentRow][digit] = true;
                    colUsed[currentCol][digit] = true;
                    blockUsed[blockRow][blockCol][digit] = true;
                    board[currentRow][currentCol] = digit + '1'; 
                    backtrack(cellIndex + 1);
                    if (solutionFound) {
                        return;
                    }
                    rowUsed[currentRow][digit] = false;
                    colUsed[currentCol][digit] = false;
                    blockUsed[blockRow][blockCol][digit] = false;
                }
            }
        };
        backtrack(0);
    }
};