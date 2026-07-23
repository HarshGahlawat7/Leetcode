class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        // Find highest power of 2 <= n
        int k = 1;
        while (k * 2 <= n) {
            k *= 2;
        }
        
        // The total number of unique XOR values is 2^(k+1) = k * 2
        return k * 2;
    }
};