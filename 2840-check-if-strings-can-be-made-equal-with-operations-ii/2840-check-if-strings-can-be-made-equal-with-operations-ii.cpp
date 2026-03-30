class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int count1[2][26] = {0};
        int count2[2][26] = {0};
        
        int n = s1.length();
        
        for (int i = 0; i < n; i++) {
            count1[i % 2][s1[i] - 'a']++;
            count2[i % 2][s2[i] - 'a']++;
        }
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