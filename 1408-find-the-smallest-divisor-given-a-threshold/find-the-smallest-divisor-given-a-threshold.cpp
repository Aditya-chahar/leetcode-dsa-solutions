class Solution {
public:
    int divSum(vector<int>& arr,int mid){
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += ceil((double)arr[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(threshold<n) return -1;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(high>=low){
            int mid = low + (high-low)/2;
            if(divSum(nums,mid) <=threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
        
    }
};