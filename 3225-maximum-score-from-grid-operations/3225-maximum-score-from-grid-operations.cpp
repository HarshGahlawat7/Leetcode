class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // 1. Precompute prefix sums for each column
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                pref[j][i + 1] = pref[j][i] + grid[i][j];
            }
        }

        // dp[height][state]
        // state 0: Decreasing (h_i < h_{i-1})
        // state 1: Increasing (h_i > h_{i-1})
        // state 2: Valley/Reset (Used to transition from decreasing to increasing)
        vector<long long> dec(n + 1, 0), inc(n + 1, 0), reset(n + 1, 0);

        for (int i = 1; i < n; ++i) {
            vector<long long> n_dec(n + 1, 0), n_inc(n + 1, 0), n_reset(n + 1, 0);

            // Precompute suffix/prefix max for O(1) transitions
            long long max_all_prev = 0;
            for (int k = 0; k <= n; ++k) {
                max_all_prev = max({max_all_prev, dec[k], inc[k], reset[k]});
            }

            // Suffix Max for Decreasing: h_i < h_{i-1}
            // Column i gets points from column i-1
            long long suffix_max = -1e18;
            for (int k = n; k >= 0; --k) {
                suffix_max = max(suffix_max, max(inc[k], dec[k]) + pref[i][k]);
                n_dec[k] = suffix_max - pref[i][k];
            }

            // Prefix Max for Increasing: h_i > h_{i-1}
            // Column i-1 gets points from column i
            long long prefix_max = -1e18;
            for (int k = 0; k <= n; ++k) {
                // From standard increase
                prefix_max = max(prefix_max, inc[k] - pref[i - 1][k]);
                n_inc[k] = prefix_max + pref[i - 1][k];
                
                // From a valley reset (allows column i-1 to get full points up to j)
                n_inc[k] = max(n_inc[k], reset[k] + pref[i - 1][k]);
                n_inc[k] = max(n_inc[k], dec[k] + pref[i - 1][k]); 
            }

            // Update Reset: Best score after a decreasing trend to start an increase
            for (int j = 0; j <= n; ++j) {
                n_reset[j] = max_all_prev; 
            }

            dec = move(n_dec);
            inc = move(n_inc);
            reset = move(n_reset);
        }

        long long ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = max({ans, dec[j], inc[j]});
        }
        return ans;

    }
};