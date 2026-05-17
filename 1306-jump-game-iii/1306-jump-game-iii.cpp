class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        std::vector<bool> visited(n, false);
        std::queue<int> q;
        
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // If we found a target index with value 0
            if (arr[curr] == 0) {
                return true;
            }
            
            // Option 1: Jump forward
            int forward = curr + arr[curr];
            if (forward < n && !visited[forward]) {
                visited[forward] = true;
                q.push(forward);
            }
            
            // Option 2: Jump backward
            int backward = curr - arr[curr];
            if (backward >= 0 && !visited[backward]) {
                visited[backward] = true;
                q.push(backward);
            }
        }
        
        return false;
    }
};