class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos_map;

        // Group indices by their value
        for (int i = 0; i < n; ++i) {
            pos_map[nums[i]].push_back(i);
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (int q_idx : queries) {
            int target_val = nums[q_idx];
            const vector<int>& indices = pos_map[target_val];

            // If only one occurrence exists, no "other" index j exists
            if (indices.size() < 2) {
                answer.push_back(-1);
                continue;
            }

            // Find where q_idx is located in the sorted list of indices
            auto it = lower_bound(indices.begin(), indices.end(), q_idx);
            int pos = distance(indices.begin(), it);

            int min_dist = n; 

            // Helper lambda for circular distance
            auto get_dist = [&](int i, int j) {
                int d = abs(i - j);
                return min(d, n - d);
            };

            // 1. Check the immediate neighbor to the left in the sorted list
            if (pos > 0) {
                min_dist = min(min_dist, get_dist(q_idx, indices[pos - 1]));
            } else {
                // If q_idx is the first element, its left "circular" neighbor 
                // is the last element in the list
                min_dist = min(min_dist, get_dist(q_idx, indices.back()));
            }

            // 2. Check the immediate neighbor to the right in the sorted list
            if (pos < indices.size() - 1) {
                min_dist = min(min_dist, get_dist(q_idx, indices[pos + 1]));
            } else {
                // If q_idx is the last element, its right "circular" neighbor 
                // is the first element in the list
                min_dist = min(min_dist, get_dist(q_idx, indices.front()));
            }

            answer.push_back(min_dist);
        }

        return answer;
    }
};