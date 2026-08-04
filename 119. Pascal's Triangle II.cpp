class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for (int currentRow = 2; currentRow <= rowIndex; ++currentRow) {
            for (int col = currentRow - 1; col > 0; --col) {
                row[col] += row[col - 1];
            }
        }
        return row;
    }
};
