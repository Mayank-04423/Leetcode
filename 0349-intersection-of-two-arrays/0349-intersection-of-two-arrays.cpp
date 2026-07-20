class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end()) ;

        vector<int>res;

        for(int num:nums2){
            if(set1.find(num)!= set1.end()) {
                res.push_back(num);
                set1.erase(num);
            }             
        }

        return res;
    }
};