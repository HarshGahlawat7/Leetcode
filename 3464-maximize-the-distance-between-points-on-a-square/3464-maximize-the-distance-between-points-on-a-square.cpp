class Solution {
public:
    bool canPlace(const vector<long long>& pos, int k, int dist, long long perimeter) {
        int n = pos.size();
        for (int i = 0; i < n; ++i) {
            if (pos[i] > pos[0] + dist) break; 
            
            int count = 1;
            long long last_pos = pos[i];
            long long first_pos = pos[i];
            
            for (int j = i + 1; j < n; ++j) {
                if (pos[j] - last_pos >= dist) {
                    if (perimeter - (pos[j] - first_pos) >= dist) {
                        last_pos = pos[j];
                        count++;
                    }
                }
                if (count >= k) return true;
            }
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> linear_pos;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (y == 0) linear_pos.push_back(x);
            else if (x == side) linear_pos.push_back(side + y);
            else if (y == side) linear_pos.push_back(2LL * side + (side - x));
            else if (x == 0) linear_pos.push_back(3LL * side + (side - y));
        }

        sort(linear_pos.begin(), linear_pos.end());

        long long total_perimeter = 4LL * side;
        int low = 1, high = side;
        int ans = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(linear_pos, k, mid, total_perimeter)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};