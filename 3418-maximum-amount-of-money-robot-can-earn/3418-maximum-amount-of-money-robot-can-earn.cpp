class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[k][i][j] : max coins at (i, j) with k neutralizations used
        // Using long long to prevent overflow and initializing with a very small number
        long long INF = 1e18;
        vector<vector<vector<long long>>> dp(3, vector<vector<long long>>(m, vector<long long>(n, -INF)));

        // Base case for (0, 0)
        dp[0][0][0] = coins[0][0]; // No neutralization
        dp[1][0][0] = max(0, coins[0][0]); // Use 1 neutralization if it's negative
        dp[2][0][0] = max(0, coins[0][0]); // Use 1 (or 2, though 1 is enough) at start

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; ++k) {
                    long long prev_max = -INF;
                    if (i > 0) prev_max = max(prev_max, dp[k][i-1][j]);
                    if (j > 0) prev_max = max(prev_max, dp[k][i][j-1]);
                    
                    // Case 1: Don't use a neutralization at current cell
                    if (prev_max != -INF) {
                        dp[k][i][j] = max(dp[k][i][j], prev_max + coins[i][j]);
                    }

                    // Case 2: Use a neutralization at current cell (if k > 0)
                    if (k > 0) {
                        long long prev_k_minus = -INF;
                        if (i > 0) prev_k_minus = max(prev_k_minus, dp[k-1][i-1][j]);
                        if (j > 0) prev_k_minus = max(prev_k_minus, dp[k-1][i][j-1]);
                        
                        if (prev_k_minus != -INF) {
                            // Neutralize current cell: value becomes 0 if negative, 
                            // though logic dictates we only neutralize negative values.
                            dp[k][i][j] = max(dp[k][i][j], prev_k_minus + max(0, coins[i][j]));
                        }
                    }
                }
            }
        }

        return max({dp[0][m-1][n-1], dp[1][m-1][n-1], dp[2][m-1][n-1]});
    }
};