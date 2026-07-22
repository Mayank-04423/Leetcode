class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>sol;
        
        for(string& s: tokens){
            
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int b = sol.top();sol.pop();
                int a = sol.top(); sol.pop();
                if(s=="+") sol.push(a+b);
                else if(s =="-") sol.push(a-b);
                else if(s =="*")sol.push(a*b);
                else if(s =="/")sol.push(a/b);

            }else{
                //its a number -> push
                sol.push(stoi(s));
            }
        }
        return sol.top();
    }
};