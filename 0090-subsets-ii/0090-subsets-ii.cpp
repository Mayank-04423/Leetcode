class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result = {{}};

        int start = 0;
        for(int i=0; i<nums.size(); i++){
            int n = result.size();
            int begin = (i>0 && nums[i]==nums[i-1]) ? start : 0;

            for(int j=begin; j <n ;j++){
                vector<int>sub = result[j];
                sub.push_back(nums[i]);
                result.push_back(sub);
            }   
            start = n;
        }   

        return result;
    }
};