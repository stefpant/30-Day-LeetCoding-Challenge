class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int counter=0;
        while(m != n){
            n>>=1;
            m>>=1;
            counter++;
        }
        return m<<counter;
    }
};
