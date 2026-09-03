class Solution {
public:
    long long totalhrsReq(vector<int>& piles,int hourly,int n){
        long long totalhrs = 0;
        for(int i = 0;i<n;i++){
            totalhrs += ceil((double)piles[i]/hourly);
        }
        return totalhrs;
    }
    int maxpile(vector<int>& piles,int n){
        int maxi = piles[0];
        for(int i = 1;i<n;i++){
            if(piles[i]>maxi) maxi = piles[i];
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = maxpile(piles,n);
        while(low<=high){
            int mid = low+(high-low)/2;
            long long totalhrs = totalhrsReq(piles,mid,n);
            if(totalhrs<=h) high = mid-1;
            else low = mid+1;
        }

        return low;
    }
};