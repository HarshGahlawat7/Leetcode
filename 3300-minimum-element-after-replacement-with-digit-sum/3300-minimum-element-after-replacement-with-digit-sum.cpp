class Solution {
public:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        
        for (int num : nums) {
            int current_digit_sum = getDigitSum(num);
            if (current_digit_sum < min_val) {
                min_val = current_digit_sum;
            }
        }
        
        return min_val;
    }
};