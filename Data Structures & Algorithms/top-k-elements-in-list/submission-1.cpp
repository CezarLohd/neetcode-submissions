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

        multimap<int, int> freq;

        for (auto& [key, value] : weights) {
            freq.insert({value, key});
        }

        vector<int> answer;

        for (auto iter = freq.rbegin(); iter != freq.rend() && k > 0; ++iter) {
            answer.push_back(iter->second);
            --k;
        }
        return answer;
    }
};
