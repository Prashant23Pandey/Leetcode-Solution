class Solution {
public:
    int totalNQueens(int n) {
        bitset<10> cols;
        bitset<20> diagonals;
        bitset<20> antiDiagonals;
        int count = 0;  
        function<void(int)> placeQueens = [&](int row) {
            if (row == n) {
                ++count;
                return;
            }
            for (int col = 0; col < n; ++col) {
                int diagonalIdx = row + col;
                int antiDiagonalIdx = row - col + n; 
                if (cols[col] || diagonals[diagonalIdx] || antiDiagonals[antiDiagonalIdx]) {
                    continue;
                }
                cols[col] = true;
                diagonals[diagonalIdx] = true;
                antiDiagonals[antiDiagonalIdx] = true;
                placeQueens(row + 1);
                cols[col] = false;
                diagonals[diagonalIdx] = false;
                antiDiagonals[antiDiagonalIdx] = false;
            }
        };
        placeQueens(0);
        return count;
    }
};