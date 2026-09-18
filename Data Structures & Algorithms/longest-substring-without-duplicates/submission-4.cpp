class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int maxlen = 0;
        unordered_map<char, int> chars; // key - char from s, value - its id 
        chars.reserve(s.size());

        for (int l = 0, r = 0; r < s.size(); ++r) {

            if ( chars.contains(s[r]) ) {
                int target = chars[s[r]];
                for (; l <= target; ++l)
                    chars.erase(s[l]);
            }

            chars.insert({s[r], r});
            if (r - l + 1 > maxlen) maxlen = r - l + 1; 
        }

        return maxlen;
    }
};
