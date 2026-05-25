class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        // If the last character is '1', we can never reach it
        if (s[n - 1] == '1') return false;

        // dp[i] will store whether index i is reachable
        std::vector<bool> dp(n, false);
        dp[0] = true; // Start position is always reachable

        // 'reaches' maintains the count of reachable indices in the current window
        int reaches = 0;

        for (int i = 1; i < n; ++i) {
            // Slide the window forward: Add the new element entering the window
            if (i >= minJump && dp[i - minJump]) {
                reaches++;
            }
            // Slide the window forward: Remove the element leaving the window
            if (i > maxJump && dp[i - maxJump - 1]) {
                reaches--;
            }

            // If there is at least one reachable index in our window and s[i] is '0'
            if (reaches > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};