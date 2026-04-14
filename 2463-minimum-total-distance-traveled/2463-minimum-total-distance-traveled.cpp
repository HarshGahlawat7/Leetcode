class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // 2. Expand factories based on their limits
        vector<int> factory_positions;
        for (auto& f : factory) {
            for (int i = 0; i < f[1]; ++i) {
                factory_positions.push_back(f[0]);
            }
        }

        int n = robot.size();
        int m = factory_positions.size();

        // 3. DP Table initialization
        // dp[i][j] = min distance for first i robots using first j factory slots
        // Use a large value for infinity. 
        // Max distance can be ~100 robots * 2e9 distance = 2e11, so 1e15 is safe.
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e15));

        // Base case: 0 robots fixed takes 0 distance
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 0;
        }

        // 4. Transitions
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // Option 1: Don't use the j-th factory slot for any robot
                dp[i][j] = dp[i][j - 1];

                // Option 2: Use the j-th factory slot for the i-th robot
                // Distance = |robot_pos - factory_pos| + dp[prev_robot][prev_factory_slot]
                long long current_dist = abs(robot[i - 1] - factory_positions[j - 1]);
                dp[i][j] = min(dp[i][j], current_dist + dp[i - 1][j - 1]);
            }
        }

        return dp[n][m];
    }
};