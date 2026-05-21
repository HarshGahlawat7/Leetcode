class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        std::unordered_set<int> prefixes;
        
        // Step 1: Insert all possible prefixes of numbers in arr1 into the hash set
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10; // Truncate the last digit to get the next prefix
            }
        }
        
        int maxLength = 0;
        
        // Step 2: Check prefixes of numbers in arr2 against the set
        for (int num : arr2) {
            while (num > 0) {
                // If the current prefix exists in the set
                if (prefixes.count(num)) {
                    // Calculate length by converting to string or using log10
                    int currentLength = std::to_string(num).length();
                    maxLength = std::max(maxLength, currentLength);
                    
                    // Since we are checking from longest to shortest prefix for this number,
                    // once we find a match, smaller prefixes won't give a larger length.
                    break;
                }
                num /= 10;
            }
        }
        
        return maxLength;
    }
};