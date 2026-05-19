class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Map each value to all the indices where it appears
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) {
            graph[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        // Initialize BFS from index 0
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                // If we've reached the last index, return the step count
                if (curr == n - 1) return steps;

                // Option 1: Jump to curr + 1
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Option 2: Jump to curr - 1
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Option 3: Jump to any index with the same value
                if (graph.count(arr[curr])) {
                    for (int nextIdx : graph[arr[curr]]) {
                        if (!visited[nextIdx]) {
                            visited[nextIdx] = true;
                            q.push(nextIdx);
                        }
                    }
                    // Crucial Step: Clear the entries for this value to avoid redundant processing later
                    graph.erase(arr[curr]);
                }
            }
            steps++;
        }

        return -1;
    }
};