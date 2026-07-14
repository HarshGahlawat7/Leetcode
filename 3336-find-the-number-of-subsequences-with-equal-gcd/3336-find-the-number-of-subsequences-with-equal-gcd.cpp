class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int max_val = 0;
        for (int x : nums) {
            max_val = std::max(max_val, x);
        }
        
        const int MOD = 1e9 + 7;
        std::vector<std::vector<int>> dp(max_val + 1, std::vector<int>(max_val + 1, 0));
        dp[0][0] = 1;
        std::vector<std::vector<int>> gcd_table(max_val + 1, std::vector<int>(max_val + 1, 0));
        for (int i = 0; i <= max_val; ++i) {
            for (int j = 0; j <= max_val; ++j) {
                gcd_table[i][j] = std::gcd(i, j);
            }
        }
        
        for (int x : nums) {
            std::vector<std::vector<int>> next_dp = dp;
            
            for (int i = 0; i <= max_val; ++i) {
                for (int j = 0; j <= max_val; ++j) {
                    if (dp[i][j] == 0) continue;
                    
                    int ways = dp[i][j];
                    int ni = gcd_table[i][x];
                    next_dp[ni][j] = (next_dp[ni][j] + ways) % MOD;
                    int nj = gcd_table[j][x];
                    next_dp[i][nj] = (next_dp[i][nj] + ways) % MOD;
                }
            }
            dp = std::move(next_dp);
        }
        
        long long total_pairs = 0;
        for (int g = 1; g <= max_val; ++g) {
            total_pairs = (total_pairs + dp[g][g]) % MOD;
        }
        
        return total_pairs;
    }
};