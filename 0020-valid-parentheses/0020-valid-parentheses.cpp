class Solution {
public:
    bool isValid(string s) {
        stack<char>bracket;

        for(char ch : s){
            if(ch=='(' || ch=='{' || ch=='['){
                bracket.push(ch);
            }else{ //for closing brackets
                if(bracket.empty()) return false;

                char last = bracket.top();

                if( ch ==')' && last == '(' ||
                    ch =='}' && last == '{' ||
                    ch ==']' && last == '[' ){
                        bracket.pop();
                    }else{
                        return false;
                    }


            }
        }
        return bracket.empty();
    }
};