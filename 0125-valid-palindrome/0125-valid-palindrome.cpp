//isalnum(c): Returns true if a character is a letter or a digit.
//tolower(c): Converts an uppercase letter to lowercase (and leaves numbers/punctuation alone).

class Solution {
public:
    bool isPalindrome(string s) {
       int i =0;
       int j =s.length()-1;

       while(i<j){
        if(!isalnum(s[i])){
            i++;
        }else if(!isalnum(s[j])){
            j--;
        }
        else{
            if(tolower(s[i])!=tolower(s[j])){
                return false; //mismatch 
            }
            i++;
            j--;

        }
       } 
       return true;
    }
};