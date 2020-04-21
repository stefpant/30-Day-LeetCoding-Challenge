class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(char& c : s){
            if(c == '(') low++; else low--;
            if(c != ')') high++; else high--;
            if(high < 0) return false;
            if(low < 0) low=0;
        }
        return (low == 0);
    }
};
