class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int lowestp = 102;

        int psize = prices.size();

        for (int i = 0; i < psize; ++i) {
            if (prices[i] < lowestp)
                lowestp = prices[i];
            else if (prices[i] - lowestp > maxprofit) 
                maxprofit = prices[i] - lowestp;
        }
        return maxprofit;
    }
};
