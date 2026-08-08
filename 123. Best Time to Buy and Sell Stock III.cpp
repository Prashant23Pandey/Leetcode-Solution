class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = -prices[0];
        int firstSell = 0;
        int secondBuy = -prices[0];
        int secondSell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            firstBuy = max(firstBuy, -prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            secondBuy = max(secondBuy, firstSell - prices[i]);
            secondSell = max(secondSell, secondBuy + prices[i]);
        }
        return secondSell;
    }
};
