class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int maxSum = nums[0];
       int bestMax = nums[0];
       int totalSum = 0;
       for(int i:nums)totalSum+= i;
       
       //maxSum 
       for(int i=1; i<nums.size() ;i++){
        bestMax = max(nums[i],bestMax +nums[i]);
        maxSum = max(maxSum , bestMax);
       }
       //minSum
       int minSum = nums[0];
       int bestMin = nums[0];
       for(int i=1; i<nums.size(); i++){
        bestMin = min(nums[i], bestMin + nums[i]);
        minSum = min(minSum , bestMin);
       }

        if(maxSum<0)return maxSum;

       
       
       return max(maxSum , totalSum - minSum);
    }
    
};