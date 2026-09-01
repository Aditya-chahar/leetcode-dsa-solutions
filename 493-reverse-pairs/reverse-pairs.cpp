class Solution {
public:
    int mergesort(vector<int> &nums,int low,int mid,int high){
        // count pairs
        int cnt = 0;
        int right = mid+1;
        for(int left = low; left<=mid;left++){
            while(right<=high && (long long)nums[left]> 2LL*nums[right]){
                right++;
            }
            cnt+= right - (mid+1);
        }
        int left = low;
        right = mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low;i<=high;i++){
            nums[i]= temp[i-low];
        }
        return cnt;

    }
    int ms(vector<int> &nums,int low,int high){
        int cnt = 0;
        int mid = (low+high)/2;
        if(low == high) return cnt;
        cnt += ms(nums,low,mid);
        cnt+= ms(nums,mid+1,high);
        cnt+= mergesort(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return ms(nums,0,nums.size()-1);
    }
};