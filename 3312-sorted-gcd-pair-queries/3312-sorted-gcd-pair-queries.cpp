class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        vector<int> counts(max_val + 1, 0);
        for (int num : nums) {
            counts[num]++;
        }
        std::vector<long long> multiples(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int j = i; j <= max_val; j += i) {
                multiples[i] += counts[j];
            }
        }
        std::vector<long long> gcd_counts(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long cnt = multiples[i];
            long long total_pairs = cnt * (cnt - 1) / 2;
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= gcd_counts[j];
            }
            gcd_counts[i] = total_pairs;
        }
        std::vector<long long> prefix_sums;
        std::vector<int> gcd_values;
        long long current_sum = 0;
        
        for (int i = 1; i <= max_val; ++i) {
            if (gcd_counts[i] > 0) {
                current_sum += gcd_counts[i];
                prefix_sums.push_back(current_sum);
                gcd_values.push_back(i);
            }
        }
        std::vector<int> ans;
        ans.reserve(queries.size());
        
        for (long long q : queries) {
            auto it = std::upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            int idx = std::distance(prefix_sums.begin(), it);
            ans.push_back(gcd_values[idx]);
        }
        
        return ans;
    }
};