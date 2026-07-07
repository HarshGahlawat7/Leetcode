class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

    std::string s = std::to_string(n);
    std::string x_str = "";
    long long digit_sum = 0;

    for (char ch : s) {
        if (ch != '0') {
            x_str += ch;
            digit_sum += (ch - '0');
        }
    }

    if (x_str.empty()) {
        return 0;
    }
    long long x = std::stoll(x_str);

    return x * digit_sum;
    }
};