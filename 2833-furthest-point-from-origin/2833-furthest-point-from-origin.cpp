class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCount = 0;
        int rCount = 0;
        int underscoreCount = 0;

        for (char move : moves) {
            if (move == 'L') {
                lCount++;
            } else if (move == 'R') {
                rCount++;
            } else {
                underscoreCount++;
            }
        }

        // The furthest distance is the bias between L and R plus all wildcards
        return std::abs(lCount - rCount) + underscoreCount;
    }
};