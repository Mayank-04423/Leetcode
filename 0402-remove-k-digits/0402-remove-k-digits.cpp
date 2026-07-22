class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string res ="";

        for(char c: num){

            while(!res.empty() && k>0 && res.back()>c){
                res.pop_back();
                k--;
            }
            res.push_back(c);

        }    

            //for sorted stack
            while(!res.empty() && k>0){
                res.pop_back();
                k--;
            }

            //for leading 0's
            int start = 0;
            while(start<res.size() && res[start] == '0'){
                start++;
            }
            res = res.substr(start);    

            if(res.empty())return "0";

            
        return res;   

    }
};