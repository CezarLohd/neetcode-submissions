class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char,int> s_chars;
        unordered_map<char,int> t_chars;

        for (char& ch : s) {
            if (!s_chars.contains(ch)) 
                s_chars.insert({ch, 1});
            else
                ++s_chars[ch];
        }

        for (char& ch : t) {
            if (!t_chars.contains(ch)) 
                t_chars.insert({ch, 1});
            else
                ++t_chars[ch];
        }

        return s_chars == t_chars ? true : false;
    }
};
