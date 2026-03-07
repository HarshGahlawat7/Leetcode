class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int diff1 = 0, diff2 = 0;
        int res = n; // Max possible flips is n

        // 1. Initial window: Calculate flips for the first 'n' characters
        // Target1: 0, 1, 0, 1... 
        // Target2: 1, 0, 1, 0...
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != i % 2) diff1++;
            if (s[i] - '0' == i % 2) diff2++;
        }
        
        // If the string length is even, Type-1 operations don't change the 
        // number of flips needed for an alternating string. 
        // We only need the sliding window for odd lengths.
        if (n % 2 == 0) return min(diff1, diff2);

        res = min(diff1, diff2);

        // 2. Sliding Window: Simulate cyclic shifts for 2n length
        // We use i % n to wrap around the original string.
        for (int i = 0; i < n; i++) {
            // Remove the character at the left (i)
            // It was compared against (i % 2)
            if (s[i] - '0' != i % 2) diff1--;
            if (s[i] - '0' == i % 2) diff2--;

            // Add the same character at the right (effectively index i + n)
            // It is now compared against ((i + n) % 2)
            if (s[i] - '0' != (i + n) % 2) diff1++;
            if (s[i] - '0' == (i + n) % 2) diff2++;

            res = min({res, diff1, diff2});
        }

        return res;
    }
};