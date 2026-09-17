class Solution {
public:
    bool isPalindrome(string& s) {
        if (s.empty()) return true;
        // lepsze bo w locie sprawdzam isalnum zamiast to na chama na poczatku erasowac (tez przesuwac w pamieci, nawet jak powiedzmy pierwszy i ostatni juz sa inne)

        for (auto left = s.begin(), right = s.end() - 1; left < right; ++left, --right) {
            while (left < right && !isalnum(*left)) ++left;
            while (left < right && !isalnum(*right)) --right;

            if (tolower(*left) != tolower(*right)) return false;
        }
        
        return true;
    }
};
