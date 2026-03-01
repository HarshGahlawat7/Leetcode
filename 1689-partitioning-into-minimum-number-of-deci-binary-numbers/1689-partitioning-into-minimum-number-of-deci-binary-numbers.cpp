class Solution {
public:
    int minPartitions(string n) {
        char max_digit = '0';
    for (int i = 0 ; i < n.length() ; i++) {
        char c = n[i];
        if (c > max_digit) {
            max_digit = c;
        }
    }
    return max_digit - '0';
    }
};