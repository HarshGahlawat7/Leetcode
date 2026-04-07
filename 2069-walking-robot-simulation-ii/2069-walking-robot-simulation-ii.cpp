class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0: East, 1: North, 2: West, 3: South
    
    vector<string> directions = {"East", "North", "West", "South"};
    vector<pair<int,int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    int cycle;
    
    Robot(int width, int height) {
        w = width;
        h = height;
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        num %= cycle;
        
        // Special case: if num == 0 and at origin, direction becomes South
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3;
            return;
        }
        
        while (num--) {
            int nx = x + moves[dir].first;
            int ny = y + moves[dir].second;
            
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4; // turn counterclockwise
                nx = x + moves[dir].first;
                ny = y + moves[dir].second;
            }
            
            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return directions[dir];
    }
};