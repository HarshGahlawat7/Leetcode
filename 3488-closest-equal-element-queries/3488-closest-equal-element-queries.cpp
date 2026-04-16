class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos_map;

        for (int i = 0; i < n; ++i) {
            pos_map[nums[i]].push_back(i);
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (int q_idx : queries) {
            int target_val = nums[q_idx];
            const vector<int>& indices = pos_map[target_val];

            if (indices.size() < 2) {
                answer.push_back(-1);
                continue;
            }
            auto it = lower_bound(indices.begin(), indices.end(), q_idx);
            int pos = distance(indices.begin(), it);

            int min_dist = n; 

            auto get_dist = [&](int i, int j) {
                int d = abs(i - j);
                return min(d, n - d);
            };
            if (pos > 0) {
                min_dist = min(min_dist, get_dist(q_idx, indices[pos - 1]));
            } else {
                min_dist = min(min_dist, get_dist(q_idx, indices.back()));
            }

            if (pos < indices.size() - 1) {
                min_dist = min(min_dist, get_dist(q_idx, indices[pos + 1]));
            } else {
                min_dist = min(min_dist, get_dist(q_idx, indices.front()));
            }

            answer.push_back(min_dist);
        }

        return answer;
    }
};