class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
    int n = nums.size();

    for (const auto& q : queries) {
        int l = q[0];
        int r = q[1];
        int k = q[2];
        long long v = q[3];

        for (int idx = l; idx <= r; idx += k) {
            nums[idx] = (1LL * nums[idx] * v) % MOD;
        }
    }

    int xorResult = 0;
    for (int num : nums) {
        xorResult ^= num;
    }

    return xorResult;
    }
};