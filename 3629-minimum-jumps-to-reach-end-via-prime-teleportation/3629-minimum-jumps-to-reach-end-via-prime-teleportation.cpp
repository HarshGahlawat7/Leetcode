class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);

        // 1. Sieve of Eratosthenes to find primes up to max_val
        vector<bool> is_prime(max_val + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= max_val; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= max_val; i += p)
                    is_prime[i] = false;
            }
        }

        // 2. Map each value to the indices where it appears
        vector<vector<int>> val_to_indices(max_val + 1);
        for (int i = 0; i < n; i++) {
            val_to_indices[nums[i]].push_back(i);
        }

        // 3. BFS Setup
        queue<int> q;
        q.push(0);
        
        vector<bool> visited_idx(n, false);
        visited_idx[0] = true;
        
        vector<bool> visited_prime(max_val + 1, false);
        
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr_idx = q.front();
                q.pop();

                if (curr_idx == n - 1) return steps;

                // --- Option 1: Adjacent Steps ---
                // Move Right
                if (curr_idx + 1 < n && !visited_idx[curr_idx + 1]) {
                    visited_idx[curr_idx + 1] = true;
                    q.push(curr_idx + 1);
                }
                // Move Left
                if (curr_idx - 1 >= 0 && !visited_idx[curr_idx - 1]) {
                    visited_idx[curr_idx - 1] = true;
                    q.push(curr_idx - 1);
                }

                // --- Option 2: Prime Teleportation ---
                int val = nums[curr_idx];
                if (val <= max_val && is_prime[val] && !visited_prime[val]) {
                    visited_prime[val] = true;
                    
                    // Iterate through all multiples of this prime
                    for (int multiple = val; multiple <= max_val; multiple += val) {
                        // Jump to all indices containing this multiple
                        for (int idx : val_to_indices[multiple]) {
                            if (!visited_idx[idx]) {
                                visited_idx[idx] = true;
                                q.push(idx);
                            }
                        }
                        // Optimization: Clear indices so we don't process them again
                        val_to_indices[multiple].clear();
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};