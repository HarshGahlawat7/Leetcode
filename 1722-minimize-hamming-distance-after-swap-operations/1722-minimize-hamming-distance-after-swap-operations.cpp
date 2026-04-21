class Solution {
public:
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    // Standard Union operation
    void unite(vector<int>& parent, int i, int j) {
        int root_i = find(parent, i);
        int root_j = find(parent, j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        // 1. Build the connected components of indices
        for (const auto& swap : allowedSwaps) {
            unite(parent, swap[0], swap[1]);
        }

        // 2. Group source values by their component root
        unordered_map<int, unordered_map<int, int>> counts;
        for (int i = 0; i < n; ++i) {
            int root = find(parent, i);
            counts[root][source[i]]++;
        }

        int totalMatches = 0;

        // 3. Check how many target elements can be satisfied within each component
        for (int i = 0; i < n; ++i) {
            int root = find(parent, i);
            int targetVal = target[i];
            
            // If the required target value exists in the source for this component
            if (counts[root][targetVal] > 0) {
                totalMatches++;
                counts[root][targetVal]--;
            }
        }

        // Hamming distance = Total elements - Matches
        return n - totalMatches;
    }
};