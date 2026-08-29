class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)return 0;

        int water = 0;
        int left = 0;
        int right = n-1;
        int leftMax = height[left];
        int rightMax = height[right];

        while(left<right){
            if(leftMax<rightMax){
                left++;
                water += max(0,leftMax - height[left]);
                leftMax = max(leftMax,height[left]);
            }else{
                right--;
                water+= max(0, rightMax - height[right]);
                rightMax = max(rightMax , height[right]);
            }
        }
        return water;
    }
};