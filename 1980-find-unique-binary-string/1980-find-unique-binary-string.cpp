class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
    unordered_set<int> seen;
    for (const string& s : nums) {
        seen.insert(stoi(s, nullptr, 2));
    }
    
    for (int i = 0; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            string res = bitset<16>(i).to_string();
            return res.substr(16 - n);
        }
    }
    return "";
    }
};