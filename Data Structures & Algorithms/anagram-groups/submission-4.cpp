class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string& str : strs) {
            string key(26, 0); 
            for (char c : str)
                key[c - 'a']++;
            
            anagrams[key].push_back(std::move(str));
        }

        vector<vector<string>> solution;
        solution.reserve(anagrams.size());

        for (auto& [key, value] : anagrams)
            solution.push_back(std::move(value));

        return solution;
    }
};