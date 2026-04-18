class Solution {
public:
    int mirrorDistance(int n) {
        std::string s = std::to_string(n);
    std::reverse(s.begin(), s.end());
    
    long long reversedN = std::stoll(s);
    
    return std::abs((long long)n - reversedN);
    }
};