class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        std::vector<int> answer;
        
        for (int num : nums) {
            // Temporary vector to hold digits of the current number
            std::vector<int> digits;
            
            // Extract digits using modulo (results in reverse order)
            while (num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }
            
            // Reverse to restore original order and add to answer
            std::reverse(digits.begin(), digits.end());
            for (int d : digits) {
                answer.push_back(d);
            }
        }
        
        return answer;
    }
};