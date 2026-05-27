class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Vectors to store indices. Initialize with -1 to indicate "not seen".
        std::vector<int> last_lowercase(26, -1);
        std::vector<int> first_uppercase(26, -1);
        
        // Traverse the string to record positions
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                last_lowercase[c - 'a'] = i; // Continually update to get the LAST occurrence
            } else if (c >= 'A' && c <= 'Z') {
                if (first_uppercase[c - 'A'] == -1) {
                    first_uppercase[c - 'A'] = i; // Only update if it's the FIRST occurrence
                }
            }
        }
        
        int special_count = 0;
        
        // Check conditions for all 26 letters
        for (int i = 0; i < 26; ++i) {
            // Condition 1 & 2: Must exist in both cases
            // Condition 3: Last lowercase position must be strictly less than first uppercase position
            if (last_lowercase[i] != -1 && first_uppercase[i] != -1 && last_lowercase[i] < first_uppercase[i]) {
                special_count++;
            }
        }
        
        return special_count;
    }
};