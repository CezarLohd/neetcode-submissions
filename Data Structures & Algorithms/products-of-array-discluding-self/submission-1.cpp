class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> solution;
        solution.reserve(nums.size());
        int product = 1;
        int zeros = 0;

        for (int i : nums)
            if (i == 0) ++zeros;
            else product *= i;
        
        for (int i : nums)
            if (zeros > 1) 
                solution.push_back(0);
            else if (zeros == 1)
                solution.push_back(i == 0 ? product : 0);
            else
                solution.push_back(product / i);
        
        return solution;
    }
};
// optimal memory efficiency