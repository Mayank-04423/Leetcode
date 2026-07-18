class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>waiting;
        unordered_map<int,int>nextMax;

        for(int num :nums2){
            while(!waiting.empty() && num > waiting.top()){
                nextMax[waiting.top()] = num;
                waiting.pop();
            }
            waiting.push(num);
        }

        vector<int>ans;
        for(int num:nums1){
            if(nextMax.count(num)){
                ans.push_back(nextMax[num]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};