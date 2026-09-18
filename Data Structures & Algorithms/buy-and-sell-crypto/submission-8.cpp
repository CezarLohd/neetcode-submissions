class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

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
