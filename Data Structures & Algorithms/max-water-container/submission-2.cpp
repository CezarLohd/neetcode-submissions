class Solution {
public:
    int maxArea(vector<int>& heights) {
        // 1. nie można tworzyć kontenerów ( O(1) )
        // 2. nie można tego sortować (indeksy są potrzebne)
        
        int max_area = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int hl = heights[l];
            int hr = heights[r];
            
            int area = (r - l) * std::min(hl, hr);
            if (area > max_area) max_area = area;

            if (hl < hr)
                while (l < r && heights[l] <= hl) l++;
            else
                while (l < r && heights[r] <= hr) r--;
        }

        return max_area;
    }
};