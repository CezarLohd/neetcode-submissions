class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> weights;
        for (int i : nums) {
            if (weights.contains(i))
                ++weights[i];
            else 
                weights.insert({i, 1});
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& [key, value] : weights) {
            buckets[value].push_back(key);
        }

        vector<int> answer;

        for (auto iter = buckets.rbegin(); iter != buckets.rend() && k > 0; ++iter) {
            for (int& num : *iter) {
                answer.push_back(num);
                --k;
            }
            
        }

        return answer;
    }
};
