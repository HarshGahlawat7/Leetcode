class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long MOD = 1e9 + 7;
        
        // dp[i][j][k]
        // i: number of 0s used
        // j: number of 1s used
        // k: 0 if the last digit is 0, 1 if the last digit is 1
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));

        // Base cases: filling arrays with only 0s or only 1s up to the limit
        for (int i = 1; i <= min(zero, limit); ++i) {
            dp[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); ++j) {
            dp[0][j][1] = 1;
        }

        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                // To end with a 0 at (i, j):
                // We take all stable arrays of (i-1, j) ending in 0 or 1
                // then subtract the invalid case where we just exceeded the 'limit' of 0s.
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                if (i > limit) {
                    // Subtract the case where we had 'limit' zeros already and added one more.
                    // This invalid case is specifically when we had a '1' followed by exactly 'limit' zeros.
                    dp[i][j][0] = (dp[i][j][0] - dp[i - limit - 1][j][1] + MOD) % MOD;
                }

                // To end with a 1 at (i, j):
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                if (j > limit) {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - limit - 1][0] + MOD) % MOD;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};