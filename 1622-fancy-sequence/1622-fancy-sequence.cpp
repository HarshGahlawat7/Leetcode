class Fancy {
    private:
    long long MOD = 1e9 + 7;
    std::vector<long long> seq;
    long long add = 0;
    long long mul = 1;

    // Fast Power function to calculate (base^exp) % mod
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Modular Inverse using Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }
public:
    Fancy() {}

    void append(int val) {
        // Reverse transformation: x = (val - add) * inv(mul)
        long long invMul = modInverse(mul);
        long long normalized = ((val - add + MOD) % MOD * invMul) % MOD;
        seq.push_back(normalized);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        add = (add * m) % MOD;
        mul = (mul * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        // Apply current transformation: (normalized * mul + add)
        return (seq[idx] * mul + add) % MOD;
        
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */