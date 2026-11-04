class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
      
        // dp[day][transactions_left][holding_stock]
        // dp[i][j][hold]: max profit at day i with j transactions left and hold status
        // hold = 1: currently holding stock, hold = 0: not holding stock
        int dp[n][k + 1][2];
        memset(dp, -1, sizeof(dp));
      
        // Recursive function with memoization
        // day: current day index
        // transactionsLeft: remaining transactions allowed
        // holdingStock: 1 if currently holding stock, 0 otherwise
        function<int(int, int, int)> dfs = [&](int day, int transactionsLeft, int holdingStock) -> int {
            // Base case: no more days left
            if (day >= n) {
                return 0;
            }
          
            // Return memoized result if already calculated
            if (dp[day][transactionsLeft][holdingStock] != -1) {
                return dp[day][transactionsLeft][holdingStock];
            }
          
            // Option 1: Do nothing today (skip to next day)
            int maxProfit = dfs(day + 1, transactionsLeft, holdingStock);
          
            if (holdingStock) {
                // Currently holding stock: can sell today
                // Selling completes a transaction (no change in transaction count)
                maxProfit = max(maxProfit, prices[day] + dfs(day + 1, transactionsLeft, 0));
            } else if (transactionsLeft > 0) {
                // Not holding stock and have transactions left: can buy today
                // Buying starts a new transaction (decrement transaction count)
                maxProfit = max(maxProfit, -prices[day] + dfs(day + 1, transactionsLeft - 1, 1));
            }
          
            // Memoize and return the result
            return dp[day][transactionsLeft][holdingStock] = maxProfit;
        };
      
        // Start from day 0, with k transactions available, not holding any stock
        return dfs(0, k, 0);
    }
};
