class Solution {
public:
    int mySqrt(int x) {
        int left =0;
        int right = x;

        while(left <=right){
            long long mid =(left+right)/2;
            long long sq = mid*mid;

            if(sq == x){
                return mid;
            }else if(sq < x){
                left = mid +1;
            }else{
                right = mid-1;
            }
        }return right;
    }
};