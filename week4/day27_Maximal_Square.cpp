class Solution {
public:
    int findMaxSquare(vector<vector<char>>& matrix, int i, int j, int sz){
        if(i >= matrix.size()-1 || j >= matrix[i].size()-1 || matrix[i+1][j+1] == '0') return sz;
        for(int a=0; a<sz; a++){
            if(matrix[i+1][j-a] == '0' || matrix[i-a][j+1] == '0') return sz;
        }
        return findMaxSquare(matrix, i+1, j+1, sz+1);
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[i].size(); j++)
                if(matrix[i][j] == '1')
                    res = max(res, findMaxSquare(matrix, i, j, 1));
        return res*res;
    }
};
