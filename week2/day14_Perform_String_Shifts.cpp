class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int a,b;
        int len = s.length();
        if(len < 2) return s;
        for(int i=0; i<shift.size(); i++){
            a = shift[i][0];
            b = shift[i][1]%len;//no need to have shift amount greater than string length
            if(!b) continue;//if amount == 0 skip it
            if(!a) s = s.substr(b,len-b) + s.substr(0,b);//shift left
            else s = s.substr(len-b,b) + s.substr(0,len-b);//shift right
        }
        return s;
    }
};
