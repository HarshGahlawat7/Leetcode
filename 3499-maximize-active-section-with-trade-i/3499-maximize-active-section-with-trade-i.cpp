class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
      int initial_ones = 0;
        for (char c : s) {
            if (c == '1') initial_ones++;
        }
        
        // Prepend and append '1'
        std::string t = "1" + s + "1";
        
        // Run-length encoding of blocks: {char, length}
        std::vector<std::pair<char, int>> blocks;
        for (char c : t) {
            if (blocks.empty() || blocks.back().first != c) {
                blocks.push_back({c, 1});
            } else {
                blocks.back().second++;
            }
        }
        
        int n_blocks = blocks.size();
        
        // Precompute largest '0'-block to the left and right of each position
        // to quickly find the largest zero-block strictly outside {i-1, i+1}
        std::vector<int> pref_max_zero(n_blocks, 0);
        std::vector<int> suff_max_zero(n_blocks, 0);
        
        int current_max = 0;
        for (int i = 0; i < n_blocks; ++i) {
            if (blocks[i].first == '0') {
                current_max = std::max(current_max, blocks[i].second);
            }
            pref_max_zero[i] = current_max;
        }
        
        current_max = 0;
        for (int i = n_blocks - 1; i >= 0; --i) {
            if (blocks[i].first == '0') {
                current_max = std::max(current_max, blocks[i].second);
            }
            suff_max_zero[i] = current_max;
        }
        
        int max_active = initial_ones;
        
        // Check all interior '1'-blocks
        for (int i = 1; i + 1 < n_blocks; ++i) {
            if (blocks[i].first == '1') {
                int L = blocks[i].second;         // length of '1'-block
                int a = blocks[i - 1].second;     // preceding '0'-block length
                int b = blocks[i + 1].second;     // succeeding '0'-block length
                
                // Choice 1: Fill the merged zero block (length a + L + b)
                int choice1 = initial_ones + a + b;
                
                // Choice 2: Fill the largest '0'-block elsewhere
                int max_other_zero = 0;
                if (i - 2 >= 0) {
                    max_other_zero = std::max(max_other_zero, pref_max_zero[i - 2]);
                }
                if (i + 2 < n_blocks) {
                    max_other_zero = std::max(max_other_zero, suff_max_zero[i + 2]);
                }
                int choice2 = initial_ones - L + max_other_zero;
                
                max_active = std::max({max_active, choice1, choice2});
            }
        }
        
        return max_active;
    }
};