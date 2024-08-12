class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        
        if (prices.empty() || prices.size() == 1) return 0;
        
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(prices[i], minPrice); // set buy day to day with lowest price
            maxProfit = max(prices[i] - minPrice, maxProfit); // keep track of historical max profit
        }

        return maxProfit;
    }
};