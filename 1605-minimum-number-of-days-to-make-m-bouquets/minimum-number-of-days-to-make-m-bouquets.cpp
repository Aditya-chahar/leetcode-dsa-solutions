class Solution {
public:
    bool bouquets(vector<int>& arr,int m,int k,long long mid){
        int n = arr.size();
        int count = 0;
        int noOfBouquets = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]<=mid){
                count++;
            }
            else{
                noOfBouquets += (count/k);
                count = 0;
            }
        }
        noOfBouquets += (count/k);
        return noOfBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {  
        int n = bloomDay.size();
        if(n<(1LL*m*k)) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }    
        long long low = mini;
        long long high = maxi;
        while(high>=low){
            long long mid = low + (high-low)/2;
            if(bouquets(bloomDay,m,k,mid)){
                high = mid-1;
            }
            else low = mid+1;

        }
        return low;
    }
};