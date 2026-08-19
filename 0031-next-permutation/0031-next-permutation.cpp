class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int j = n-2; 

        while(j>=0 && nums[j] >= nums[j+1]){
            j--;
        }       

        if(j>=0){
            int i = n-1;
            while(nums[i]<=nums[j]){
                i--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+j+1,nums.end());
    }
};