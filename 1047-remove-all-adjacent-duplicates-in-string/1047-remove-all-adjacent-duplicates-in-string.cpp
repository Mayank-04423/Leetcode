class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

    for(int i=0; i<s.length();i++){
        char ch=s[i];

        if((!st.empty()) && st.top() ==ch ){
            st.pop();
        }else{
            st.push(ch);
        }
    }

    string result = "";
    while(!st.empty()){
        result = st.top() + result;
        st.pop();
    }
     return result;
    }
   
};