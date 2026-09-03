class Solution {
public:
    int divsum(vector<int>& nums,int mid,int n){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (ceil)((double)nums[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low =1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            int sum = divsum(nums,mid,n);
            if(sum>threshold) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};