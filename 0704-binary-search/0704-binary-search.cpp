class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; 

            if (nums[mid] == target) {
                return mid; // Found it!
            } else if (nums[mid] < target) {
                left = mid + 1; // right half
            } else {
                right = mid - 1; // left half
            }
        }

        return -1; 
    }
};