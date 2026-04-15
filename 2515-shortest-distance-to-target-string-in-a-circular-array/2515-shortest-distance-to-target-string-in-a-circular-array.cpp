class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int min_dist = -1;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                // Calculate the direct distance
                int abs_diff = abs(i - startIndex);
                
                // Calculate the shortest path (direct vs circular wrap-around)
                int current_dist = min(abs_diff, n - abs_diff);
                
                // Update min_dist if it's the first find or a new minimum
                if (min_dist == -1 || current_dist < min_dist) {
                    min_dist = current_dist;
                }
            }
        }
        
        return min_dist;
    }
};