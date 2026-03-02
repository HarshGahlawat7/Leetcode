class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> trailingZeros(n);

        // Step 1: Count trailing zeros for each row
        // Optimization: Scan from right to left and stop at the first '1'
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            trailingZeros[i] = count;
        }

        int totalSwaps = 0;

        // Step 2: Greedy selection of the first valid row
        for (int i = 0; i < n; ++i) {
            int targetRequirement = n - 1 - i;
            int foundIdx = -1;

            // Find the first row from current position downwards that fits
            for (int j = i; j < n; ++j) {
                if (trailingZeros[j] >= targetRequirement) {
                    foundIdx = j;
                    break;
                }
            }

            // If no row satisfies the condition, it's impossible
            if (foundIdx == -1) return -1;

            // Step 3: Move the row to position 'i' using adjacent swaps
            // This mimics the 'bubble sort' movement
            for (int k = foundIdx; k > i; --k) {
                std::swap(trailingZeros[k], trailingZeros[k - 1]);
                totalSwaps++;
            }
        }

        return totalSwaps;
    };
    };