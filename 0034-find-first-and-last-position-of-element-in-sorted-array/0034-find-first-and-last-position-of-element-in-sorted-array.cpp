class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFirst(nums, target);
        // If the target is not found, return [-1, -1]
        if (start == -1) {
            return {-1, -1};
        }
        int end = findLast(nums, target);
        return {start, end};
    }
private:
    int findFirst(vector<int> &arr ,int target){
        int start = 0;
        int end = arr.size() - 1 ;
        int res = -1 ;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target){
                res = mid;
                end = mid - 1;
            }

            else if (arr[mid] > target){
                end = mid - 1;
            } 
            else{
                start = mid + 1;
            }
        }
        return res;
    }
    int findLast(vector<int> &arr ,int target){
        int start = 0;
        int end = arr.size() - 1 ;
        int res = -1 ;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target){
                res = mid;
                start = mid + 1;
            }

            else if (arr[mid] > target){
                end = mid - 1;
            } 
            else{
                start = mid + 1;
            }
        }
        return res;
    }
    };