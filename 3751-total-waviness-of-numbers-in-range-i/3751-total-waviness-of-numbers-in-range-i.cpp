#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
    // Helper function to calculate the waviness of a single number
    int calculateWaviness(int n) {
        // Any number with fewer than 3 digits has a waviness of 0
        if (n < 100) return 0;
        
        std::string s = std::to_string(n);
        int waviness = 0;
        int len = s.length();
        
        // Iterate through the internal digits (excluding first and last)
        for (int i = 1; i < len - 1; ++i) {
            // Check for Peak: strictly greater than both neighbors
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) {
                waviness++;
            }
            // Check for Valley: strictly less than both neighbors
            else if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                waviness++;
            }
        }
        
        return waviness;
    }

public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        
        for (int i = num1; i <= num2; ++i) {
            total_sum += calculateWaviness(i);
        }
        
        return total_sum;
    }
};

