class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty() || prices.size() <= 1)
            return 0;
        
        int total = prices.size();
        int buy[total];
        int sell[total];
        
        //buy[i] = max profit if he decides to buy at i day
        //sell[i] = max profit if he decides to sell at day i
        
        //buy[i] = sell[i-2] - prices[i] OR buy[i-1]
        //sell[i] = sell[i-1] OR prices[i] + buy[i-1]
        
        buy[0] = -prices[0];
        sell[0] = 0;
        
        for (int i = 1; i < total; i++) {
            buy[i] = std::max(sell[i-2] - prices[i], buy[i-1]);
            sell[i] = std::max(sell[i-1], prices[i] + buy[i-1]);
        }
        
        return sell[total-1];
        
    }
};
