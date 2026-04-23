class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, vector<int>> indicesMap;

        // Group indices by their values
        for (int i = 0; i < n; ++i) {
            indicesMap[nums[i]].push_back(i);
        }

        // Iterate through each group of indices
        for (auto const& [val, pos] : indicesMap) {
            int k = pos.size();
            if (k <= 1) continue;

            // Calculate total sum of indices for this value to help with suffix sums
            long long totalSum = 0;
            for (int p : pos) totalSum += p;

            long long prefixSum = 0;
            for (int i = 0; i < k; ++i) {
                long long p_i = pos[i];
                
                // Left side calculation: (i * p_i) - sum(pos[0...i-1])
                long long leftCount = i;
                long long leftSum = leftCount * p_i - prefixSum;

                // Right side calculation: sum(pos[i+1...k-1]) - (k - 1 - i) * p_i
                long long rightCount = k - 1 - i;
                long long suffixSum = (totalSum - prefixSum - p_i);
                long long rightSum = suffixSum - (rightCount * p_i);

                arr[p_i] = leftSum + rightSum;

                // Update prefixSum for the next index in the group
                prefixSum += p_i;
            }
        }

        return arr;
    }
};