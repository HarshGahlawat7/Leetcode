class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        std::vector<int> C(n);
        std::vector<int> freq(n + 1, 0);
        int common_count = 0;

        for (int i = 0; i < n; ++i) {
            // Increment frequency for the element in A
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                common_count++;
            }

            // Increment frequency for the element in B
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                common_count++;
            }

            // Store the running count for the current prefix
            C[i] = common_count;
        }

        return C;
    }
};