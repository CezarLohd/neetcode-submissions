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

            if (height[l] <= height[r]) solution += maxl - height[l++];
            else solution += maxr - height[r--];
        }

        return solution;
    }
};
