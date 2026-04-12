class Solution {
public:
    int getDist(int a, int b) {
        if (a == 26) return 0; // Finger hasn't been placed yet
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.length();
        // dp[i][f2] = min distance after typing 'i' characters, 
        // with one finger at word[i-1] and the other at position f2.
        // f2 = 26 represents an unplaced finger.
        vector<vector<int>> dp(n + 1, vector<int>(27, 1e9));
        
        dp[0][26] = 0;

        for (int i = 0; i < n; ++i) {
            int next_char = word[i] - 'A';
            for (int f2 = 0; f2 <= 26; ++f2) {
                if (dp[i][f2] == 1e9) continue;

                // Current position of the finger that just typed word[i-1]
                int f1 = (i == 0) ? 26 : word[i - 1] - 'A';

                // Option 1: Move Finger 1 to type word[i]
                dp[i + 1][f2] = min(dp[i + 1][f2], dp[i][f2] + getDist(f1, next_char));

                // Option 2: Move Finger 2 to type word[i]
                // After this, Finger 2 is at 'next_char' and Finger 1 is at 'f1'.
                // To keep our state consistent (one finger at word[i], other at 'f2'),
                // we store the finger that stayed behind (f1).
                dp[i + 1][f1] = min(dp[i + 1][f1], dp[i][f2] + getDist(f2, next_char));
            }
        }

        int min_dist = 1e9;
        for (int f2 = 0; f2 <= 26; ++f2) {
            min_dist = min(min_dist, dp[n][f2]);
        }
        return min_dist;
    }
};