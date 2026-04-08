class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
    int n = nums.size();

    // 1. Process each query in the order they appear
    for (const auto& q : queries) {
        int l = q[0];
        int r = q[1];
        int k = q[2];
        long long v = q[3];

        // 2. Iterate from l to r with step size k
        for (int idx = l; idx <= r; idx += k) {
            // Update the element: (nums[idx] * v) % (10^9 + 7)
            // Use long long for the multiplication to prevent overflow
            nums[idx] = (1LL * nums[idx] * v) % MOD;
        }
    }

    // 3. Compute the bitwise XOR of all final elements
    int xorResult = 0;
    for (int num : nums) {
        xorResult ^= num;
    }

    return xorResult;
    }
};