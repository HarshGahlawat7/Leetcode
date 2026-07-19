class Solution {
public:
    string smallestSubsequence(string s) {
        std::unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        std::vector<bool> seen(26, false);
        std::vector<char> stack;
        for (char c : s) {
            count[c]--;
            if (seen[c - 'a']) {
                continue;
            }
            while (!stack.empty() && stack.back() > c && count[stack.back()] > 0) {
                seen[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(c);
            seen[c - 'a'] = true;
        }
        return std::string(stack.begin(), stack.end());
    }
};