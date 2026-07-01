class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the start or end cell contains a thief, safeness factor is immediately 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }
        
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        // Step 1: Multi-source BFS to find min distance to any thief
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // Step 2: Modified Dijkstra to find path maximizing the minimum safeness factor
        // Priority Queue stores: {safeness_factor, {r, c}}
        priority_queue<pair<int, pair<int, int>>> pq;
        
        // Max safeness factor array to optimize/prevent redundant processing
        vector<vector<int>> max_safeness(n, vector<int>(n, -1));
        
        pq.push({dist[0][0], {0, 0}});
        max_safeness[0][0] = dist[0][0];
        
        while (!pq.empty()) {
            auto [sf, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();
            
            // Reached destination, return computed max safeness factor
            if (r == n - 1 && c == n - 1) {
                return sf;
            }
            
            // Skip stale states
            if (sf < max_safeness[r][c]) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    // Path safeness is limited by the minimum safeness cell encountered
                    int next_sf = min(sf, dist[nr][nc]);
                    
                    if (next_sf > max_safeness[nr][nc]) {
                        max_safeness[nr][nc] = next_sf;
                        pq.push({next_sf, {nr, nc}});
                    }
                }
            }
        }
        
        return 0;
    }
};