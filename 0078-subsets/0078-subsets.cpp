class Solution {
public:
    void solve(int idx,vector<int>& nums ,vector<int>& curr ,vector<vector<int>>& result){
        if(idx== nums.size()){
            result.push_back(curr);
            return;
        }

        solve(idx+1,nums,curr,result);

        curr.push_back(nums[idx]);
        solve(idx+1, nums,curr,result);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>curr;
        solve(0,nums,curr,result);
        return result;
    }
};