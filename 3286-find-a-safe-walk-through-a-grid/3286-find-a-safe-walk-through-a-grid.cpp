class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], 0, 0});
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto [current_damage, r, c] = pq.top();
            pq.pop();
            
            if (r == m - 1 && c == n - 1) {
                break;
            }
            
            if (current_damage > dist[r][c]) {
                continue;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_damage = current_damage + grid[nr][nc];
                    
                    if (next_damage < dist[nr][nc]) {
                        dist[nr][nc] = next_damage;
                        pq.push({next_damage, nr, nc});
                    }
                }
            }
        }
        int final_damage = dist[m - 1][n - 1];
        return (health - final_damage) >= 1;
    }
};