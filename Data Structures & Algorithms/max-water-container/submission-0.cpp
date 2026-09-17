class Solution {
public:
    int maxArea(vector<int>& heights) {
        // 1. nie można tworzyć kontenerów ( O(1) )
        // 2. nie można tego sortować (indeksy są potrzebne)

        int max_area = 0;

        int size = heights.size();

        for (int l = 0, r = size - 1; l < r;) {
            int area = (r - l) * min(heights[r],heights[l]);

            if (area > max_area) max_area = area;

            if (heights[l] < heights[r])
                l++;
            else
                r--;
        }

        return max_area;

    }
};
