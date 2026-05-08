class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        auto dfs = [&](this auto&& dfs, int row, int col) -> int {
            if (row >= rows || col >= cols || obstacleGrid[row][col] == 1) {
                return 0;
            }
            if (row == rows - 1 && col == cols - 1) {
                return 1;
            }
            if (memo[row][col] == -1) {
                memo[row][col] = dfs(row + 1, col) + dfs(row, col + 1);
            }
          
            return memo[row][col];
        };
        return dfs(0, 0);
    }
};
