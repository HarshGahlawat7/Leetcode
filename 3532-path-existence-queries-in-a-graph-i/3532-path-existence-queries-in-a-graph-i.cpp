class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int curr_id = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                curr_id++;
            }
            component[i] = curr_id;
        }
        vector<bool> ans;
        ans.reserve(queries.size()); 
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            ans.push_back(component[u] == component[v]);
        }
        
        return ans;
    }
};