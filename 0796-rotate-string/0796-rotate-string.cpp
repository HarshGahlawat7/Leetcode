class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        // Concatenate s with itself
        std::string doubled = s + s;

        // Check if goal is a substring of the doubled string
        // string::find returns the starting index, or string::npos if not found
        return doubled.find(goal) != std::string::npos;
    }
};