class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        // Difference array to track moves for each possible sum S in [2, 2 * limit]
        vector<int> delta(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            // Standardize a as the smaller value
            int val_min = min(a, b);
            int val_max = max(a, b);

            // 1. Default: 2 moves for the entire range [2, 2 * limit]
            delta[2] += 2;
            delta[2 * limit + 1] -= 2;

            // 2. 1 move range: [min(a, b) + 1, max(a, b) + limit]
            // We subtract 1 from the default 2 moves
            delta[val_min + 1] -= 1;
            delta[val_max + limit + 1] += 1;

            // 3. 0 moves: target sum is exactly a + b
            // We subtract another 1 from the current 1 move
            delta[a + b] -= 1;
            delta[a + b + 1] += 1;
        }

        int min_moves = n; // Max possible moves is n
        int current_moves = 0;
        
        // Sweep through the difference array to find the minimum
        for (int i = 2; i <= 2 * limit; ++i) {
            current_moves += delta[i];
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;
    }
};