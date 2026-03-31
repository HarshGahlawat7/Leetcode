class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int totalLen = n + m - 1;
        
        string res(totalLen, '\0');
        vector<bool> locked(totalLen, false);
        
        // Step 1: Fill 'T' constraints and mark locked positions
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (res[i + j] != '\0' && res[i + j] != str2[j]) {
                        return ""; // Direct conflict between 'T's
                    }
                    res[i + j] = str2[j];
                    locked[i + j] = true;
                }
            }
        }
        
        // Step 2: Fill gaps with 'a' for lexicographical smallest
        for (int i = 0; i < totalLen; ++i) {
            if (res[i] == '\0') {
                res[i] = 'a';
            }
        }
        
        // Step 3: Verify and fix 'F' constraints
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                // Check if current substring matches str2
                bool match = true;
                for (int j = 0; j < m; ++j) {
                    if (res[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                
                // If it matches, we must break it by changing a non-locked char
                if (match) {
                    bool fixed = false;
                    // Start from the back (i + m - 1) to keep the prefix small
                    for (int j = m - 1; j >= 0; --j) {
                        int idx = i + j;
                        if (!locked[idx]) {
                            // Change res[idx] to the smallest possible char that isn't str2[j]
                            for (char c = 'a'; c <= 'z'; ++c) {
                                if (c != str2[j]) {
                                    res[idx] = c;
                                    fixed = true;
                                    break;
                                }
                            }
                        }
                        if (fixed) break;
                    }
                    
                    if (!fixed) return ""; // All chars in this 'F' window are locked by 'T's
                }
            }
        }
        
        return res;
    }
};