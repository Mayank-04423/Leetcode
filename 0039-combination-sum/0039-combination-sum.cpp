class Solution {
public:
    void solve(int idx,vector<int>& candidates,int target,vector<int>&curr,vector<vector<int>>& result){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(idx==candidates.size() || target<0)return;
        
        curr.push_back(candidates[idx]);
        solve(idx,candidates,target-candidates[idx],curr,result);
        curr.pop_back();

        solve(idx+1,candidates,target,curr,result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        vector<vector<int>>result;
        solve(0,candidates,target,curr,result);
        return result;
    }
};