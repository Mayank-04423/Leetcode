class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
      
        int maxSum = nums[0];
        int minSum = nums[0];
        int ans = abs(nums[0]);

        for(int i=1; i< nums.size(); i++){
            maxSum = max(maxSum + nums[i],nums[i]);
            minSum = min(nums[i], minSum + nums[i]);
           
            ans = max({ans, maxSum , abs(minSum)});
        }  
        return ans;  
    }
};