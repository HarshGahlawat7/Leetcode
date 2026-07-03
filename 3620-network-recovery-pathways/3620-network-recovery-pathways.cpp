class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        // Step 1: Filter edges and build adjacency list for valid online nodes
        vector<vector<pair<int, int>>> adj(n);
        vector<int> in_degree(n, 0);
        vector<int> unique_costs;
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            
            // If either endpoint is offline, this edge cannot be part of a valid path
            if (!online[u] || !online[v]) continue;
            
            adj[u].push_back({v, cost});
            in_degree[v]++;
            unique_costs.push_back(cost);
        }
        
        // Deduplicate and sort unique edge costs for binary search
        sort(unique_costs.begin(), unique_costs.end());
        unique_costs.erase(unique(unique_costs.begin(), unique_costs.end()), unique_costs.end());
        
        // Step 2: Compute Topological Sort of the DAG
        vector<int> topo_order;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);
            
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Step 3: Helper lambda to check if a path with a given threshold exists
        auto is_possible = [&](int threshold) -> bool {
            // k can be up to 5 * 10^13, so distance must be long long
            const long long INF = 1e18; 
            vector<long long> dist(n, INF);
            dist[0] = 0;
            
            // Relax edges in topological order
            for (int u : topo_order) {
                if (dist[u] == INF) continue;
                
                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int cost = neighbor.second;
                    
                    // Only traverse edges that meet or exceed our bottleneck threshold
                    if (cost >= threshold) {
                        if (dist[u] + cost < dist[v]) {
                            dist[v] = dist[u] + cost;
                        }
                    }
                }
            }
            return dist[n - 1] <= k;
        };
        
        // Step 4: Binary Search over the sorted unique edge costs
        int low = 0;
        int high = unique_costs.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int threshold = unique_costs[mid];
            
            if (is_possible(threshold)) {
                ans = threshold; // This minimum cost is possible, try to push for a larger one
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};