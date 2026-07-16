class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       int n = nums.size();
        vector<int> prefixGcd(n);
        
        int current_max = 0;
        for (int i = 0; i < n; ++i) {
            current_max = max(current_max, nums[i]);
            prefixGcd[i] = gcd(nums[i], current_max);
        }
        
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long total_sum = 0;
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            total_sum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return total_sum; 
    }
};