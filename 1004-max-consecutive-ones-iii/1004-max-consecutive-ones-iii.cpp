class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0;
        int max_length = 0;
        int noz =0;

        for(int r=0; r< nums.size();r++){
            if(nums[r]==0){
                noz++;
            }
            while(noz>k){
                if(nums[l]==0){
                    noz--;
                }
                l++;
            }

            max_length = max(max_length , r-l+1);
        }
        return max_length;
    }
};