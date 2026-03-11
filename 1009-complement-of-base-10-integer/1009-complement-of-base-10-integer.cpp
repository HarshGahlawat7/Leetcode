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

        unsigned int mask = (1U << num_bits) - 1;

        return n ^ mask;
    }
};