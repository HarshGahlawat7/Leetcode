class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Store obstacles in a set for fast lookup
        // We can pack (x, y) into a single long long to use with std::set
        std::set<std::pair<int, int>> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        
        int x = 0, y = 0; // Starting position
        int dir = 0;      // Starting direction (North)
        int maxDistSq = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) { // Turn left
                dir = (dir + 3) % 4;
            } else if (cmd == -1) { // Turn right
                dir = (dir + 1) % 4;
            } else { // Move forward k units
                for (int i = 0; i < cmd; ++i) {
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];
                    
                    // Check if the next step is an obstacle
                    if (obstacleSet.find({nextX, nextY}) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        // Update max distance at every step
                        maxDistSq = std::max(maxDistSq, x * x + y * y);
                    } else {
                        // Hit an obstacle, stop moving for this command
                        break;
                    }
                }
            }
        }
        
        return maxDistSq;
    }
};