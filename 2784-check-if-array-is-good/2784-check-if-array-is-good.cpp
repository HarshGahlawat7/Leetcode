class Solution {
public:
    bool isGood(vector<int>& nums) {
        int len = nums.size();
        // Since base[n] has length n + 1, our n must be len - 1
        int n = len - 1;
        
        // base[1] is [1, 1], so n must be at least 1
        if (n < 1) return false;

        // Use a frequency map or array to count occurrences
        // Since nums[i] <= 200, a simple array works well
        std::vector<int> count(201, 0);
        for (int x : nums) {
            // If we find a number larger than our expected n, it's invalid
            if (x > n) return false;
            count[x]++;
        }

        // Check values from 1 to n-1 (must appear exactly once)
        for (int i = 1; i < n; i++) {
            if (count[i] != 1) return false;
        }

        // Check value n (must appear exactly twice)
        return count[n] == 2;
    }
};