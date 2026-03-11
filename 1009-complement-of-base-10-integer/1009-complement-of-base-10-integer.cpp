class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        unsigned int num_bits = 0;
        int temp = n;
        while (temp > 0) {
            temp >>= 1;
            num_bits++;
        }

        // Create a mask of all 1s of length num_bits
        // (1U << 3) is 1000, subtracting 1 gives 0111
        unsigned int mask = (1U << num_bits) - 1;

        // XOR n with the mask to flip all bits up to the MSB
        return n ^ mask;
    }
};