class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: S1 is always "0"
        if (n == 1) return '0';

        // Length of Sn is 2^n - 1
        int length = (1 << n) - 1; 
        int mid = (length / 2) + 1;

        if (k == mid) {
            return '1';
        } else if (k < mid) {
            // If k is in the left half, it's the same as in Sn-1
            return findKthBit(n - 1, k);
        } else {
            // If k is in the right half, find the mirrored index in the left half
            // The mirrored index is: length - k + 1
            char mirroredBit = findKthBit(n - 1, length - k + 1);
            
            // Invert the bit ('0' -> '1', '1' -> '0')
            return (mirroredBit == '0') ? '1' : '0';
        }
    }
};