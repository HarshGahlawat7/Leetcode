class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remainingCount = 0;
        int maxEnd = 0;
        
        for (const auto& interval : intervals) {
            // If the current interval's end extends past the maxEnd seen so far,
            // it cannot be covered by previous intervals.
            if (interval[1] > maxEnd) {
                remainingCount++;
                maxEnd = interval[1]; // Update the boundary
            }
            // Otherwise, it is covered by a previous interval, so we skip it.
        }
        
        return remainingCount;
    }
};