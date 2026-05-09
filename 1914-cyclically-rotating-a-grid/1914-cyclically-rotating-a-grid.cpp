class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int num_layers = min(m, n) / 2;

        for (int layer = 0; layer < num_layers; ++layer) {
            vector<int> elements;

            // 1. Extract elements in counter-clockwise order
            // Top row: left to right
            for (int j = layer; j < n - 1 - layer; ++j) 
                elements.push_back(grid[layer][j]);
            
            // Right column: top to bottom
            for (int i = layer; i < m - 1 - layer; ++i) 
                elements.push_back(grid[i][n - 1 - layer]);
            
            // Bottom row: right to left
            for (int j = n - 1 - layer; j > layer; --j) 
                elements.push_back(grid[m - 1 - layer][j]);
            
            // Left column: bottom to top
            for (int i = m - 1 - layer; i > layer; --i) 
                elements.push_back(grid[i][layer]);

            // 2. Calculate effective rotation
            int p = elements.size();
            int real_k = k % p;
            
            // Rotate the vector: elements at indices [0...real_k-1] 
            // move to the end of the list.
            rotate(elements.begin(), elements.begin() + real_k, elements.end());

            // 3. Put elements back into the grid
            int idx = 0;
            for (int j = layer; j < n - 1 - layer; ++j) 
                grid[layer][j] = elements[idx++];
            
            for (int i = layer; i < m - 1 - layer; ++i) 
                grid[i][n - 1 - layer] = elements[idx++];
            
            for (int j = n - 1 - layer; j > layer; --j) 
                grid[m - 1 - layer][j] = elements[idx++];
            
            for (int i = m - 1 - layer; i > layer; --i) 
                grid[i][layer] = elements[idx++];
        }

        return grid;
    }
};