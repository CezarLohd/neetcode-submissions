class Solution {
public:
    bool checkInclusion(const string& s1, const string& s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int size1 = s1.size();
        int size2 = s2.size();
        
        if (size1 > size2) return false;

        array<int,26> letters1{};
        array<int,26> letters2{};

        for (int i = 0; i < size1; ++i) {
            ++letters1[s1[i] - 'a'];
            ++letters2[s2[i] - 'a'];
        }

        if (letters1 == letters2) 
            return true;

        for (int l = 0, r = size1; r < size2; ++l, ++r) {
            --letters2[ s2[l] - 'a' ];
            ++letters2[ s2[r] - 'a' ];

            if (letters1 == letters2) 
                return true;
        }

        return false;
    }
};
