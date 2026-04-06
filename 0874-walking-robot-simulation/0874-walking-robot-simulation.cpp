class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        std::set<std::pair<int, int>> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        
        int x = 0, y = 0; 
        int dir = 0;     
        int maxDistSq = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) { 
                dir = (dir + 3) % 4;
            } else if (cmd == -1) { 
                dir = (dir + 1) % 4;
            } else { 
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