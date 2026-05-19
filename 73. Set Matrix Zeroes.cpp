class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        vector<bool> rowHasZero(rowCount, false);
        vector<bool> colHasZero(colCount, false);
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < colCount; ++col) {
                if (matrix[row][col] == 0) {
                    rowHasZero[row] = true;
                    colHasZero[col] = true;
                }
            }
        }
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < colCount; ++col) {
                if (rowHasZero[row] || colHasZero[col]) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};