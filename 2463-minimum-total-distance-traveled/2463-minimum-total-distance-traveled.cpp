class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factory_positions;
        for (auto& f : factory) {
            for (int i = 0; i < f[1]; ++i) {
                factory_positions.push_back(f[0]);
            }
        }

        int n = robot.size();
        int m = factory_positions.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e15));

        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1];

                long long current_dist = abs(robot[i - 1] - factory_positions[j - 1]);
                dp[i][j] = min(dp[i][j], current_dist + dp[i - 1][j - 1]);
            }
        }

        return dp[n][m];
    }
};