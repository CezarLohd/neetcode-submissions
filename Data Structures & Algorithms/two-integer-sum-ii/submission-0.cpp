class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (auto left = numbers.begin(), right = numbers.end() - 1; left < right;) {
            int now = *left + *right;

            if (now > target) --right;
            else if (now < target) ++left;
            else return {(int)(left - numbers.begin() + 1), (int)(right - numbers.begin() + 1)};
        }
        return {};
    }
};
