class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1: left, right | 2: up, down | 3: left, down | 4: right, down | 5: left, up | 6: right, up
        vector<vector<pair<int, int>>> directions = {
            {}, 
            {{0, -1}, {0, 1}},  
            {{-1, 0}, {1, 0}},  
            {{0, -1}, {1, 0}},  
            {{0, 1}, {1, 0}},   
            {{0, -1}, {-1, 0}}, 
            {{0, 1}, {-1, 0}}   
        };

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true; // Fixed: Changed [0, 0] to [0][0]

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            int streetType = grid[r][c];
            for (auto& dir : directions[streetType]) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int neighborType = grid[nr][nc];
                    bool backConnection = false;

                    for (auto& backDir : directions[neighborType]) {
                        if (nr + backDir.first == r && nc + backDir.second == c) {
                            backConnection = true;
                            break;
                        }
                    }

                    if (backConnection) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return false;
    }
};