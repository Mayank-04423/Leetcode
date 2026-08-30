class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty())return 0;

        int count = 0; int maxCount = 0;
        for(int num : nums){
            if(num == 1){
                count++;
                maxCount = max(count, maxCount);
            }else{
                count = 0;
            }
        }
        return maxCount;
    }
};