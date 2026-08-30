class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        int st = intervals[0][0];
        int end = intervals[0][1];
        for(int i =1 ;i<n;i++){
            if(end>=intervals[i][0]){
                end = max(end,intervals[i][1]);
            }
            else if(end<=intervals[i][0]){
                ans.push_back({st,end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({st,end});
        return ans;
        
    }
};