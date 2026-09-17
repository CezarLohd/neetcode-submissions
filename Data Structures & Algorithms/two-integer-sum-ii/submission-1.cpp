//gemini mowi ze to bedzie szybsze, zobaczymy

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }

            if (sum < target) {
                int current = numbers[left];
                while (left < right && numbers[left] == current) ++left;
            } else {
                int current = numbers[right];
                while (left < right && numbers[right] == current) --right;
            }
        }

        return {};
    }
};

// Opcjonalnie: odpięcie I/O przed mainem
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();