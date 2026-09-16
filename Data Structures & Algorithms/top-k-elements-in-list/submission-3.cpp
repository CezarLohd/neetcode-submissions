class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int weights[2001] = {0};
        for (int i : nums)
            weights[i + 1000]++; 


        vector<vector<int>> buckets(nums.size() + 1);

        for (int i = 0; i < 2001; ++i)
            if (weights[i] > 0)
                buckets[weights[i]].push_back(i - 1000); 

        vector<int> answer;
        answer.reserve(k);

        for (auto iter = buckets.rbegin(); iter != buckets.rend() && k > 0; ++iter) {
            for (int& num : *iter) {
                answer.push_back(num);
                --k;
            }
            
        }

        return answer;
    }
};
