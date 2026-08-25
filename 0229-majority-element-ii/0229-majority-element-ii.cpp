class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>result;
        unordered_map<int, int>freq;
        int n = nums.size();

        for(auto num:nums){
            freq[num]++;
        }

        for(auto& pair:freq){
            if(pair.second > n/3){
                result.push_back(pair.first);
            }
        }
        return result;
    }
};