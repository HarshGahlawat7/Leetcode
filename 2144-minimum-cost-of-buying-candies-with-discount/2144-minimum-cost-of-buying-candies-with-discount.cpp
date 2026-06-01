class Solution {
public:
    int minimumCost(vector<int>& cost) {
        std::sort(cost.rbegin(), cost.rend());
        
        int totalCost = 0;
        int n = cost.size();
        
        for (int i = 0; i < n; i++) {
            // Every 3rd element (indices 2, 5, 8, ...) is free
            if ((i + 1) % 3 == 0) {
                continue;
            }
            totalCost += cost[i];
        }
        
        return totalCost;
    }
};