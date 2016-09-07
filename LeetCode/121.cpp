class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int lowest = prices[0];
        int best = -1000000000;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
            }
            if (prices[i] - lowest > best)
                best = prices[i] - lowest;
        }
        return best;
    }
};
