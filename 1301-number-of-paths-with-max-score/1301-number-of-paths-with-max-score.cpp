class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int MOD = 1e9 + 7;
        int n = board.size();
        
        std::vector<std::vector<std::pair<int, int>>> dp(n, std::vector<std::pair<int, int>>(n, {-1, 0}));
        
        dp[n - 1][n - 1] = {0, 1};
        
        int dirs[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                auto [max_sum, paths] = dp[i][j];
                
                if (max_sum == -1 || board[i][j] == 'X') {
                    continue;
                }
                for (int d = 0; d < 3; ++d) {
                    int ni = i + dirs[d][0];
                    int nj = j + dirs[d][1];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] != 'X') {
                        int cell_val = (board[ni][nj] == 'E') ? 0 : (board[ni][nj] - '0');
                        int new_sum = max_sum + cell_val;
                        if (new_sum > dp[ni][nj].first) {
                            dp[ni][nj] = {new_sum, paths};
                        } 
                        else if (new_sum == dp[ni][nj].first) {
                            dp[ni][nj].second = (dp[ni][nj].second + paths) % MOD;
                        }
                    }
                }
            }
        }
        
       
        auto [final_sum, final_paths] = dp[0][0];
        
        if (final_sum == -1) {
            return {0, 0};
        }
        return {final_sum, final_paths};
    }
};