class Solution {
private:
    void backtrack(int n, int k, string& current, int& count, string& result) {
        // Optimization: if we already found the result, stop recursion
        if (!result.empty()) return;

        // Base case: we've reached the required length
        if (current.length() == n) {
            count++;
            if (count == k) {
                result = current;
            }
            return;
        }

        // Try adding 'a', 'b', and 'c' in order
        for (char c : {'a', 'b', 'c'}) {
            // Check the happy string condition: s[i] != s[i-1]
            if (current.empty() || current.back() != c) {
                current.push_back(c);
                backtrack(n, k, current, count, result);
                current.pop_back(); // Backtrack step
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        string current = "";
        string result = "";
        int count = 0;
        
        backtrack(n, k, current, count, result);
        return result;
    }
};