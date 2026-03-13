class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        // Upper bound: max workerTime (10^6) * H * (H+1) / 2 where H = 10^5
        // 1e16 is a safe ceiling for a 64-bit long long.
        long long high = 1e16; 
        long long result = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canReduce(mountainHeight, workerTimes, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

private:
    bool canReduce(int mountainHeight, const vector<int>& workerTimes, long long T) {
        long long totalReduction = 0;
        for (int w : workerTimes) {
            // Calculate max x such that w * x * (x + 1) / 2 <= T
            // x = (-1 + sqrt(1 + 8*T/w)) / 2
            double val = 1.0 + (8.0 * T) / w;
            long long x = (sqrt(val) - 1) / 2;
            
            totalReduction += x;
            if (totalReduction >= mountainHeight) {
                return true;
            }
        }
        return totalReduction >= mountainHeight;
    }
};