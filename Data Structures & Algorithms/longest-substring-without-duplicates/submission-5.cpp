#include <cstring>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int maxlen = 0;
        int chars[256]; // indexes for every char possible 
        memset(chars, -1, sizeof(chars));

        for (int l = 0, r = 0; r < s.size(); ++r) {

            if ( chars[s[r]] != -1 ) {
                int target = chars[s[r]];
                for (; l <= target; ++l)
                    chars[s[l]] = -1;
            }

            chars[s[r]] = r;
            if (r - l + 1 > maxlen) maxlen = r - l + 1; 
        }

        return maxlen;
    }
};
