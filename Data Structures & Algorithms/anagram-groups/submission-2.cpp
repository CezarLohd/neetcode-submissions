class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string& str : strs) {
            string sorted = str;
            std::sort(sorted.begin(), sorted.end());

            if(anagrams.contains(sorted))
                anagrams[sorted].push_back(str);
            else
                anagrams.insert({sorted, {str}});
        }

        vector<vector<string>> solution;

        for (auto& [key, value] : anagrams)
            solution.push_back(value);

        return solution;
    }
};
