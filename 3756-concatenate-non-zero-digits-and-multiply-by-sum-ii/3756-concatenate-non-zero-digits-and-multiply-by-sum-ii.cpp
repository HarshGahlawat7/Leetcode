class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int m = s.length();
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        vector<int> cnt(m + 1, 0);
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> pref_x(m + 1, 0);
        
        for (int i = 0; i < m; ++i) {
            int digit = s[i] - '0';
            if (digit != 0) {
                cnt[i + 1] = cnt[i] + 1;
                pref_sum[i + 1] = pref_sum[i] + digit;
                pref_x[i + 1] = (pref_x[i] * 10 + digit) % MOD;
            } else {
                cnt[i + 1] = cnt[i];
                pref_sum[i + 1] = pref_sum[i];
                pref_x[i + 1] = pref_x[i];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int k = cnt[r + 1] - cnt[l];
            
            if (k == 0) {
                ans.push_back(0);
                continue;
            }
            long long current_sum = pref_sum[r + 1] - pref_sum[l];
            long long x = (pref_x[r + 1] - (pref_x[l] * pow10[k]) % MOD + MOD) % MOD;
            long long query_ans = (x * current_sum) % MOD;
            ans.push_back(query_ans);
        }
        
        return ans;
    }
};