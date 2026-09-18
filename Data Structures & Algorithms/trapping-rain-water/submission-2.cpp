class Solution {
public:
    int trap(vector<int>& height) {
        // teraz sprobuje two pointers zrobic
        int hsize = height.size();
        int solution = 0;
        int maxl = 0, maxr = 0;

        for (int l = 0, r = hsize - 1; l < r;) {
            if (height[l] > maxl) maxl = height[l];
            if (height[r] > maxr) maxr = height[r];

            solution += min(maxl, maxr) - height[l] > 0 ? min(maxl, maxr) - height[l] : 0;
            solution += min(maxl, maxr) - height[r] > 0 ? min(maxl, maxr) - height[r] : 0;
            
            if (maxl > maxr) --r;
            else ++l;
        }

        return solution;
    }
};
