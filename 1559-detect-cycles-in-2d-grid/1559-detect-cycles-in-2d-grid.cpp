class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
             int r, int c, int pr, int pc, char target) {
        
        visited[r][c] = true;
        
        // Directions: Right, Left, Down, Up
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 1. Check bounds
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
                // 2. Only move to cells with the same character
                if (grid[nr][nc] == target) {
                    // 3. If the neighbor is visited and NOT the parent, a cycle is found
                    if (visited[nr][nc] && (nr != pr || nc != pc)) {
                        return true;
                    }
                    // 4. If not visited, continue searching
                    if (!visited[nr][nc]) {
                        if (dfs(grid, visited, nr, nc, r, c, target)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    // Start DFS: (current_r, current_c, parent_r, parent_c, target_char)
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};