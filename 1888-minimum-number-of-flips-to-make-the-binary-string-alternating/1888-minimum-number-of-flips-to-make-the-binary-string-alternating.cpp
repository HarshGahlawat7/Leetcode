class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int diff1 = 0, diff2 = 0;
        int res = n; 

        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != i % 2) diff1++;
            if (s[i] - '0' == i % 2) diff2++;
        }
        
        
        if (n % 2 == 0) return min(diff1, diff2);

        res = min(diff1, diff2);

        
        for (int i = 0; i < n; i++) {
            
            if (s[i] - '0' != i % 2) diff1--;
            if (s[i] - '0' == i % 2) diff2--;

            if (s[i] - '0' != (i + n) % 2) diff1++;
            if (s[i] - '0' == (i + n) % 2) diff2++;

            res = min({res, diff1, diff2});
        }

        return res;
    }
};