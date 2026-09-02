class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
       int low = 0;
       int high = n-1;
       while(low<=high){
        int mid = low +(high-low)/2;
        if(nums[mid]== target) return mid;

        // right part is sorted
        if(nums[mid]<=nums[high]){
            if(nums[mid]<=target && target<=nums[high]){
                low = mid+1;
            }
            else high = mid-1;
        }
        // left part is sorted
        else{
            if(nums[low]<=target && target<=nums[mid]){
                high = mid-1;
            }
            else low = mid+1;
        }
       }
       return -1;
    }
};