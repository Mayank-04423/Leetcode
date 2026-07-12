class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>window;

        for(int i=0; i< nums.size();i++){
        //if already exists -> true
        if(window.find(nums[i])!= window.end()){
            return true;
        }
        //instering if does no exist 
        window.insert(nums[i]);
       
        //drop last
        if(window.size()>k){
            window.erase(nums[i-k]);
        }
      }
      return false;

    }
};