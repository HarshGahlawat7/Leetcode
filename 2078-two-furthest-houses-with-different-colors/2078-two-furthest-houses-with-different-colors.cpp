class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int left = 0, right = n - 1;
        while (colors[n - 1] == colors[left]) {
            left++;
        }
        while (colors[0] == colors[right]) {
            right--;
        }
        return std::max(n - 1 - left, right);
    }
};