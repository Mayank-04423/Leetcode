class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        int fact = 1;

        for(int i=1; i<=n ;i++){
            nums.push_back(i);
            fact*=i;
        }

        k--;
        string result ="";

        for(int i=n ; i>0 ;i--){
            fact/=i;
            int idx = k/fact;
            result+= to_string(nums[idx]);
            nums.erase(nums.begin()+idx);
            k %= fact;
        }

        return result;
    }
};