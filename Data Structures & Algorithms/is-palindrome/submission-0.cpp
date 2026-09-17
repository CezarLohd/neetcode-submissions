class Solution {
public:
    bool isPalindrome(string s) {
        erase_if(s, [](unsigned char c) {
            return !std::isalnum(c);
        });

        for (int i = 0; i < s.size() / 2; ++i)
            if (tolower(s[i]) != tolower(s[s.size() - i - 1])) return false;
        
        return true;
    }
};
