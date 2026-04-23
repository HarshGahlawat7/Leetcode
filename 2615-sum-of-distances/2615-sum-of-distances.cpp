class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, vector<int>> indicesMap;

        for (int i = 0; i < n; ++i) {
            indicesMap[nums[i]].push_back(i);
        }

        for (auto const& [val, pos] : indicesMap) {
            int k = pos.size();
            if (k <= 1) continue;

            long long totalSum = 0;
            for (int p : pos) totalSum += p;

            long long prefixSum = 0;
            for (int i = 0; i < k; ++i) {
                long long p_i = pos[i];
                long long leftCount = i;
                long long leftSum = leftCount * p_i - prefixSum;
                long long rightCount = k - 1 - i;
                long long suffixSum = (totalSum - prefixSum - p_i);
                long long rightSum = suffixSum - (rightCount * p_i);

                arr[p_i] = leftSum + rightSum;
                prefixSum += p_i;
            }
        }

        return arr;
    }
};