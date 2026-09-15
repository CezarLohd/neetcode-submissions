class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<int,int> map;
        map.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            if (map.contains(comp)) return {map[comp], i};
            map[nums[i]] = i;
        }
        return {};
    }
};