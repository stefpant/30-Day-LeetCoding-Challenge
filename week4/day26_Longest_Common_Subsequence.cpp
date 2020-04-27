class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()==0 || text2.size()==0) return 0;
        int s1 = text1.size()+1;
        int s2 = text2.size()+1;
        int lcs[s1][s2];
        for(int i=0; i<s1; i++) lcs[i][0] = 0;
        for(int j=0; j<s2; j++) lcs[0][j] = 0;
        for(int i=1; i<s1; i++){
            for(int j=1; j<s2; j++){
                if(text1[i-1] == text2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
                else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
        return lcs[s1-1][s2-1];
    }
};
