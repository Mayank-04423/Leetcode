class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       
        int n = nums.size();
        vector<int>ans(n);    

        int left = 0;
        int right = n-1;

//filling result array from back to 0        
        for(int i=n-1;i>=0;i--){
            int v1 = nums[left]*nums[left];
            int v2 = nums[right]*nums[right];

            if(v1>v2){
                ans[i]=v1;
                left++;
            }else{
                ans[i] = v2;
                right--;
            }
        }
        return ans;
    }
};