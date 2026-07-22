class Solution {
public:
    string decodeString(string s) {
        stack<string>strStack; 
        stack<int>numStack;

        string curr = "";
        int num = 0;

        for(char c:s){

            if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            else if(isalpha(c)){
                curr += c;
            }
            else if(c == '['){  //going one level deeper
                numStack.push(num);
                strStack.push(curr);

                //resetting working variable inside bracket
                num = 0;
                curr = "";
            }
            else if(c == ']'){
                int k = numStack.top();
                numStack.pop();

                string prev = strStack.top();
                strStack.pop();

                //repeating currstr k times and appending to prev 
                string repeated = "";
                for(int i=0; i<k;i++){
                    repeated += curr;
                }
                curr = prev + repeated;
            }
            else{
                curr += c;
            }
        }

        return curr;
    }
};