class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        for (const string& q : queries) {
            for (const string& d : dictionary) {
                int edits = 0;
                bool possible = true;
                
                // Compare characters at each index
                for (int i = 0; i < q.length(); ++i) {
                    if (q[i] != d[i]) {
                        edits++;
                    }
                    // Optimization: break if edits exceed 2
                    if (edits > 2) {
                        possible = false;
                        break;
                    }
                }
                
                if (possible) {
                    result.push_back(q);
                    break; // Move to the next query word
                }
            }
        }
        
        return result;
    }
};