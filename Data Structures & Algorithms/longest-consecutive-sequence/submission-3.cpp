class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());

        int prev;
        int count = 1;
        int max_count = 0;
        bool first = true;

        for (int& i : nums) {
            if (first) { prev = i; max_count = 1; first = false; continue;}

            if (i == prev) continue;
            
            if (prev + 1 == i) count++;
            else count = 1;

            if (count > max_count) max_count = count;
            prev = i;
        }

        return max_count;
    }
};
