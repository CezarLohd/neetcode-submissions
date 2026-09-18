class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int maxlen = 0;
        string substr;
        substr.reserve(s.size());

        for(char& ch : s) {
            if (substr.contains(ch))
                substr.erase(0, substr.find(ch) + 1);

            substr += ch;
            if(substr.size() > maxlen) maxlen = substr.size();
        }

        cout << substr;

        return maxlen;
    }
};
