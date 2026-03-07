class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string target1 = "", target2 = "";
        
        // Create target alternating patterns for the doubled length
        for (int i = 0; i < 2 * n; i++) {
            target1 += (i % 2 == 0) ? '0' : '1';
            target2 += (i % 2 == 0) ? '1' : '0';
        }
        
        string s_double = s + s;
        int diff1 = 0, diff2 = 0;
        int res = 1e9; // Initialize with a large value
        
        int l = 0;
        for (int r = 0; r < 2 * n; r++) {
            // Add current character's difference to the window
            if (s_double[r] != target1[r]) diff1++;
            if (s_double[r] != target2[r]) diff2++;
            
            // If window size exceeds n, slide the left pointer
            if ((r - l + 1) > n) {
                if (s_double[l] != target1[l]) diff1--;
                if (s_double[l] != target2[l]) diff2--;
                l++;
            }
            
            // Once window is exactly size n, track the minimum flips
            if ((r - l + 1) == n) {
                res = min({res, diff1, diff2});
            }
        }
        
        return res;
    }
};