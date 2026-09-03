class Solution {
public: 

    bool isPallindrome(string&s, int start, int end){
        while(start<end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }

    void solve(int idx, string&s,vector<string>&curr, vector<vector<string>>& result){
        if(idx == s.size()){
            result.push_back(curr);
            return;
        }

        for(int i=idx ; i<s.size();i++){
            if(isPallindrome(s,idx,i)){
                curr.push_back(s.substr(idx, i - idx + 1));
            
            solve(i+1,s,curr,result);
            curr.pop_back();
        }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>curr;
        solve(0,s,curr,result);
        return result;
             
    }
};