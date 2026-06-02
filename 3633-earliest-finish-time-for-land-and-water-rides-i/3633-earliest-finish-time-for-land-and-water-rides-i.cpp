class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minFinishTime = INT_MAX;

        // Iterate through all possible pairs of land and water rides
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                // Scenario 1: Land Ride i followed by Water Ride j
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart1 = std::max(landFinish, waterStartTime[j]);
                int totalFinish1 = waterStart1 + waterDuration[j];
                
                // Scenario 2: Water Ride j followed by Land Ride i
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart2 = std::max(waterFinish, landStartTime[i]);
                int totalFinish2 = landStart2 + landDuration[i];
                
                // Track the minimum finish time encountered
                minFinishTime = std::min({minFinishTime, totalFinish1, totalFinish2});
            }
        }

        return minFinishTime;
    }
};