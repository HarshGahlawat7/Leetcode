class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
       int n = robots.size();
        vector<pair<int, int>> r_data(n);
        for (int i = 0; i < n; ++i) r_data[i] = {robots[i], distance[i]};
        sort(r_data.begin(), r_data.end());
        sort(walls.begin(), walls.end());

        // dp[i][0]: Max unique walls using first i robots, i-th robot fires LEFT
        // dp[i][1]: Max unique walls using first i robots, i-th robot fires RIGHT
        vector<vector<int>> dp(n, vector<int>(2, 0));

        for (int i = 0; i < n; ++i) {
            int curr = r_data[i].first;
            int d = r_data[i].second;

            // Walls hit by i-th robot firing LEFT: [max(prev_robot+1, curr-d), curr]
            int l_limit = (i == 0) ? curr - d : max(curr - d, r_data[i-1].first + 1);
            int count_L = upper_bound(walls.begin(), walls.end(), curr) - 
                          lower_bound(walls.begin(), walls.end(), l_limit);

            // Walls hit by i-th robot firing RIGHT: [curr, min(next_robot-1, curr+d)]
            int r_limit = (i == n - 1) ? curr + d : min(curr + d, r_data[i+1].first - 1);
            int count_R = upper_bound(walls.begin(), walls.end(), r_limit) - 
                          lower_bound(walls.begin(), walls.end(), curr);

            if (i == 0) {
                dp[i][0] = count_L;
                dp[i][1] = count_R;
            } else {
                // If i fires LEFT:
                // Case 1: i-1 fired LEFT. Ranges: [..., R_{i-1}] and [R_{i-1}+1, R_i]. No overlap.
                int from_left = dp[i-1][0] + count_L;

                // Case 2: i-1 fired RIGHT. Ranges: [R_{i-1}, R_{i-1}+D_{i-1}] and [curr-D_i, curr].
                // These might overlap in the gap (R_{i-1}, R_i).
                int prev_R_reach = min(r_data[i-1].first + r_data[i-1].second, curr - 1);
                int curr_L_reach = max(r_data[i-1].first + 1, curr - d);
                
                int overlap = 0;
                if (curr_L_reach <= prev_R_reach) {
                    overlap = upper_bound(walls.begin(), walls.end(), prev_R_reach) - 
                              lower_bound(walls.begin(), walls.end(), curr_L_reach);
                }
                int from_right = dp[i-1][1] + count_L - overlap;
                
                dp[i][0] = max(from_left, from_right);

                // If i fires RIGHT:
                // No overlap with i-1 (regardless of i-1's choice) because i fires away.
                dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + count_R;
            }
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};