class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for (string& s : strs) {
            enc += "#";
            enc += to_string(s.size());
            enc += "#";
            enc += s;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> answer;

        for (int i = 0; i < s.size();) {
            int lenght;
            string separator;

            for (int j = 1; j < s.size(); ++j) {
                if (s[i + j] == '#') {
                    separator = s.substr(i + 1, j - 1);
                    lenght = stoi(separator);
                    break;
                }
            }

            i += separator.size() + 2; // #separator#
            answer.push_back(s.substr(i, lenght));
            i += lenght;
        }

        return answer;
    }
};
