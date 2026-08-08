class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        // last_pos[j] stores the maximum index in word1 where 
        // the suffix word2[j...n2-1] can be matched EXACTLY.
        vector<int> last_pos(n2 + 1, -1);
        last_pos[n2] = n1;

        int k = n1 - 1;
        for (int j = n2 - 1; j >= 0; --j) {
            k = min(k, last_pos[j + 1] - 1);
            while (k >= 0 && word1[k] != word2[j]) {
                k--;
            }
            last_pos[j] = k;
        }

        vector<int> ans(n2);
        bool changed = false;
        int idx = 0;

        for (int i = 0; i < n2; ++i) {
            bool found = false;
            while (idx < n1) {
                if (word1[idx] == word2[i]) {
                    if (!changed) {
                        // Exact match when 1 change is still available is always optimal
                        ans[i] = idx;
                        found = true;
                        idx++;
                        break;
                    } else if (last_pos[i + 1] > idx) {
                        // Exact match when 0 changes remain requires suffix to be matchable
                        ans[i] = idx;
                        found = true;
                        idx++;
                        break;
                    }
                } else {
                    // Mismatch: use the allowed 1 change if suffix can be matched with 0 changes
                    if (!changed && last_pos[i + 1] > idx) {
                        ans[i] = idx;
                        changed = true;
                        found = true;
                        idx++;
                        break;
                    }
                }
                idx++;
            }
            
            // If no valid index in word1 could be assigned to word2[i]
            if (!found) return {};
        }

        return ans;
    }
};