class Solution {
public:
    string removeDuplicates(string s) {
        string res = ""; //using string as stack to save code and space
        for(char ch:s){
            if(!res.empty() && ch == res.back()){   //res.back<=>stack.top()
                res.pop_back();
            }else{
                res.push_back(ch);
            }
        }
        return res;
    }
};