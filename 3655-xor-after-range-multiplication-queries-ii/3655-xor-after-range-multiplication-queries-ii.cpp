class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        auto bravexuneth = queries;

        int B = sqrt(n) + 1;

        vector<vector<tuple<int,int,int>>> bucket(B);

        // Step 1: split queries
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                bucket[k].push_back({l, r, v});
            }
        }

        // Step 2: process small k
        for (int k = 1; k < B; k++) {
            if (bucket[k].empty()) continue;

            for (int r = 0; r < k; r++) {

                int m = (n - r + k - 1) / k; // size of this AP

                vector<long long> diff(m + 1, 1);

                // apply queries
                for (auto &[l, rr, v] : bucket[k]) {
                    if (l % k != r) continue;

                    int start = (l - r) / k;
                    int end = (rr - r) / k;

                    diff[start] = diff[start] * v % MOD;
                    if (end + 1 < m) {
                        diff[end + 1] = diff[end + 1] * modInverse(v, MOD) % MOD;
                    }
                }

                // apply prefix
                long long cur = 1;
                for (int i = 0; i < m; i++) {
                    cur = cur * diff[i] % MOD;

                    int actual_index = r + i * k;  // no idx array needed
                    nums[actual_index] = nums[actual_index] * cur % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }

    long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod);
    }

    long long power(long long a, long long b, long long mod) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
};