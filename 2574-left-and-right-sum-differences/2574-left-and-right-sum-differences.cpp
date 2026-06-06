class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int total_sum = 0 ;
        for(int i = 0 ; i< n ; i++){
            total_sum = total_sum + nums[i];
        }

        int left_sum = 0;
        for(int i = 0 ; i < n ; i++){
            int right_sum = total_sum - left_sum - nums[i];

            int diff = left_sum - right_sum;

            if(diff < 0){
                diff = - diff;
            }
            ans[i] = diff;
            left_sum = left_sum + nums[i];
        }
        return ans;
    }
};