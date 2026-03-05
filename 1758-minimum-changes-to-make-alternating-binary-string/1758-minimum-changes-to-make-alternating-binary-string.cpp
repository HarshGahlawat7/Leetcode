class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count0 = 0; // operations to make s look like "0101..."
        
        for (int i = 0; i < n; i++) {
            // Pattern: Even index = '0', Odd index = '1'
            if (i % 2 == 0) {
                if (s[i] != '0') count0++;
            } else {
                if (s[i] != '1') count0++;
            }
        }
        
        // count1 (for "1010...") is simply (n - count0)
        return std::min(count0, n - count0);
    }
};