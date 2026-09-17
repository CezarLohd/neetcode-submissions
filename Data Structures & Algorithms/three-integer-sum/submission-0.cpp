class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;

        std::sort(nums.begin(), nums.end());

        auto size = nums.size();

        for (int i = 0; i < size; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int l = i + 1, p = size - 1; l < p;) {
                int sum = nums[i] + nums[l] + nums[p];

                if (sum > 0) --p;
                else if (sum < 0) ++l;
                else {
                    solution.push_back({nums[l], nums[i], nums[p]});
                    while (l < p && nums[l] == nums[l + 1]) ++l;
                    while (l < p && nums[p] == nums[p - 1]) --p;
                    ++l;
                    --p;
                }
            }
        }
        return solution;
    }
};
