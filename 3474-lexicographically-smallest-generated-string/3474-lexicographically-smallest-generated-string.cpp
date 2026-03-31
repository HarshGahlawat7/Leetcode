class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int totalLen = n + m - 1;
        
        string res(totalLen, '\0');
        vector<bool> locked(totalLen, false);
        
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (res[i + j] != '\0' && res[i + j] != str2[j]) {
                        return "";
                    }
                    res[i + j] = str2[j];
                    locked[i + j] = true;
                }
            }
        }
        
        for (int i = 0; i < totalLen; ++i) {
            if (res[i] == '\0') {
                res[i] = 'a';
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; ++j) {
                    if (res[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                
                if (match) {
                    bool fixed = false;
                    for (int j = m - 1; j >= 0; --j) {
                        int idx = i + j;
                        if (!locked[idx]) {
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
                    
                    if (!fixed) return "";
                }
            }
        }
        
        return res;
    }
};