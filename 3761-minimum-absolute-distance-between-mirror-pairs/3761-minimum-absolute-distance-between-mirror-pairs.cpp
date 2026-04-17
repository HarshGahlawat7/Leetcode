class Solution {
public:
    long long reverseInt(int n) {
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> last_seen_reverse;
        int min_dist = INT_MAX;
        bool found = false;

        for (int j = 0; j < n; ++j) {
            // Check if current nums[j] was the reverse of a previous nums[i]
            if (last_seen_reverse.count(nums[j])) {
                min_dist = min(min_dist, j - last_seen_reverse[nums[j]]);
                found = true;
            }

            // Store the reverse of current nums[j] as a potential target for future indices
            long long rev_j = reverseInt(nums[j]);
            last_seen_reverse[rev_j] = j;
        }

        return found ? min_dist : -1;
    }
};