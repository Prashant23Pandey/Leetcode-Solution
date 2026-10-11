class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
      
        // Create DP table with extra row and column for boundary conditions
        // dp[i][j] represents minimum health required to reach bottom-right from cell (i,j)
        int dp[rows + 1][cols + 1];
      
        // Initialize all cells with a large value (infinity)
        memset(dp, 0x3f, sizeof(dp));
      
        // Set boundary conditions: we need at least 1 HP to enter the princess cell
        // These serve as base cases for cells adjacent to bottom-right corner
        dp[rows][cols - 1] = 1;  // Cell below the bottom-right corner
        dp[rows - 1][cols] = 1;  // Cell to the right of bottom-right corner
      
        // Fill the DP table from bottom-right to top-left
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                // Calculate minimum HP needed at current cell
                // We can move either right (dp[i][j+1]) or down (dp[i+1][j])
                int minHealthRequired = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
              
                // Health must be at least 1 to stay alive
                dp[i][j] = max(1, minHealthRequired);
            }
        }
      
        // Return minimum initial HP required to start from top-left corner
        return dp[0][0];
    }
};
