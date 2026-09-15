class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> pastNums;

        for (int i : nums) {
            if (pastNums.contains(i)) return true;

            pastNums.insert(i);
        }
        return false;
    }
};