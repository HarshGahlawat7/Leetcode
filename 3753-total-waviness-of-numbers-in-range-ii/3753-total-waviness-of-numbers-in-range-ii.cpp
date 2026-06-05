#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
private:
    long long dp[17][11][11][2][2];
    long long count_dp[17][11][11][2][2]; 
    string num_str;

    pair<long long, long long> solve_dp(int idx, int prev, int prev_prev, bool is_less, bool is_started) {
        if (idx == num_str.length()) {
            return {0, 1}; 
        }

        if (dp[idx][prev][prev_prev][is_less][is_started] != -1) {
            return {dp[idx][prev][prev_prev][is_less][is_started], count_dp[idx][prev][prev_prev][is_less][is_started]};
        }

        long long total_waviness = 0;
        long long total_count = 0;
        int limit = is_less ? 9 : (num_str[idx] - '0');

        for (int d = 0; d <= limit; ++d) {
            bool next_less = is_less || (d < limit);
            bool next_started = is_started || (d > 0);

            int next_prev = next_started ? d : 10;
            int next_prev_prev = prev;

            int waviness_contribution = 0;
            if (is_started && prev_prev != 10 && prev != 10) {
                if ((prev > prev_prev && prev > d) || (prev < prev_prev && prev < d)) {
                    waviness_contribution = 1;
                }
            }

            auto [next_waviness, next_count] = solve_dp(idx + 1, next_prev, next_prev_prev, next_less, next_started);
            
            total_count += next_count;
            total_waviness += next_waviness + (waviness_contribution * next_count);
        }

        count_dp[idx][prev][prev_prev][is_less][is_started] = total_count;
        return {dp[idx][prev][prev_prev][is_less][is_started] = total_waviness, total_count};
    }

    long long get_waviness_sum(long long n) {
        if (n < 100) return 0;
        num_str = to_string(n);
        memset(dp, -1, sizeof(dp));
        memset(count_dp, -1, sizeof(count_dp));
        return solve_dp(0, 10, 10, false, false).first;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return get_waviness_sum(num2) - get_waviness_sum(num1 - 1);
    }
};