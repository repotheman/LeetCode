class Solution {
public:
    bool isPalindrome(string s) {
 
        string temp = "";
 
        for(auto x: s){
            if(isalnum(x)){
                temp += tolower(x);
            }
        }
 
        int n = temp.size();
        int i = 0, j = n - 1;
 
        while(i < j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
 
        return true;
 
        
    }
};