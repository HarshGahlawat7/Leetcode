class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<std::vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        vector<bool> visited(n, false);
        int completeComponentsCount = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> componentNodes;
                queue<int> q;
                
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    componentNodes.push_back(curr);
                    
                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                int componentSize = componentNodes.size();
                bool isComplete = true;
                
                for (int node : componentNodes) {
                    if (degree[node] != componentSize - 1) {
                        isComplete = false;
                        break;
                    }
                }
                
                if (isComplete) {
                    completeComponentsCount++;
                }
            }
        }
        
        return completeComponentsCount;
    }
};