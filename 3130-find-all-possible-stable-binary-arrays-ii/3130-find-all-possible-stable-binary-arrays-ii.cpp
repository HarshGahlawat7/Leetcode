class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long MOD = 1e9 + 7;
        
        // We use two 2D arrays to represent the current number of 1s used (j)
        // and whether the last digit was 0 or 1.
        // dp[i][j][0] is now dp0[i][j]
        // dp[i][j][1] is now dp1[i][j]
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

        // Base Case: Only zeros
        for (int i = 1; i <= min(zero, limit); ++i) {
            dp0[i][0] = 1;
        }
        // Base Case: Only ones
        for (int j = 1; j <= min(one, limit); ++j) {
            dp1[0][j] = 1;
        }

        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                // Transition for ending in 0
                dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % MOD;
                if (i > limit) {
                    dp0[i][j] = (dp0[i][j] - dp1[i - limit - 1][j] + MOD) % MOD;
                }

                // Transition for ending in 1
                dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1]) % MOD;
                if (j > limit) {
                    dp1[i][j] = (dp1[i][j] - dp0[i][j - limit - 1] + MOD) % MOD;
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};