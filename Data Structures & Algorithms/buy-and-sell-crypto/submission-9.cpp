class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int lowestp = 102;

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < lowestp)
                lowestp = prices[i];
            else if (prices[i] - lowestp > maxprofit) 
                maxprofit = prices[i] - lowestp;
        }
        return maxprofit;
    }
};
