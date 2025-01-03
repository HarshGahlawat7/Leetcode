class Solution {
public:
    int fib(int n) { if (n <= 1) return n; std::vector<int> fib_seq(n + 1);  fib_seq[0] = 0; fib_seq[1] = 1; for (int i = 2; i <= n; ++i) { fib_seq[i] = fib_seq[i - 1] + fib_seq[i - 2]; } return fib_seq[n]; }
};