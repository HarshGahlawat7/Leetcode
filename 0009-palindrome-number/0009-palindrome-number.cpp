class Solution {
public:
    bool isPalindrome(int x) {
        int reversed = 0;
        int temp = x;
        while (temp != 0) {
            int digit = temp % 10;
            temp /= 10; 
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
                return 0; // Overflow condition
            }
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) {
                return 0; // Underflow condition
            }
            reversed = reversed * 10 + digit;
        }
        if(reversed == x && (x>=0)){
            return true;
        }
        else{
            return false;
        }
    }
};