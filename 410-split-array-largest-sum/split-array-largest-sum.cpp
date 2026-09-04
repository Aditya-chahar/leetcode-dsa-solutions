class Solution {
public:
    int noOfStudents(vector<int>& arr,int mid){
        int n = arr.size();
        int students = 0;
        int total_pages = 0;
        for(int i = 0;i<n;i++){
            if(total_pages +arr[i]<=mid){
                total_pages += arr[i];
            }
            else{
                students++;
                total_pages = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n<k) return -1;
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(noOfStudents(arr,mid)>=k) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        // same concept as book allocation,painter partition 
        return findPages(nums,k);
        
    }
};