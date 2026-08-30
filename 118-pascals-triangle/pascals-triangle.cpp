class Solution {
public:
    vector<int> getRow(int row){
        vector<int> rowElements;
        int ans = 1;
        rowElements.push_back(1);
        for(int i = 1;i<row;i++){
            ans = ans * (row-i);
            ans = ans/i;
            rowElements.push_back(ans);
        }
        return rowElements;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1;i<=numRows;i++){
            ans.push_back(getRow(i));
        }
        return ans;
    }
};