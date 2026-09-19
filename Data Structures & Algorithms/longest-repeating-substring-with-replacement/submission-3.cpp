class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0}; // frequency[ch - 'A']

        int maxFreqCount = 0;

        int highestLen = 0;


        for (int l = 0, r = 0; r < s.size(); ++r) {
            ++freq[ s[r] - 'A' ];

            if ( freq[ s[r] - 'A' ] > maxFreqCount )
                maxFreqCount = freq[ s[r] - 'A' ];
            
            while ( (r - l + 1) - maxFreqCount > k ) {
                --freq[ s[l] - 'A' ];
                ++l;
            }

            if(r - l + 1 > highestLen) highestLen = r - l + 1;
        }

        return highestLen;
    }
};
