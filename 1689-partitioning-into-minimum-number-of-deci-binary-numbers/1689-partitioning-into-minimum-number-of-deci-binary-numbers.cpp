class Solution {
public:
    int minPartitions(string n) {
        char max_digit = '0';
    for (const char &c : n) {
        if (c > max_digit) {
            max_digit = c;
        }
    }
    return max_digit - '0';
    }
};