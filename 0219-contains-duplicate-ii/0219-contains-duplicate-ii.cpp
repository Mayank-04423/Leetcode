class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>data;

        for(int i=0; i<nums.size();i++){
            int num = nums[i];

            if(data.count(num)==1){

                if(i - data[num] <= k){
                    return true;
                }
            }
            data[num] =i ;
        }
        return false; 
    }
};