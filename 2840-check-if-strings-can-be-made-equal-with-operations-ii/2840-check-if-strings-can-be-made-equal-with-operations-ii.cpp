class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int count1[2][26] = {0};
        int count2[2][26] = {0};
        
        int n = s1.length();
        
        for (int i = 0; i < n; i++) {
            // s1: increment count for current parity (even/odd)
            count1[i % 2][s1[i] - 'a']++;
            
            // s2: increment count for current parity (even/odd)
            count2[i % 2][s2[i] - 'a']++;
        }
        
        // Compare the frequency distributions
        for (int parity = 0; parity < 2; parity++) {
            for (int charIdx = 0; charIdx < 26; charIdx++) {
                if (count1[parity][charIdx] != count2[parity][charIdx]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};