class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hello;

        for(int i=0; i<nums.size(); i++){
            int req = target - nums[i];

            if(hello.find(req)!=hello.end()){
                return {hello[req],i};
            }

            hello[nums[i]] = i;
        }

        return{};
    }
};