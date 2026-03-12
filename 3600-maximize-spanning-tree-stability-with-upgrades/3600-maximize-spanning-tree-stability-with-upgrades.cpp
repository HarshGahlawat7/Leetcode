class DSU {
public:
    vector<int> parent;
    int components;
    
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        components = n;
    }
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        set<int> potential_scores;
        for (const auto& e : edges) {
            potential_scores.insert(e[2]);
            if (e[3] == 0) {
                potential_scores.insert(e[2] * 2);
            }
        }

        // Convert set to sorted vector for binary search indices
        vector<int> scores(potential_scores.begin(), potential_scores.end());
        int low = 0, high = scores.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFormST(n, edges, k, scores[mid])) {
                ans = scores[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

private:
    bool canFormST(int n, const vector<vector<int>>& edges, int k, int threshold) {
        DSU dsu(n);
        int edges_count = 0;

        // Step 1: Add all MUST-HAVE edges
        for (const auto& e : edges) {
            if (e[3] == 1) {
                // If a mandatory edge is naturally weaker than our target, 
                // and it can't be upgraded, this threshold is impossible.
                if (e[2] < threshold) return false;
                // If mandatory edges form a cycle, it's not a spanning tree.
                if (!dsu.unite(e[0], e[1])) return false;
                edges_count++;
            }
        }

        // Step 2: Categorize Optional Edges by Upgrade Cost
        // cost0: Already >= threshold
        // cost1: Needs 1 upgrade to reach >= threshold
        vector<pair<int, int>> cost0, cost1;
        for (const auto& e : edges) {
            if (e[3] == 0) {
                if (e[2] >= threshold) {
                    cost0.push_back({e[0], e[1]});
                } else if (e[2] * 2 >= threshold) {
                    cost1.push_back({e[0], e[1]});
                }
            }
        }

        // Step 3: Greedy addition of cost-0 edges
        for (const auto& p : cost0) {
            if (dsu.unite(p.first, p.second)) {
                edges_count++;
            }
        }

        // Step 4: Greedy addition of cost-1 edges (within budget k)
        int upgrades_used = 0;
        for (const auto& p : cost1) {
            if (upgrades_used < k) {
                if (dsu.unite(p.first, p.second)) {
                    upgrades_used++;
                    edges_count++;
                }
            }
        }

        // A valid spanning tree must have exactly n-1 edges and connect all nodes
        return edges_count == n - 1 && dsu.components == 1;
    }
};