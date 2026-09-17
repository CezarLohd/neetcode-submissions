class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> columns[9];
        unordered_set<char> squares[3][3];

        for (short i = 0; i < 9; ++i) {
            for (short j = 0; j < 9; ++j) {
                char now = board[i][j];
                if (now == '.') continue;
                
                if (rows[i].contains(now)) return false;
                if (columns[j].contains(now)) return false;
                if (squares[i/3][j/3].contains(now)) return false;

                rows[i].insert(now);
                columns[j].insert(now);
                squares[i/3][j/3].insert(now);
            }
        }

        return true;
    }
};
