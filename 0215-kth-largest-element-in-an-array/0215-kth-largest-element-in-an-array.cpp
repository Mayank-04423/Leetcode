class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int nums:nums){
            pq.push(nums);
        }
        //popping k-1 elements
        for(int i=0; i<k-1;i++){
            pq.pop();
        }
        return pq.top();

    }
};