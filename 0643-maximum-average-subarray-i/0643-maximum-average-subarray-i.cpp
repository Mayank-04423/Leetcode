class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr_sum = 0;
        //setting the base window 
        for(int i=0; i< k; i++){
            curr_sum += nums[i];
        }

        int max_sum = curr_sum;
        //sliding the window 
        for(int i =k;i< nums.size();i++){
            curr_sum += nums[i] - nums[i-k];

            if(curr_sum> max_sum){
                max_sum = curr_sum;
            }
        }
        return (double)max_sum/k;
    }
};