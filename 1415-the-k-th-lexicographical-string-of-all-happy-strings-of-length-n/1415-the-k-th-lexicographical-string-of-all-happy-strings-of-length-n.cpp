class Solution {
private:
    void backtrack(int n, int k, string& current, int& count, string& result) {
        if (!result.empty()) 
            return;

        if (current.length() == n) {
            count++;
            if (count == k) {
                result = current;
            }
            return;
        }

        for (char c : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != c) {
                current.push_back(c);
                backtrack(n, k, current, count, result);
                current.pop_back(); 
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