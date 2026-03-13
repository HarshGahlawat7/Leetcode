class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
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