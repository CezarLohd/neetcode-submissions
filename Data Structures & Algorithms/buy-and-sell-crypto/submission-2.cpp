class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int lowestp = 102;
        int highestp = 0;

        int psize = prices.size();

        for (int i = 0; i < psize; ++i) {
            if (prices[i] < lowestp) {
                lowestp = prices[i];
                highestp = 0;
            }

            if (prices[i] > highestp) {
                highestp = prices[i];
                if (highestp - lowestp > maxprofit) 
                    maxprofit = highestp - lowestp;
            }
        }
        return maxprofit;
    }
};
