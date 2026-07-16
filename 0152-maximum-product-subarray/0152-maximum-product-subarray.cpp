class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0];
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];

        for(int i =1; i<nums.size();i++){
            best = nums[i];
            int v1 = nums[i]*maxEnd;
            int v2 = nums[i]*minEnd;
            maxEnd = max(best,max(v1,v2));
            minEnd = min(best,min(v1,v2));
            ans = max(ans,maxEnd);
        }
        return ans;
    }
};