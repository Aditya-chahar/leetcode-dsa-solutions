class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(high>=low){
            int mid = low + (high-low)/2; 
            if(nums[mid] == target) return true;
            if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
                low +=1;
                high -= 1;
                continue;
            }
            if(nums[mid]<=nums[high]){
                // right part is sorted
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid+1;
                }
                else high = mid-1;
            }
            else{
                // left part is sorted
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }
                else low = mid+1;
            }
        }
        return false;
    }
};