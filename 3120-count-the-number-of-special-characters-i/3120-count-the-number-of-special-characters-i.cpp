class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Arrays to track the presence of lowercase and uppercase letters
        std::vector<bool> hasLower(26, false);
        std::vector<bool> hasUpper(26, false);
        
        // Traverse the string and mark the presence of each character
        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                hasLower[ch - 'a'] = true;
            } else if (ch >= 'A' && ch <= 'Z') {
                hasUpper[ch - 'A'] = true;
            }
        }
        
        // Count how many letters appear in both lowercase and uppercase
        int specialCount = 0;
        for (int i = 0; i < 26; ++i) {
            if (hasLower[i] && hasUpper[i]) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
};