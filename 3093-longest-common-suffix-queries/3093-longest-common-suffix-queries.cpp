#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Using a distinct name to avoid conflicts, and zero-initializing 
// via default structures to prevent compiler bugs on LeetCode.
struct SuffixTrieNode {
    int children[26];
    int best_idx;
};

class Solution {
private:
    bool isBetter(int new_idx, int old_idx, const vector<string>& wordsContainer) {
        if (old_idx == -1) return true;
        if (wordsContainer[new_idx].length() < wordsContainer[old_idx].length()) return true;
        if (wordsContainer[new_idx].length() == wordsContainer[old_idx].length()) return new_idx < old_idx;
        return false;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Pool allocator for nodes
        vector<SuffixTrieNode> trie;
        
        // Lambda to create and push a freshly initialized node
        auto createNode = [&]() {
            SuffixTrieNode node;
            fill(begin(node.children), end(node.children), -1);
            node.best_idx = -1;
            trie.push_back(node);
        };
        
        // Create the root node at index 0
        createNode();
        
        // Find the global best default index
        int global_best_idx = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].length() < wordsContainer[global_best_idx].length()) {
                global_best_idx = i;
            }
        }
        trie[0].best_idx = global_best_idx;

        // Build Trie using pool array
        for (int i = 0; i < wordsContainer.size(); ++i) {
            int curr = 0; // Start at root
            const string& word = wordsContainer[i];
            
            for (int j = word.length() - 1; j >= 0; --j) {
                int char_idx = word[j] - 'a';
                
                if (trie[curr].children[char_idx] == -1) {
                    trie[curr].children[char_idx] = trie.size();
                    createNode();
                }
                
                curr = trie[curr].children[char_idx];
                
                if (isBetter(i, trie[curr].best_idx, wordsContainer)) {
                    trie[curr].best_idx = i;
                }
            }
        }

        // Process queries
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& query : wordsQuery) {
            int curr = 0;
            int matched_idx = trie[0].best_idx;
            
            for (int j = query.length() - 1; j >= 0; --j) {
                int char_idx = query[j] - 'a';
                if (trie[curr].children[char_idx] != -1) {
                    curr = trie[curr].children[char_idx];
                    matched_idx = trie[curr].best_idx;
                } else {
                    break;
                }
            }
            ans.push_back(matched_idx);
        }

        return ans;
    }
};