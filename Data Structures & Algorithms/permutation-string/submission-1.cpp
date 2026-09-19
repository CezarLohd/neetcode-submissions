class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();

        if (size1 > size2) return false;

        array<int,26> letters1{};
        array<int,26> letters2{};

        for (char& ch : s1)
            ++letters1[ ch - 'a' ];

        for (int i = 0; i < size1; ++i)
            ++letters2[ s2[i] - 'a' ];

        if (letters1 == letters2) 
            return true;
        
        //
        // for (int i = 0; i < 26; ++i) 
        //     if (letters2[i]) cout << (char)((int)'a' + i) << ": " << letters2[i] << ", ";
        // cout << endl;

        for (int l = 0, r = size1; r < size2; ++l, ++r) {
            --letters2[ s2[l] - 'a' ];
            ++letters2[ s2[r] - 'a' ];

            if (letters1 == letters2) 
                return true;
            //
            // for (int i = 0; i < 26; ++i) 
            //     if (letters2[i]) cout << (char)((int)'a' + i) << ": " << letters2[i] << ", ";
            // cout << endl;
        }

        return false;
    }
};
