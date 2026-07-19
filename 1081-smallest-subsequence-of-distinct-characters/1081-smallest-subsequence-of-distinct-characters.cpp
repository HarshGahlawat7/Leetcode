class Solution {
public:
    string smallestSubsequence(string s) {
        std::unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        // Tracks if a character is currently in our result stack
        std::vector<bool> seen(26, false);
        std::vector<char> stack;
        
        // Step 2: Iterate through the string
        for (char c : s) {
            // Decrement the remaining count for this character
            count[c]--;
            
            // If the character is already in our result, skip it
            if (seen[c - 'a']) {
                continue;
            }
            
            // Maintain monotonic increasing order where possible
            // Pop from stack if:
            // 1. Stack is not empty
            // 2. Top of stack is lexicographically greater than the current char
            // 3. The top char occurs again later in the string (count > 0)
            while (!stack.empty() && stack.back() > c && count[stack.back()] > 0) {
                seen[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            
            // Add the current character to the stack and mark as seen
            stack.push_back(c);
            seen[c - 'a'] = true;
        }
        
        // Convert the stack of characters into the final string
        return std::string(stack.begin(), stack.end());
    }
};