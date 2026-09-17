#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
//to gemini zrobil, mowi ze bedzie najszybsze
// 256-bajtowa tablica lookup (LUT):
// Znak nieprawidłowy -> 0
// Litera/cyfra -> znormalizowany znak (lowercase)
consteval auto create_lut() {
    std::array<char, 256> lut{};
    for (char c = '0'; c <= '9'; ++c) lut[static_cast<unsigned char>(c)] = c;
    for (char c = 'a'; c <= 'z'; ++c) lut[static_cast<unsigned char>(c)] = c;
    for (char c = 'A'; c <= 'Z'; ++c) lut[static_cast<unsigned char>(c)] = static_cast<char>(c + 32);
    return lut;
}

alignas(64) static constexpr auto LUT = create_lut();

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        if (s.empty()) return true;

        // Surowe wskaźniki prosto do bufora znaków
        const char* left = s.data();
        const char* right = s.data() + s.size() - 1;

        while (left < right) {
            char cl = LUT[static_cast<unsigned char>(*left)];
            if (!cl) {
                ++left;
                continue;
            }

            char cr = LUT[static_cast<unsigned char>(*right)];
            if (!cr) {
                --right;
                continue;
            }

            if (cl != cr) return false;

            ++left;
            --right;
        }

        return true;
    }
};