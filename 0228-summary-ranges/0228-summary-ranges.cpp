class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;

        for(int start=0; start<nums.size(); start++){
            int i = start;  //setting explorer point

            while(i+1 < nums.size() && nums[i]+1 ==nums[i+1] ){
                i++;        
            }    

            if(start == i){
                ans.push_back(to_string(nums[start]));
            }else {
                ans.push_back(to_string(nums[start])+"->"+ to_string(nums[i]));
            }    

            start =i;
        }
        return ans;

    }
};